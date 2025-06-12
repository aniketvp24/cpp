#include <iostream>
using namespace std;

template <typename T>
T add(T num1, T num2)
{
    return num1 + num2;
}

int main()
{
    cout << add(10, 20) << endl;
    cout << add(10.2, 20.8) << endl;
    return 0;
}
