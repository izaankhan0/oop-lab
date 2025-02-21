#include <iostream>
#include <string>

using namespace std;

class Book {
    string title;
    string ISBN;
public:
    Book(string t, string i) : title(t), ISBN(i) {
        cout << "Book Created: " << title << " (" << ISBN << ")" << endl;
    }

    ~Book() {
        cout << "Book Destroyed: " << title << " (" << ISBN << ")" << endl;
    }

    string getISBN() const { return ISBN; }
    string getTitle() const { return title; }
};

class Catalog {
    Book* books[100];
    string isbns[100];
    int count;
public:
    Catalog() : count(0) {}

    void addBook(Book* book) {
        books[count] = book;
        isbns[count] = book->getISBN();
        count++;
    }

    void removeBook(string ISBN) {
        for (int i = 0; i < count; i++) {
            if (isbns[i] == ISBN) {
                for (int j = i; j < count - 1; j++) {
                    books[j] = books[j + 1];
                    isbns[j] = isbns[j + 1];
                }
                count--;
                break;
            }
        }
    }

    Book* findBook(string ISBN) {
        for (int i = 0; i < count; i++) {
            if (isbns[i] == ISBN) {
                return books[i];
            }
        }
        return nullptr;
    }
};

class Library {
    Catalog catalog;
    Book* books[100];
    int bookCount;
public:
    Library() : bookCount(0) {}

    void addBook(Book* book) {
        books[bookCount] = book;
        catalog.addBook(book);
        bookCount++;
    }

    void removeBook(string ISBN) {
        for (int i = 0; i < bookCount; i++) {
            if (books[i]->getISBN() == ISBN) {
                for (int j = i; j < bookCount - 1; j++) {
                    books[j] = books[j + 1];
                }
                bookCount--;
                break;
            }
        }
        catalog.removeBook(ISBN);
    }

    void searchBook(string ISBN) {
        Book* book = catalog.findBook(ISBN);
        if (book)
            cout << "Book Found: " << book->getTitle() << endl;
        else
            cout << "Book Not Found" << endl;
    }
};

int main() {
    Library myLibrary;

    Book book1("C++ Programming", "1234");
    Book book2("Data Structures", "5678");

    myLibrary.addBook(&book1);
    myLibrary.addBook(&book2);

    myLibrary.searchBook("1234");
    myLibrary.searchBook("9999");

    myLibrary.removeBook("1234");
    myLibrary.searchBook("1234");

    return 0;
}
