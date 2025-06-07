# include <iostream>
using namespace std;

int main() {
    int age;
    string name;

    cout << "Enter you name: ";
    getline(cin, name);

    cout << "Enter your age: ";
    cin >> age;

    cout << "Hello " << name << "!" << endl;
    cout << "You are " << age << " years old." << endl;
    return 0;
}