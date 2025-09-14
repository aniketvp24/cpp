#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void swap(vector<int> &arr, int i, int j)
{
    int buffer = arr[i];
    arr[i] = arr[j];
    arr[j] = buffer;
}

void heapSort(vector<int> &arr)
{
}

void heapify(vector<int> &arr, int i)
{
    int n = arr.size();
    int left, right, max;
    left = 2 * i + 1;
    right = 2 * i + 2;

    if (left <= n - 1 && arr[left] > arr[i])
    {
        max = left;
    }
    else
    {
        max = i;
    }

    if (right <= n - 1 && arr[right] > arr[max])
    {
        max = right;
    }

    if (max != i)
    {
        swap(arr, max, i);
        heapify(arr, max);
    }
}

void buildMaxHeap(vector<int> &arr)
{
    int n = arr.size();

    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, i);
    }
}

int main()
{
    vector<int> arr = {1, 2, 4, 3};
    // swap(arr, 2, 3);

    buildMaxHeap(arr);

    for (int elem : arr)
    {
        cout << elem << endl;
    }

    return 0;
}