#include <iostream>
using namespace std;

template <typename T>
class Calculator
{
public:
    T add(T num1, T num2)
    {
        return num1 + num2;
    }

    T subtract(T num1, T num2)
    {
        return num1 - num2;
    }
};

int main()
{
    Calculator<int> intCalulator;
    cout << intCalulator.add(10, 20) << endl;
    cout << intCalulator.subtract(5, 3) << endl;

    Calculator<float> floatCalulator;
    cout << floatCalulator.add(10.1, 20.2) << endl;
    cout << floatCalulator.subtract(5.7, 3.2) << endl;

    return 0;
}