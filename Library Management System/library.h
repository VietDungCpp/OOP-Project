#ifndef LIBRARY_H
#define LIBRARY_H

#include <vector>
#include "book.h"

using namespace std;

class Library
{
    private:
        vector<Book> books;
    public:
        void addBook();
        void showBooks() const;
        void searchBookbyTitle() const;

        void borrowBook();
        void returnBook();
};

#endif