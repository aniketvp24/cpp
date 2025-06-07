# include <iostream>
using namespace std;

class Person {
    public:
        void sayHello() {
            cout << "Hello!" << endl;
        }
};

class Student: public Person {
    public:
        void about() {
            cout << "I am a student." << endl;
        }

        void sayHello() {
            cout << "Hello! I am a student." << endl;
        }
};


int main() {
    Student student1;
    student1.about();
    student1.sayHello();

    return 0;
}