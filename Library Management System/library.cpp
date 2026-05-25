#include "library.h"
#include <iostream>

using namespace std;

void Library::addBook()
{
    Book b;

    b.input();

    books.push_back(b);

    cout << "Book added successfully\n";
}

void Library::showBooks() const
{
    if (books.empty())
    {
        cout << "No books in library\n";
        return;
    }

    for (const Book& b : books)
    {
        cout << "------------------\n";
        b.display();
    }
}

void Library::searchBookbyTitle() const
{
    cin.ignore();

    string key;

    cout << "Enter title to search: ";
    getline(cin, key);

    bool fo = false;

    for (const Book& b : books)
    {
        if (b.getTitle() == key)
        {
            b.display();
            fo = true;
        }
    }

    if (!fo)
    {
        cout << "Book not found\n";
    }
}

void Library::borrowBook()
{
    int id;
    
    cout << "Enter book ID to borrow: ";
    cin >> id;

    for (Book& b : books)
    {
        if (b.getID() == id)
        {
            if (b.isAvailable())
            {
                b.borrowBook();
                cout << "Borrowed successfully\n";
            }
            else
            {
                cout << "Book already borrowed\n";
            }

            return;
        }
    }

    cout << "Book not found\n";
}

void Library::returnBook()
{
    int id;

    cout << "Enter book ID to return: ";
    cin >> id;

    for (Book& b : books)
    {
        if (b.getID() == id)
        {
            b.returnBook();

            cout << "Returned successfully\n";

            return;
        }
    }

    cout << "Book not found\n";
}