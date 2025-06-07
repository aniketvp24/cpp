# include <iostream>
using namespace std;

class Book {
    public:
        string title;
        int pages;

        Book(string btitle, int bpages) {
            title = btitle;
            pages = bpages;
        } 

        bool isBookLengthy() {
            if (pages > 100) {
                return true;
            }
            return false;
        }
};

int main() {
    Book book1("Lord of the Rings", 500);
    Book book2("Harry Potter", 100);

    cout << book1.title << " | " << book1.pages << " | " << book1.isBookLengthy() << endl;
    cout << book2.title << " | " << book2.pages << " | " << book2.isBookLengthy() << endl;

    return 0;
}