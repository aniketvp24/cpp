#include <iostream>
using namespace std;

template <typename T>
class SinglyLinkedList
{
private:
    struct Node
    {
        T data;
        Node *next;

        Node(T data, Node *next) : data(data), next(next) {};
    };

    int size = 0;
    Node *head = nullptr;
    Node *tail = nullptr;

public:
    int getSize()
    {
        return size;
    }

    bool isEmpty()
    {
        return getSize() == 0;
    }

    void add(T element)
    {
        if (isEmpty())
        {
            head = tail = new Node(element, nullptr);
        }
        else
        {
            Node *newNode = new Node(element, nullptr);
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }

    void removeFirst()
    {
        if (isEmpty())
        {
            cout << "Singly linked list is empty!" << endl;
        }
        else
        {
            Node *oldHead = head;
            T data = head->data;
            head = head->next;

            if (head == nullptr)
                tail = nullptr;

            size--;
            cout << "Removed: " << data << endl;

            delete oldHead;
        }
    }

    void removeLast()
    {
        if (isEmpty())
        {
            cout << "Singly linked list is empty!" << endl;
        }
        else
        {
            T data = tail->data;
            if (head == tail)
            {
                delete head;
                head = tail = nullptr;
            }
            else
            {
                Node *trav = head;
                while (trav->next != tail)
                {
                    trav = trav->next;
                }

                Node *oldTail = trav->next;
                trav->next = nullptr;
                delete oldTail;
                tail = trav;
            }
            size--;
            cout << "Removed: " << data << endl;
        }
    }

    void traverse()
    {
        Node *trav = head;
        while (trav != nullptr)
        {
            cout << trav->data << " -> ";
            trav = trav->next;
        }
        cout << "null" << endl;
    }

    T peekFirst()
    {
        if (isEmpty())
        {
            cout << "Singly Linked List is empty!" << endl;
            return T{};
        }
        else
        {
            return head->data;
        }
    }

    T peekLast()
    {
        if (isEmpty())
        {
            cout << "Singly Linked List is empty!" << endl;
            return T{};
        }
        else
        {
            return tail->data;
        }
    }
};

template <typename T>
class Stack
{
private:
    SinglyLinkedList<T> sll;

public:
    int getSize()
    {
        return sll.getSize();
    }

    bool isEmpty()
    {
        return sll.isEmpty();
    }

    void push(T element)
    {
        sll.add(element);
    }

    void pop()
    {
        sll.removeLast();
    }

    void displayElements()
    {
        sll.traverse();
    }
};

int main()
{
    // SinglyLinkedList<int> sll;
    // cout << sll.isEmpty() << endl;

    // sll.add(10);
    // sll.add(20);
    // sll.add(30);
    // sll.add(40);
    // sll.removeLast();
    // sll.removeFirst();
    // sll.traverse();

    // cout << sll.getSize() << endl;

    Stack<int> s;
    cout << "Size: " << s.getSize() << endl;
    cout << "Is Empty?: " << s.isEmpty() << endl;

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.pop();
    s.pop();
    s.displayElements();

    return 0;
}