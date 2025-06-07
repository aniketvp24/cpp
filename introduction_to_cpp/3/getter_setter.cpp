# include <iostream>
using namespace std;

class Book {
    private:
        int pages;

    public:
        string title;
        Book(string btitle, int bpages) {
            title = btitle;
            setPages(bpages);
        } 

        bool isBookLengthy() {
            if (pages > 100) {
                return true;
            }
            return false;
        }
        
        void setPages(int bpages) {
            if (bpages < 0) {
                pages = 0;
            } else {
                pages = bpages;
            }
        }
        

        int getPages() {
            return pages;
        }
};

int main() {
    Book book1("Lord of the Rings", 500);
    Book book2("Harry Potter", -100);

    // cout << book1.title << " | "  << book1.isBookLengthy() << " | " << endl;
    // cout << book2.title << " | "  << book2.isBookLengthy() << " | " << endl;


    cout << book1.title << " | "  << book1.isBookLengthy() << " | " << book1.getPages() << endl;
    cout << book2.title << " | "  << book2.isBookLengthy() << " | " << book2.getPages() << endl;

    return 0;
}