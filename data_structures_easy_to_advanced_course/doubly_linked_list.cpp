#include <iostream>
using namespace std;

template <typename T>
class DoublyLinkedList
{
private:
    struct Node
    {
        T data;
        Node *prev, *next;

        Node(T data, Node *prev, Node *next) : data(data), prev(prev), next(next) {};
    };
    int size = 0;
    Node *head = nullptr;
    Node *tail = nullptr;

public:
    void clear()
    {
        Node *trav = head;
        while (trav != nullptr)
        {
            Node *next = trav->next;
            trav->next = trav->prev = nullptr;
            delete trav;
            trav = next;
        }
        head = tail = trav = nullptr;
        size = 0;
    }

    int getSize()
    {
        return size;
    }

    bool isEmpty()
    {
        return size == 0;
    }

    void addFirst(T element)
    {
        if (head == nullptr)
        {
            head = tail = new Node(element, nullptr, nullptr);
        }
        else
        {
            Node *newNode = new Node(element, nullptr, head);
            head->prev = newNode;
            head = head->prev;
        }
        size++;
    }

    void addLast(T element)
    {
        if (tail == nullptr)
        {
            head = tail = new Node(element, nullptr, nullptr);
        }
        else
        {
            Node *newNode = new Node(element, tail, nullptr);
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }

    void traverse()
    {
        Node *trav = head;
        while (trav != nullptr)
        {
            cout << trav->data << " <-> ";
            trav = trav->next;
        }
        cout << "null" << endl;
    }

    void traverseReverse()
    {
        Node *trav = tail;
        while (trav != nullptr)
        {
            cout << trav->data << " <-> ";
            trav = trav->prev;
        }
        cout << "null" << endl;
    }

    void add(T element)
    {
        addLast(element);
    }

    void peekFirst()
    {
        if (isEmpty())
        {
            cout << "Doubly linked list is empty!" << endl;
        }
        else
        {
            cout << "Peek first: " << head->data << endl;
        }
    }

    void peekLast()
    {
        if (isEmpty())
        {
            cout << "Doubly linked list is empty!" << endl;
        }
        else
        {
            cout << "Peek last: " << tail->data << endl;
        }
    }

    void removeFirst()
    {
        if (head == nullptr)
        {
            cout << "Doubly linked list is empty!" << endl;
        }
        else
        {
            Node *oldHead = head;
            head = head->next;
            size--;

            if (isEmpty())
            {
                tail = nullptr;
            }
            else
            {
                head->prev = nullptr;
            }
            cout << "Removed: " << oldHead->data << endl;
            delete oldHead;
        }
    }

    void removeLast()
    {
        if (tail == nullptr)
        {
            cout << "Doubly linked list is empty!" << endl;
        }
        else
        {
            Node *oldTail = tail;
            tail = tail->prev;
            size--;

            if (isEmpty())
            {
                head = nullptr;
            }
            else
            {
                tail->next = nullptr;
            }
            cout << "Removed: " << oldTail->data << endl;
            delete oldTail;
        }
    }

    void remove(Node *node)
    {
        if (node == nullptr)
        {
            cout << "Please pass correct address, current is pointing to null!" << endl;
            return;
        }

        else if (node == tail)
        {
            removeLast();
        }
        else if (node == head)
        {
            removeFirst();
        }
        else
        {
            node->next->prev = node->prev;
            node->prev->next = node->next;
            size--;

            cout << "Removed: " << node->data << endl;
            node->data = T{};
            node->next = node->prev = nullptr;

            delete node;
        }
    }

    int indexOf(T data)
    {
        int index = 0;
        Node *trav = head;

        while (trav != nullptr)
        {
            if (trav->data == data)
            {
                return index;
            }
            else
            {
                trav = trav->next;
                index++;
            }
        }
        return -1;
    }

    bool contains(T data)
    {
        return indexOf(data) != -1;
    }

    Node *addressOf(T data)
    {
        Node *trav = head;

        while (trav != nullptr)
        {
            if (trav->data == data)
            {
                return trav;
            }
            else
            {
                trav = trav->next;
            }
        }
        return nullptr;
    }
};

int main()
{
    DoublyLinkedList<int> dll;
    dll.clear();
    dll.peekFirst();
    dll.peekLast();
    dll.addFirst(10);
    dll.removeFirst();
    cout << "Size: " << dll.getSize() << endl;

    dll.addFirst(20);
    dll.addFirst(100);
    dll.addFirst(1000);
    dll.addLast(41);

    dll.traverse();
    dll.traverseReverse();
    cout << "Size: " << dll.getSize() << endl;
    dll.removeLast();

    dll.peekFirst();
    dll.peekLast();

    cout << "Address of 1000: " << dll.addressOf(1000) << endl;

    dll.remove(dll.addressOf(1000));
    dll.traverse();

    cout << "Index of 100: " << dll.indexOf(100) << endl;
    cout << "Index of 700: " << dll.indexOf(700) << endl;

    cout << "Contains 100?: " << dll.contains(100) << endl;
    cout << "Contains 700?: " << dll.contains(700) << endl;

    cout << "Size: " << dll.getSize() << endl;
    return 0;
}
