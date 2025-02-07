#include <iostream>
#include <string>
using namespace std;

class Book {
    string bookName;
    string isbn;
    string author;
    string publisher;
public:
    Book(string bookName, string isbn, string author, string publisher) {
        this->bookName = bookName;
        this->isbn = isbn;
        this->author = author;
        this->publisher = publisher;
    }

    string getBookName(){ return this->bookName; }
    string getISBN(){ return this->isbn; }
    string getAuthor(){ return this->author; }
    string getPublisher(){ return this->publisher; }

    string getBookInfo() const {
        return "Book Name: " + this->bookName + "\nISBN: " + this->isbn + "\nAuthor: " + this->author + "\nPublisher: " + this->publisher;
    }
};

int main() {
    Book books[5] = {
        Book("The Great Gatsby", "9780743273565", "F. Scott Fitzgerald", "Scribner"),
        Book("To Kill a Mockingbird", "9780061120084", "Harper Lee", "J.B. Lippincott & Co."),
        Book("1984", "9780451524935", "George Orwell", "Secker & Warburg"),
        Book("Pride and Prejudice", "9781503290563", "Jane Austen", "T. Egerton"),
        Book("Moby Dick", "9781503280786", "Herman Melville", "Harper & Brothers")
    };

    for (int i = 0; i < 5; i++) {
        cout << "Book " << i + 1 << " Details:\n" << books[i].getBookInfo() << "\n\n";
    }
    
    return 0;
}
