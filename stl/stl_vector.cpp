#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> numbers;
    // numbers.push_back(7);

    for (int i = 1; i <= 10; i++)
    {
        numbers.push_back(i);
    }

    // numbers.insert(numbers.begin() + 5, 88);
    numbers.erase(numbers.begin() + 5);
    numbers.pop_back();

    for (int number : numbers)
        cout << number << endl;

    // auto it = numbers.begin();
    // cout << *(it + 5) << endl;

    // cout << "Size: " << numbers.size() << endl;
    // cout << "Max Size: " << numbers.max_size() << endl;
    // cout << "Max Capacity: " << numbers.capacity() << endl;
    // numbers.resize(5);
    // cout << "Size: " << numbers.size() << endl;

    // if (numbers.empty())
    // {
    //     cout << "Vector is empty!!" << endl;
    // }
    // else
    // {
    //     cout << "Vector is not empty!" << endl;
    // }

    // cout << "Element[0]: " << numbers[0] << endl;
    // cout << "Element.at(0): " << numbers.at(0) << endl;
    // cout << "Front: " << numbers.front() << endl;
    // cout << "Back: " << numbers.size() << endl;

    // for (auto it = numbers.cbegin(); it != numbers.cend(); it++)
    // {
    //     // *it = 10; Does not work in case of cbegin, cend;
    //     cout << *it << endl;
    //     // cout << &it << endl;
    //     // cout << &*it << endl;
    //     // cout << "******************" << endl;
    // }
    // numbers.clear();
    // cout << "Size: " << numbers.size() << endl;

    // for (vector<int>::iterator it = numbers.begin(); it <= numbers.end(); it++)
    // {
    //     cout << *it << endl;
    //     cout << &it << endl;
    //     cout << &*it << endl;
    //     // cout << *&it << endl; Does not work
    //     cout << "******************" << endl;
    // }

    // for (int i = 0; i < numbers.size(); i++)
    // {
    //     cout << numbers[i] << endl;
    // }
    // cout << numbers.size() << endl;
    // cout << numbers[13] << endl;

    // for (int number : numbers)
    //     cout << number << endl;

    return 0;
}