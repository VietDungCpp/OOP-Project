#include "librarymenu.h"
#include "menu.h"
#include <iostream>
#include <string>
#include <limits>

using namespace std;

LibraryMenu::LibraryMenu(Library& l) : lib(l) {}

void LibraryMenu::run()
{
    Menu bookMenu("Book Management");
    bookMenu.addItem(new MenuItem(1, "Add book", [this]() {
        addBook();
    }));
    bookMenu.addItem(new MenuItem(2, "Delete book", [this]() {
        deleteBook();
    }));
    bookMenu.addItem(new MenuItem(3, "List books", [this]() {
        listBooks();
    }));

    Menu readerMenu("Reader Management");
    readerMenu.addItem(new MenuItem(1, "Add reader", [this]() {
        addReader();
    }));
    readerMenu.addItem(new MenuItem(2, "Delete reader", [this]() {
        deleteReader();
    }));
    readerMenu.addItem(new MenuItem(3, "List readers", [this]() {
        listReaders();
    }));

    Menu borrowMenu("Borrow / Return");
    borrowMenu.addItem(new MenuItem(1, "Borrow a book", [this]() {
        borrowBook();
    }));
    borrowMenu.addItem(new MenuItem(2, "Return a book", [this]() {
        returnBook();
    }));
    borrowMenu.addItem(new MenuItem(3, "View borrows by reader", [this]() {
        listBorrows();
    }));

    Menu mainMenu("LIBRARY SYSTEM");
    mainMenu.addItem(new MenuItem(1, "Book management", [&bookMenu]() {
        bookMenu.run();
    }));
    mainMenu.addItem(new MenuItem(2, "Reader management", [&readerMenu]() {
        readerMenu.run();
    }));
    mainMenu.addItem(new MenuItem(3, "Borrow / Return", [&borrowMenu]() {
        borrowMenu.run();
    }));

    mainMenu.run();
    cout << "Goodbye!\n";

}

int LibraryMenu::inputInt(const string& s)
{
    int val;
    while (true)
    {
        cout << s;
        cin >> val;

        if (cin.good())
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return val;
        }

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "  Invalid input, please enter a number.\n";
    }
}

string LibraryMenu::inputString(const string& s)
{
    string val;
    cout << s;
    getline(cin, val);
    return val;
}

void LibraryMenu::addBook()
{
    int id = inputInt("  Book ID   : ");
    string title = inputString("  Title     : ");
    string isbn = inputString("  ISBN      : ");
    string author_name = inputString("  Author name: ");
    int author_id = inputInt("  Author ID : ");

    Book* b = new Book(id, title, isbn);
    b->addAuthor(new Author(author_id, author_name));

    lib.addBook(b);
    cout << "  Book added.\n";
}

void LibraryMenu::deleteBook()
{
    lib.listBooks();
    int id = inputInt("  Enter book ID to delete: ");

    lib.deleteBook(id);
    cout << "  Book deleted.\n";
}

void LibraryMenu::listBooks()
{
    cout << '\n';
    lib.listBooks();
}

void LibraryMenu::addReader()
{
    int id = inputInt("  Reader ID : ");
    string name = inputString("  Name      : ");

    lib.addReader(new Reader(id, name));
    cout << "  Reader added.\n";
}

void LibraryMenu::deleteReader()
{
    lib.listReaders();
    int id = inputInt("  Enter reader ID to delete: ");

    lib.deleteReader(id);
    cout << "  Reader deleted.\n";
}

void LibraryMenu::listReaders()
{
    cout << '\n';
    lib.listReaders();
}

void LibraryMenu::borrowBook()
{
    int r_id = inputInt("  Reader ID : ");
    int b_id = inputInt("  Book ID   : ");

    Borrow* bw = lib.borrowBook(r_id, b_id);

    if (bw)
    {
        cout << "  Borrow recorded on " << bw->getDate() << ".\n";
    }
}

void LibraryMenu::returnBook()
{
    int r_id = inputInt("  Reader ID : ");
    int b_id = inputInt("  Book ID   : ");

    ReturnBook* rb = lib.returnBook(r_id, b_id);
    
    if (rb)
    {
        cout << "  Return recorded on " << rb->getDate() << ".\n";
    }
    
    delete rb;
}

void LibraryMenu::listBorrows()
{
    int r_id = inputInt("  Reader ID : ");
    lib.listBorrows(r_id);
}