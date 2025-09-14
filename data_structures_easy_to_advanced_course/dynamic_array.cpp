#include <iostream>
using namespace std;

// Array constructors, size, len, isEmpty, get, set, clear, add, removeAt, insertAt, remove, indexOf
template <typename T>
class DynamicArray
{
private:
    T *arr;
    int len = 0;
    int capacity = 0;

public:
    DynamicArray()
    {
        this->capacity = 4;
        arr = new T[4];
    }

    DynamicArray(int capacity)
    {
        this->capacity = capacity;
        arr = new T[this->capacity];
    }

    int size()
    {
        return this->len;
    }

    void actualSize()
    {
        cout << "Actual Size: " << this->capacity << endl;
    }

    bool isEmpty()
    {
        return (this->len == 0);
    }

    T get(int index)
    {
        if (index < 0 || index >= len)
        {
            throw out_of_range("Index out of range!");
        }

        return arr[index];
    }

    void set(int index, T element)
    {
        if (index < 0 || index >= len)
        {
            throw out_of_range("Index out of range!");
        }

        arr[index] = element;
    }

    void clear()
    {
        for (int i = 0; i < len; i++)
        {
            arr[i] = T{};
        }
        len = 0;
    }

    void add(T element)
    {
        if (len + 1 > capacity)
        {
            if (capacity == 0)
            {
                capacity = 1;
            }
            else
            {
                capacity *= 2;
            }

            T *new_arr = new T[capacity];
            for (int i = 0; i < len; i++)
            {
                new_arr[i] = arr[i];
            }
            delete[] arr;
            arr = new_arr;
        }

        arr[len++] = element;
    }

    T removeAt(int index)
    {
        if (index >= len)
        {
            throw out_of_range("Index out of range!");
        }

        T data = arr[index];
        for (int i = index; i < len - 1; i++)
        {
            arr[i] = arr[i + 1];
        }
        len--;
        arr[len] = T{};

        return data;
    }

    void insertAt(int index, T element)
    {

        if (index < 0 || index > len)
        {
            throw out_of_range("Index out of range!");
        }

        if (len + 1 > capacity)
        {
            if (capacity == 0)
            {
                capacity = 1;
            }
            else
            {
                capacity *= 2;
            }
            T *new_arr = new T[capacity];

            for (int i = 0; i < index; i++)
            {
                new_arr[i] = arr[i];
            }

            new_arr[index] = element;

            for (int i = index; i < len; i++)
            {
                new_arr[i + 1] = arr[i];
            }

            delete[] arr;
            arr = new_arr;
        }
        else
        {
            for (int i = len; i > index; i--)
            {
                arr[i] = arr[i - 1];
            }
            arr[index] = element;
        }
        len++;
    }

    int indexOf(T element)
    {
        for (int i = 0; i < len; i++)
        {
            if (arr[i] == element)
            {
                return i;
            }
        }
        return -1;
    }

    bool remove(T element)
    {
        int index = indexOf(element);

        if (index != -1)
        {
            T data = removeAt(index);
            return true;
        }
        return false;
    }
};

// Test cases generated using ChatGPT
void testAddAndGet()
{
    DynamicArray<int> da;
    da.add(10);
    da.add(20);
    da.add(30);
    cout << (da.get(0) == 10 ? "PASS" : "FAIL") << " - Add/Get Test 1\n";
    cout << (da.get(2) == 30 ? "PASS" : "FAIL") << " - Add/Get Test 2\n";
}

void testSet()
{
    DynamicArray<int> da;
    da.add(100);
    da.set(0, 999);
    cout << (da.get(0) == 999 ? "PASS" : "FAIL") << " - Set Test\n";
}

void testInsertAt()
{
    DynamicArray<int> da;
    da.add(1);
    da.add(2);
    da.add(3);
    da.insertAt(1, 99); // 1, 99, 2, 3
    cout << (da.get(1) == 99 && da.get(2) == 2 ? "PASS" : "FAIL") << " - InsertAt Test\n";
}

void testRemoveAt()
{
    DynamicArray<int> da;
    da.add(5);
    da.add(6);
    da.add(7);
    int removed = da.removeAt(1); // should remove 6
    cout << ((removed == 6 && da.get(1) == 7 && da.size() == 2) ? "PASS" : "FAIL") << " - RemoveAt Test\n";
}

void testRemoveElement()
{
    DynamicArray<int> da;
    da.add(10);
    da.add(20);
    da.add(30);
    bool result = da.remove(20);
    cout << (result && da.indexOf(20) == -1 && da.size() == 2 ? "PASS" : "FAIL") << " - Remove(Element) Test\n";
}

void testIndexOf()
{
    DynamicArray<int> da;
    da.add(111);
    da.add(222);
    da.add(333);
    cout << (da.indexOf(222) == 1 ? "PASS" : "FAIL") << " - IndexOf Test\n";
}

void testClearAndIsEmpty()
{
    DynamicArray<int> da;
    da.add(5);
    da.add(10);
    da.clear();
    cout << (da.isEmpty() && da.size() == 0 ? "PASS" : "FAIL") << " - Clear/IsEmpty Test\n";
}

void testResizeGrowth()
{
    DynamicArray<int> da;
    for (int i = 0; i < 100; i++)
        da.add(i);
    cout << (da.size() == 100 && da.get(99) == 99 ? "PASS" : "FAIL") << " - Resize/Growth Test\n";
}

int main()
{
    testAddAndGet();
    testSet();
    testInsertAt();
    testRemoveAt();
    testRemoveElement();
    testIndexOf();
    testClearAndIsEmpty();
    testResizeGrowth();

    DynamicArray<int> da;
    // cout << da.isEmpty() << endl;
    da.actualSize();

    da.add(100);
    da.add(200);
    da.add(300);
    da.add(400);
    da.add(500);
    da.add(7800);
    da.add(1000);
    // da.removeAt(5);

    cout << "Size: " << da.size() << endl;

    da.insertAt(7, 10000);
    for (int i = 0; i < da.size(); i++)
    {
        cout << da.get(i) << endl;
    }

    cout << "Size: " << da.size() << endl;
    da.remove(1000);

    da.actualSize();

    for (int i = 0; i < da.size(); i++)
    {
        cout << da.get(i) << endl;
    }

    cout << "Size: " << da.size() << endl;

    // cout << da.get(4) << endl;
    return 0;
}