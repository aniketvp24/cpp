# include <iostream>
using namespace std;

class Book {
    public:
        string title;
        int pages;
};

int main() {
    Book book1;
    book1.title = "Title";
    cout << book1.title;
    return 0;
}