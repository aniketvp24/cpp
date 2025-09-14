#include <iostream>
#include <list>
using namespace std;

template <typename T>
class Stack
{
private:
    list<T> llist;

public:
    Stack()
    {
    }

    Stack(T element)
    {
        push(element);
    }

    bool isEmpty()
    {
        return llist.empty();
    }

    int size()
    {
        return llist.size();
    }

    void push(T element)
    {
        llist.push_back(element);
    }

    void pop()
    {
        if (isEmpty())
        {
            cout << "Stack is empty!" << endl;
        }
        else
        {
            llist.pop_back();
        }
    }

    void peek()
    {
        if (isEmpty())
        {
            cout << "Stack is empty!" << endl;
        }
        else
        {
            cout << llist.back() << endl;
        }
    }

    void displayElements()
    {
        for (typename list<T>::const_iterator it = llist.begin(); it != llist.end(); it++)
        {
            cout << *it << endl;
        }
    }
};

int main()
{
    Stack<int> s;
    cout << "Is empty?: " << s.isEmpty() << endl;
    s.push(100);
    s.push(1000);
    s.pop();
    s.peek();
    s.displayElements();
    cout << "Is empty?: " << s.isEmpty() << endl;
    cout << "Size: " << s.size() << endl;
    return 0;
}