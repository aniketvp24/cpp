# include <iostream>
using namespace std;

int main() {
    int index = 1;
    while (index <= 5) {
        cout << index << endl;
        index++;
    }

    index = 1;
    do {
        cout << index << endl;
        index++;
    } while (index <= 5);

    return 0;
}