#include <iostream>
#include <stack>
using namespace std;

void displayStackElements(stack<int> myStack)
{
    while (!myStack.empty())
    {
        cout << myStack.top() << endl;
        myStack.pop();
    }
}

int main()
{
    // empty, size, push, pop, top
    stack<int> myStack;

    myStack.push(1);
    myStack.push(2);
    myStack.push(3);
    myStack.pop();

    if (myStack.empty())
        cout
            << "Stack is empty!!" << endl;
    else
        cout << "Stack is not empty" << endl;

    cout << "Stack size: " << myStack.size() << endl;
    displayStackElements(myStack);

    return 0;
}