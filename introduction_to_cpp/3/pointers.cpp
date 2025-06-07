# include <iostream>
using namespace std;

int main() {
    int age = 24;
    double pi = 3.14;
    string name = "Aniket";

    int *page = &age;
    double *ppi = &pi;
    string *pname = &name;
 
    cout << &*page << endl;
    cout << *ppi << endl;
    cout << *pname << endl;

    return 0;
}