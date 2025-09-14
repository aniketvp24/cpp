#include <iostream>
using namespace std;

class UnionFind
{
private:
    int size, numComponents;
    int *sz, *id;

public:
    UnionFind(int size)
    {
        if (size <= 0)
        {
            throw invalid_argument("Size cannot be 0 or less!");
        }

        this->size = numComponents = size;
        sz = new int[size];
        id = new int[size];

        for (int i = 0; i < size; i++)
        {
            sz[i] = 1;
            id[i] = i;
        }
    }

    int find(int p)
    {
        if (p < 0 || p >= size)
        {
            throw out_of_range("Index out of bounds");
        }

        int root = p;
        while (root != id[root])
        {
            root = id[root];
        }

        while (p != root)
        {
            int next = id[p];
            id[p] = root;
            p = next;
        }

        return root;
    }

    int findRecursive(int p)
    {
        if (p < 0 || p >= size)
        {
            throw out_of_range("Index out of bounds");
        }

        if (p == id[p])
        {
            return p;
        }
        else
        {
            id[p] = findRecursive(id[p]);
            return id[p];
        }
    }

    bool connected(int p, int q)
    {
        return find(p) == find(q);
    }

    int componentSize(int p)
    {
        return sz[find(p)];
    }

    int getSize()
    {
        return size;
    }

    int getComponents()
    {
        return numComponents;
    }

    void unify(int p, int q)
    {
        int root_p = find(p);
        int root_q = find(q);

        if (root_p == root_q)
            return;

        if (sz[root_p] < sz[root_q])
        {
            sz[root_q] += sz[root_p];
            id[root_p] = root_q;
        }
        else
        {
            sz[root_p] += sz[root_q];
            id[root_q] = root_p;
        }

        numComponents--;
    }

    void displayRoots()
    {
        cout << "Roots: ";
        for (int i = 0; i < size; i++)
        {
            cout << id[i] << " ";
        }
        cout << endl;
    }

    void displaySizes()
    {
        cout << "Sizes: ";
        for (int i = 0; i < size; i++)
        {
            cout << sz[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    UnionFind uf(10);
    uf.displayRoots();
    uf.displaySizes();
    cout << uf.getComponents() << endl;

    // uf.unify(0, 4);

    // uf.displayRoots();
    // uf.displaySizes();

    uf.unify(1, 2);
    uf.unify(3, 4);
    uf.unify(2, 4);
    uf.unify(5, 6);
    uf.unify(5, 7);
    uf.unify(0, 5);
    uf.unify(0, 4);

    cout << "1. connected(1, 3): " << (uf.connected(1, 3) ? "yes" : "no") << endl;
    cout << "2. connected(1, 7): " << (uf.connected(1, 7) ? "yes" : "no") << endl;
    cout << "3. componentSize(0): " << uf.componentSize(0) << endl;
    cout << "4. componentSize(5): " << uf.componentSize(5) << endl;
    cout << "5. getComponents(): " << uf.getComponents() << endl;
    cout << "6. connected(8, 9): " << (uf.connected(8, 9) ? "yes" : "no") << endl;

    cout << "7. Final id[]: ";
    uf.displayRoots();

    cout << "8. Final sz[]: ";
    uf.displaySizes();

    return 0;
}