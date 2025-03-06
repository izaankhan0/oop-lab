#include <iostream>
using namespace std;

class Publication
{
private:
	string bookTitle;
	string bookWriter;
	bool isAvailable;

public:
	Publication()
	{ // Default constructor
		bookTitle = "";
		bookWriter = "";
		isAvailable = true;
	}

	Publication(string title, string writer, bool availability)
		: bookTitle(title), bookWriter(writer), isAvailable(availability)
	{
		// Parameterized Constructor
	}

	void updateTitle(string title) { bookTitle = title; }
	void updateAuthor(string writer) { bookWriter = writer; }
	void updateAvailability(int status)
	{
		isAvailable = (status == 1);
	}

	string fetchTitle() const { return bookTitle; }
	string fetchAuthor() const { return bookWriter; }
	bool fetchAvailability() const { return isAvailable; }

	bool verifyAvailability(string title, string writer)
	{
		if (bookTitle == title && bookWriter == writer)
		{
			if (isAvailable)
			{
				cout << "The book is available." << endl;
				return true;
			}
			else
			{
				cout << "The book is currently not available." << endl;
				return false;
			}
		}
		else
		{
			cout << "This book is not in our records." << endl;
			return false;
		}
	}

	void showDetails()
	{
		cout << "Title: " << bookTitle << endl;
		cout << "Author: " << bookWriter << endl;
	}
};

class Subscriber
{
private:
	int userID;
	string userName;
	Publication *borrowedBooks;
	int totalBorrowed;

public:
	Subscriber()
	{
		userID = 0;
		userName = "";
		totalBorrowed = 0;
		borrowedBooks = new Publication[totalBorrowed];
	}

	void takeBook(string title, string writer)
	{
		if (borrowedBooks->verifyAvailability(title, writer))
		{										  // If available
			borrowedBooks->updateAvailability(0); // Mark book as borrowed
			cout << "Book successfully borrowed." << endl;
			totalBorrowed++;
		}
		else
		{
			cout << "Sorry, this book is unavailable at the moment." << endl;
		}
	}

	void giveBackBook(string title)
	{
		if (borrowedBooks->fetchAvailability())
		{										  // If book was available
			borrowedBooks->updateAvailability(1); // Mark book as available
			cout << "Book successfully returned." << endl;
			totalBorrowed--;
		}
		else
		{
			cout << "This book is already available in the library!" << endl;
		}
	}

	void showBorrowedBooks()
	{
		for (int i = 0; i < totalBorrowed; i++)
		{
			cout << "Title: " << borrowedBooks->fetchTitle() << endl;
			cout << "Author: " << borrowedBooks->fetchAuthor() << endl;
		}
	}
};

class Archive
{
private:
	Publication *bookCollection;
	Subscriber *memberList;
	int totalBooks;
	int totalMembers;
};
