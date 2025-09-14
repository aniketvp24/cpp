#include <iostream>
using namespace std;

template <typename T>
class Queue
{
private:
    T arr[100];
    int front, len = 0;

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
        return size() == 0;
    }

    void offer(T element)
    {
        arr[len++] = element;
    }

    T poll()
    {
        if (isEmpty())
        {
            throw runtime_error("Queue is Empty!");
        }
        else
        {
            T data = arr[0];
            for (int i = 0; i < len - 1; i++)
            {
                arr[i] = arr[i + 1];
            }
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
            return arr[0];
        }
    }

    void displayElements()
    {
        cout << "Queue: ";
        for (int i = 0; i < len; i++)
        {
            cout << arr[i] << " ";
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

    return 0;
}