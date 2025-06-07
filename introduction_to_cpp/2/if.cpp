# include <iostream>
using namespace std;

int main() {
    bool isMale = false;
    bool isTall = true;

    if(isMale && isTall == true) {
        cout << "You are a tall male" << endl;
    } else if (isMale && !isTall) {
        cout << "You are a short male" << endl;
    } else if (!isMale && isTall) {
        cout << "You are tall and not a male" << endl;
    } else {
        cout << "You are not a male and not short" << endl;
    }
    

    return 0;
}