#include <iostream>
#include <list>
#include <cmath>
#include <optional>
using namespace std;

template <typename K, typename V>
class Entry
{
private:
    K key;
    V value;
    int _hash;

public:
    Entry(K key, V value) : key(key), value(value)
    {
        _hash = hash<K>{}(key);
    }

    bool equals(const Entry<K, V> &other)
    {
        if (_hash != other._hash)
        {
            return false;
        }
        return key == other.key;
    }

    void toString()
    {
        cout << key << " => " << _hash << endl;
    }

    K getKey()
    {
        return key;
    }

    V getValue()
    {
        return value;
    }

    int getHash()
    {
        return _hash;
    }

    void setValue(V value)
    {
        this->value = value;
    }
};

template <typename K, typename V>
class HashTableSeparateChaining
{
private:
    static constexpr int DEFAULT_CAPACITY = 3;
    static constexpr double DEFAULT_LOAD_FACTOR = 0.75;

    double maxLoadFactor = 0.75;
    int capacity = 0, threshold = 0, size = 0;
    list<Entry<K, V>> *table;

    int normalizeIndex(int keyHash)
    {
        return (keyHash & 0x7FFFFFFF) % capacity;
    }

    Entry<K, V> *bucketSeekEntry(int bucketIndex, const K &key) const
    {
        list<Entry<K, V>> &bucket = table[bucketIndex];

        for (Entry<K, V> &entry : bucket)
        {
            if (entry.getKey() == key)
            {
                return &entry;
            }
        }
        return nullptr;
    }

    void bucketInsertEntry(int bucketIndex, Entry<K, V> &entry)
    {
        list<Entry<K, V>> &bucket = table[bucketIndex];
        Entry<K, V> *existentEntry = bucketSeekEntry(bucketIndex, entry.getKey());

        if (existentEntry)
        {
            // V *oldValue = &(existentEntry->getValue());
            existentEntry->setValue(entry.getValue());
        }
        else
        {
            bucket.push_back(entry);
            size++;
            if (size > threshold)
            {
                resizeTable();
            }
        }
    }

    V bucketRemoveEntry(int bucketIndex, const K &key)
    {
        Entry<K, V> *entry = bucketSeekEntry(bucketIndex, key);
        if (entry == nullptr)
        {
            throw invalid_argument("Key not found in map!");
        }
        else
        {
            list<Entry<K, V>> &bucket = table[bucketIndex];
            bucket.remove_if([&](const Entry<K, V> &e)
                             { return &e == entry; });

            size--;
            return entry->getValue();
        }
    }

    void resizeTable()
    {
        int oldCapacity = capacity;
        capacity *= 2;
        threshold = (int)(this->capacity * this->maxLoadFactor);
        list<Entry<K, V>> *newTable = new list<Entry<K, V>>[capacity];

        for (int i = 0; i < oldCapacity; i++)
        {
            list<Entry<K, V>> &bucket = table[i];
            for (auto &entry : bucket)
            {
                int bucketIndex = normalizeIndex(entry.getHash());
                list<Entry<K, V>> &newBucket = newTable[bucketIndex];
                newBucket.push_back(entry);
            }
        }

        delete[] table;
        table = newTable;
    }

public:
    HashTableSeparateChaining() : HashTableSeparateChaining(DEFAULT_CAPACITY, DEFAULT_LOAD_FACTOR) {};

    HashTableSeparateChaining(int capacity) : HashTableSeparateChaining(capacity, DEFAULT_LOAD_FACTOR) {};

    HashTableSeparateChaining(int capacity, double maxLoadFactor)
    {
        if (capacity < 0)
            throw invalid_argument("Invalid capacity!");

        if (maxLoadFactor <= 0 || isinf(maxLoadFactor) || isnan(maxLoadFactor))
            throw invalid_argument("Invalid maxLoadFactor!");

        this->maxLoadFactor = maxLoadFactor;
        this->capacity = max(DEFAULT_CAPACITY, capacity);
        threshold = (int)(this->capacity * this->maxLoadFactor);
        table = new list<Entry<K, V>>[this->capacity];
    }

    int getSize() const
    {
        return size;
    }

    bool isEmpty() const
    {
        return size == 0;
    }

    void clear()
    {
        delete[] table;
        table = new list<Entry<K, V>>[capacity];
        size = 0;
    }

    void insert(K key, V value)
    {
        Entry<K, V> newEntry(key, value);
        int bucketIndex = normalizeIndex(newEntry.getHash());
        bucketInsertEntry(bucketIndex, newEntry);
        // cout << "DEBUG: " << bucketIndex << endl;
    }

    V get(K key)
    {
        int bucketIndex = normalizeIndex(hash<K>{}(key));
        Entry<K, V> *entry = bucketSeekEntry(bucketIndex, key);

        if (entry == nullptr)
        {
            throw invalid_argument("Key not found in map!");
        }
        else
        {
            return entry->getValue();
        }
    }

    V remove(K key)
    {
        int bucketIndex = normalizeIndex(hash<K>{}(key));
        return bucketRemoveEntry(bucketIndex, key);
    }

    void displayConfig() const
    {
        cout << "Capacity: " << capacity << endl;
        cout << "Size: " << size << endl;
        cout << "Threshold: " << threshold << endl;
    }

    void displayBuckets() const
    {
        cout << "Buckets: " << endl;
        for (int i = 0; i < capacity; i++)
        {
            list<Entry<K, V>> &bucket = table[i];
            cout << i << ": ";
            for (auto &entry : bucket)
            {
                cout << "(" << entry.getKey() << ", " << entry.getValue() << "), ";
            }
            cout << endl;
        }
    }

    void displayBucketSizes() const
    {
        cout << "Bucket Sizes: " << endl;
        for (int i = 0; i < capacity; i++)
        {
            list<Entry<K, V>> &bucket = table[i];
            cout << i << " " << bucket.size() << endl;
        }
    }

    ~HashTableSeparateChaining()
    {
        delete[] table;
    }
};

int main()
{
    HashTableSeparateChaining<char, int> ht;
    cout << "------------------------------------" << endl;
    ht.insert('A', 1);
    ht.insert('B', 8);
    ht.insert('Z', 3);
    ht.insert('Q', 5);
    ht.insert('L', 9);
    ht.insert('G', 98);

    cout << ht.get('L') << endl;
    cout << ht.remove('Q') << endl;

    ht.displayBuckets();
    cout << "Is empty: " << ht.isEmpty() << endl;
    return 0;
}