#ifndef LIBRARYMENU_H
#define LIBRARYMENU_H

#include "library.h"
#include <string>

using namespace std;

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