#ifndef MENU_H
#define MENU_H

#include <string>
#include "menuitem.h"
#include "library.h"

using namespace std;

class Menu
{
    private:
        string title;
        vector<MenuItem*> items;
    public:
        Menu(string);
        ~Menu();

        void addItem(MenuItem*);
        int show() const;
        void run() const;
    private:
        static int inputChoice(const string&);
};

class LibraryMenu
{
    private:
        Library& lib;
    public:
        LibraryMenu(Library&);
        void run();
    private:
        static int inputInt(const string&);
        static string inputString(const string&);

        void addBook();
        void deleteBook();
        void listBooks();

        void addReader();
        void deleteReader();
        void listReaders();

        void borrowBook();
        void returnBook();
        void listBorrows();
};

#endif