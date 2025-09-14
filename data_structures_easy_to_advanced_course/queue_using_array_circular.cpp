#include <iostream>
using namespace std;

template <typename T>
class Queue
{
private:
    static const int capacity = 100;
    int front = 0, rear = 0, len = 0;
    T arr[capacity];

public:
    Queue()
    {
    }

    Queue(T element)
    {
        offer(element);
    }

    int size()
    {
        return len;
    }

    bool isEmpty()
    {
        return len == 0;
    }

    bool isFull()
    {
        return len == capacity;
    }

    void offer(T element)
    {
        if (isFull())
        {
            throw runtime_error("Queue is full!");
        }
        else
        {
            arr[rear] = element;
            rear = (rear + 1) % capacity;
            len++;
        }
    }

    T poll()
    {
        if (isEmpty())
        {
            throw runtime_error("Queue is Empty!");
        }
        else
        {
            T data = arr[front];
            front = (front + 1) % capacity;
            len--;
            return data;
        }
    }

    T peek()
    {
        if (isEmpty())
        {
            throw runtime_error("Queue is Empty!");
        }
        else
        {
            return arr[front];
        }
    }

    void displayElements()
    {
        cout << "Queue: ";
        for (int i = 0; i < len; i++)
        {
            int index = (front + i) % capacity;
            cout << arr[index] << " ";
        }
        cout << endl;
    }
};

int main()
{
    Queue<int> queue(0);
    queue.offer(10);
    queue.offer(20);
    queue.offer(30);

    queue.displayElements();

    cout << queue.poll() << endl;
    cout << queue.poll() << endl;

    cout << queue.peek() << endl;
    queue.displayElements();

    return 0;
}