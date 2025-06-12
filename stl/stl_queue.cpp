#include <iostream>
#include <queue>
using namespace std;

void displayQueueElements(queue<int> myQueue)
{
    while (!myQueue.empty())
    {
        cout << myQueue.front() << " ";
        myQueue.pop();
    }
    cout << endl;
}

int main()
{
    queue<int> myQueue;
    myQueue.push(1);
    myQueue.push(2);
    myQueue.push(3);

    cout << "Front: " << myQueue.front() << endl;
    cout << "Back: " << myQueue.back() << endl;
    cout << "Size: " << myQueue.size() << endl;

    if (myQueue.empty())
        cout << "Queue is empty!!" << endl;
    else
        cout << "Queue is not empty!" << endl;

    myQueue.pop();
    displayQueueElements(myQueue);
    return 0;
}