#include <iostream>
#include <queue>
using namespace std;

template <typename T>
class BinarySearchTree
{
private:
    struct Node
    {
        T data;
        Node *left, *right;

        Node(T data, Node *left, Node *right) : data(data), left(left), right(right) {};
    };

    int nodeCount = 0;
    Node *root = nullptr;

    Node *add(Node *node, T element)
    {
        if (node == nullptr)
        {
            node = new Node(element, nullptr, nullptr);
        }
        else
        {
            if (element < node->data)
            {
                node->left = add(node->left, element);
            }
            else
            {
                node->right = add(node->right, element);
            }
        }

        return node;
    }

    Node *remove(Node *node, T element)
    {
        if (node == nullptr)
        {
            return nullptr;
        }

        // Find phase
        if (element < node->data)
        {
            node->left = remove(node->left, element);
        }
        else if (element > node->data)
        {
            node->right = remove(node->right, element);
        }
        else
        {
            if (node->left == nullptr)
            {
                Node *rightChild = node->right;

                node->data = T{};
                node = nullptr;

                return rightChild;
            }
            else if (node->right == nullptr)
            {
                Node *leftChild = node->left;
                node->data = T{};
                node = nullptr;

                return leftChild;
            }
            else
            {
                Node *successor = digLeft(node->right);
                node->data = successor->data;

                node->right = remove(node->right, successor->data);
            }
        }

        return node;
    }

    bool contains(Node *node, T element)
    {
        if (node == nullptr)
        {
            return false;
        }
        else
        {
            if (element < node->data)
            {
                return contains(node->left, element);
            }
            else if (element > node->data)
            {
                return contains(node->right, element);
            }
            else
            {
                return true;
            }
        }
    }

    Node *digLeft(Node *node)
    {
        Node *current = node;
        while (current->left != nullptr)
        {
            current = current->left;
        }
        return current;
    }

    Node *digRight(Node *node)
    {
        Node *current = node;
        while (current->right != nullptr)
        {
            current = current->right;
        }
        return current;
    }

    int height(Node *node)
    {
        if (node == nullptr)
        {
            return 0;
        }

        return max(height(node->left), height(node->right)) + 1;
    }

    void preOrderTraversal(Node *node)
    {
        if (node == nullptr)
        {
            return;
        }
        cout << node->data << " ";
        preOrderTraversal(node->left);
        preOrderTraversal(node->right);
    }

    void inOrderTraversal(Node *node)
    {
        if (node == nullptr)
        {
            return;
        }
        inOrderTraversal(node->left);
        cout << node->data << " ";
        inOrderTraversal(node->right);
    }

    void postOrderTraversal(Node *node)
    {
        if (node == nullptr)
        {
            return;
        }
        postOrderTraversal(node->left);
        postOrderTraversal(node->right);
        cout << node->data << " ";
    }

    void levelOrderTraversal(Node *node)
    {
        queue<Node *> lot;
        lot.push(node);

        while (!lot.empty())
        {
            Node *front = lot.front();
            lot.pop();

            if (front->left != nullptr)
                lot.push(front->left);

            if (front->right != nullptr)
                lot.push(front->right);

            cout << front->data << " ";
        }
    }

public:
    bool isEmpty()
    {
        return size() == 0;
    }

    int size()
    {
        return nodeCount;
    }

    bool add(T element)
    {
        if (contains(element))
        {
            return false;
        }
        else
        {
            root = add(root, element);
            nodeCount++;
            return true;
        }
    }

    bool contains(T element)
    {
        return contains(root, element);
    }

    bool remove(T element)
    {
        if (contains(element))
        {
            root = remove(root, element);
            nodeCount--;
            return true;
        }
        else
        {
            return false;
        }
    }

    int height()
    {
        return height(root);
    }

    void preOrderTraversal()
    {
        cout << "Pre-Order Traversal: " << " ";
        preOrderTraversal(root);
        cout << endl;
    }

    void inOrderTraversal()
    {
        cout << "In-Order Traversal: " << " ";
        inOrderTraversal(root);
        cout << endl;
    }

    void postOrderTraversal()
    {
        cout << "Post-Order Traversal: " << " ";
        postOrderTraversal(root);
        cout << endl;
    }

    void levelOrderTraversal()
    {
        cout << "Level-Order Traversal: " << " ";
        levelOrderTraversal(root);
        cout << endl;
    }
};

int main()
{
    BinarySearchTree<int> bst;
    cout << "Initial size: " << bst.size() << endl;
    cout << "add(10): " << bst.add(10) << endl;
    cout << "add(20): " << bst.add(20) << endl;
    cout << "add(30): " << bst.add(30) << endl;
    cout << "add(20) again: " << bst.add(20) << endl;
    cout << "Size after inserts: " << bst.size() << endl;
    cout << "contains(30): " << bst.contains(30) << endl;
    cout << "contains(50): " << bst.contains(50) << endl;
    cout << "remove(20): " << bst.remove(20) << endl;
    cout << "remove(20) again: " << bst.remove(20) << endl;
    cout << "Size after removals: " << bst.size() << endl;
    cout << "Height of tree: " << bst.height() << endl;
    bst.preOrderTraversal();
    bst.inOrderTraversal();
    bst.postOrderTraversal();

    bst.add(5);
    bst.add(15);
    bst.add(25);
    bst.add(35);
    cout << "Before removing 30:" << endl;
    bst.inOrderTraversal();
    cout << "remove(30): " << bst.remove(30) << endl;
    cout << "After removing 30:" << endl;
    cout << "Final size: " << bst.size() << endl;
    cout << "Height of tree: " << bst.height() << endl;
    bst.preOrderTraversal();
    bst.inOrderTraversal();
    bst.postOrderTraversal();
    bst.levelOrderTraversal();
    return 0;
}
