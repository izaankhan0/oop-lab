#include <iostream>
#include <vector>
using namespace std;

class Books
{
protected:
    string genre;

public:
    Books(string genre) : genre(genre) {}

    void setGenre(string genre) { this->genre = genre; }
    string getGenre() { return genre; }
    virtual void display() = 0;
    virtual string getTitle() = 0;

    virtual ~Books() {}
};

class Kids : public Books
{
    string title;
    string author;

public:
    Kids(string title, string author, string genre) : title(title), author(author), Books(genre) {};
    string getTitle() override { return title; }
    string getAuthor() { return author; }
    void display() override
    {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Genre: " << genre << endl;
    }
    ~Kids() {}
};

class Adult : public Books
{
    string title;
    string author;

public:
    Adult(string title, string author, string genre) : title(title), author(author), Books(genre) {};
    string getTitle() { return title; }
    string getAuthor() { return author; }
    void display() override
    {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Genre: " << genre << endl;
    }
    ~Adult() {}
};

int main()
{

    vector<Books *> books;
    string title, author, genre;
    int choice = -1;
    bool flag = false;
    cout << "|--- Welcome to Library Book Management System ---|" << endl;
    while (choice != 0)
    {
        cout << endl;
        cout << "Press 1 to add a Kids Book" << endl;
        cout << "Press 2 to add a Adult Book" << endl;
        cout << "Press 3 to display all books" << endl;
        cout << "Press 4 to find a book" << endl;
        cout << "Press 0 to Exit" << endl;
        cout << "Enter Choice: ";
        cin >> choice;
        if (choice == 1)
        {
            cout << "Enter Title: ";
            cin >> title;
            cout << "Enter Author: ";
            cin >> author;
            cout << "Enter Genre: ";
            cin >> genre;
            books.push_back(new Kids(title, author, genre));
            cout << "\nKids Book Added!" << endl;
        }
        else if (choice == 2)
        {
            cout << "Enter Title: ";
            cin >> title;
            cout << "Enter Author: ";
            cin >> author;
            cout << "Enter Genre: ";
            cin >> genre;
            books.push_back(new Adult(title, author, genre));
            cout << "\nAdult Book Added!" << endl;
        }
        else if (choice == 3)
        {
            for (int i = 0; i < books.size(); i++)
            {
                cout << "\nBook #" << i + 1 << endl;
                books.at(i)->display();
                cout << "\n";
            }
        }
        else if (choice == 4)
        {
            cout << "Enter Title of book: ";
            cin >> title;
            for (int i = 0; i < books.size(); i++)
            {
                if (title == books.at(i)->getTitle())
                {
                    cout << "\nBook found in shelf " << i + 1 << endl;
                    flag = true;
                    books.at(i)->display();
                    cout << "\n";
                }
            }
            if (!flag)
            {
                cout << "Book not found!" << endl;
            }
            else
            {
                flag = false;
            }
        }
        else if (choice == 0)
        {
            cout << "Goodbye!" << endl;
        }
        else
        {
            cout << "Invalid Input" << endl;
        }
    }

    return 0;
}