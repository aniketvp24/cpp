#include <iostream>
#include <list>
using namespace std;

template <typename T>
class Queue
{
private:
    list<T> dll;

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
        return dll.size();
    }

    bool isEmpty()
    {
        return dll.empty();
    }

    void offer(T element)
    {
        dll.push_back(element);
    }

    T poll()
    {
        if (isEmpty())
        {
            throw runtime_error("Queue is empty!");
        }
        else
        {
            T data = peek();
            dll.pop_front();
            return data;
        }
    }

    T peek()
    {
        if (isEmpty())
        {
            throw runtime_error("Queue is empty!");
        }
        else
        {
            return dll.front();
        }
    }

    void displayElements()
    {
        cout << "Queue: ";
        for (typename list<T>::iterator it = dll.begin(); it != dll.end(); it++)
        {
            cout << *it << " ";
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