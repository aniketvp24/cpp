#include <iostream>
#include <list>
#include <set>
#include <vector>
#include <unordered_map>
using namespace std;

template <typename T>
class PriorityQueue
{
private:
    int heapSize = 0, heapCapacity = 0;
    vector<T> heap;
    unordered_map<T, set<int>> hmap;

    bool less(int i, int j)
    {
        return heap[i] <= heap[j];
    }

    void swap(int i, int j)
    {
        T i_elem = heap[i];
        T j_elem = heap[j];

        heap[j] = i_elem;
        heap[i] = j_elem;

        mapSwap(i_elem, j_elem, i, j);
    }

    void swim(int k)
    {
        int parent = (k - 1) / 2;

        while (k > 0 && less(k, parent))
        {
            swap(parent, k);
            k = parent;

            parent = (k - 1) / 2;
        }
    }

    void sink(int k)
    {
        while (true)
        {
            int left = 2 * k + 1;
            int right = 2 * k + 2;
            int smallest = left;

            if (right < heapSize && less(right, left))
                smallest = right;

            if (left >= heapSize || less(k, smallest))
                break;

            swap(k, smallest);
            k = smallest;
        }
    }

    void mapAdd(T element, int index)
    {
        set<int> &hset = hmap[element];
        hset.insert(index);
    }

    void mapRemove(T element, int index)
    {
        set<int> &hset = hmap[element];
        hset.erase(index);

        if (hset.size() == 0)
        {
            hmap.erase(element);
        }
    }

    void mapSwap(T i_elem, T j_elem, int i, int j)
    {
        set<int> &i_hset = hmap[i_elem];
        set<int> &j_hset = hmap[j_elem];

        i_hset.erase(i);
        j_hset.erase(j);

        i_hset.insert(j);
        j_hset.insert(i);
    }

    int mapGet(T element)
    {
        set<int> &hset = hmap[element];
        if (hset.size() > 0)
        {
            return *hset.rbegin();
        }
        return -1;
    }

public:
    PriorityQueue() : PriorityQueue(1) {};

    PriorityQueue(int size) : heap(size), heapCapacity(size) {};

    PriorityQueue(vector<T> elements)
    {
        heapSize = heapCapacity = elements.size();
        // heap.resize(heapCapacity);

        for (int i = 0; i < heapSize; i++)
        {
            // heap[i] = elements[i];
            heap.push_back(elements[i]);
            mapAdd(elements[i], i);
        }

        // Heapify
        for (int i = max(0, (heapSize / 2) - 1); i >= 0; i--)
        {
            sink(i);
        }
    }

    bool isEmpty()
    {
        return heapSize == 0;
    }

    void clear()
    {
        heap.clear();
        heapSize = 0;
        heapCapacity = 0;
        hmap.clear();
    }

    int size()
    {
        return heapSize;
    }

    T peek()
    {
        if (isEmpty())
            throw runtime_error("PQ is empty!");
        return heap[0];
    }

    bool contains(T element)
    {
        if (hmap.find(element) != hmap.end())
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void add(T element)
    {
        if (heapSize < heapCapacity)
        {
            heap[heapSize] = element;
        }
        else
        {
            heap.push_back(element);
            heapCapacity = heap.size();
        }

        mapAdd(element, heapSize);
        swim(heapSize);
        heapSize++;
    }

    T poll()
    {
        return removeAt(0);
    }

    bool remove(T element)
    {
        int index = mapGet(element);
        if (index != -1)
        {
            removeAt(index);
        }
        return index != -1;
    }

    T removeAt(int index)
    {
        if (isEmpty())
            throw runtime_error("PQ is empty!");

        heapSize--;
        T removedData = heap[index];
        swap(index, heapSize);

        heap[heapSize] = T{};
        mapRemove(removedData, heapSize);

        if (index == heapSize)
            return removedData;

        T element = heap[index];
        sink(index);

        if (heap[index] == element)
        {
            swim(index);
        }
        return removedData;
    }

    bool isMinHeap(int k)
    {
        if (k >= heapSize)
            return true;

        int left = 2 * k + 1;
        int right = 2 * k + 2;

        if (left < heapSize && !less(k, left))
            return false;

        if (right < heapSize && !less(k, right))
            return false;

        return isMinHeap(left) && isMinHeap(right);
    }

    void displayElements()
    {
        for (int i = 0; i < heapSize; i++)
            cout << heap[i] << " ";

        cout << endl;
    }

    // For debugging
    void getSizeAndCapacity()
    {
        cout << "Size: " << heap.size() << endl;
        cout << "Capacity: " << heapCapacity << endl;
    }
};

int main()
{
    vector<int> vec = {4, 5, 6, 1, 3, 11, 1, 19, 2};
    PriorityQueue<int> pq(vec);
    pq.getSizeAndCapacity();
    cout << pq.peek() << endl;
    cout << "Contains 2: " << pq.contains(2) << endl;
    cout << "Contains 4: " << pq.contains(4) << endl;

    cout << "Is Min Heap? " << pq.isMinHeap(0) << endl;

    pq.add(100);
    pq.add(10);
    cout << "Is Min Heap? " << pq.isMinHeap(0) << endl;

    pq.poll();
    pq.poll();
    pq.add(4);
    pq.displayElements();
    cout << "Is Min Heap? " << pq.isMinHeap(0) << endl;
    pq.poll();
    pq.displayElements();
    pq.poll();
    pq.displayElements();
    pq.poll();
    pq.displayElements();
    pq.poll();
    pq.displayElements();
    pq.poll();
    pq.displayElements();
    pq.poll();
    pq.displayElements();

    return 0;
}