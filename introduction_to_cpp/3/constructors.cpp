# include <iostream>
using namespace std;

class Book {
    public:
        string title;
        int pages;

        Book() {
            title = "No title";
            pages = 0;
        }

        Book(string btitle, int bpages) {
            title = btitle;
            pages = bpages;
        } 
};

int main() {
    Book book1;
    Book book2("Harry Potter", 100);

    cout << book1.title << " | " << book1.pages << endl;
    cout << book2.title << " | " << book2.pages << endl;

    return 0;
}