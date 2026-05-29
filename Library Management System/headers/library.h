#ifndef LIBRARY_H
#define LIBRARY_H

#include <vector>
#include "book.h"
#include "reader.h"
#include "borrow.h"
#include "returnbook.h"

using namespace std;

class Library
{
    private:
        vector<Book*> books;
        vector<Reader*> readers;
        vector<Borrow*> borrows;
    public:
        Library();
        ~Library();

        void addBook(Book*);
        void addBooks(const vector<Book*>&);
        bool deleteBook(Book*);
        void listBooks() const;
        bool checkBook(const Book*) const;
        bool checkBook(int) const;

        void addReader(Reader*);
        void listReaders() const;
        bool deleteReader(Reader*);
        bool checkReader(const Reader*) const;
        bool checkReader(int) const;

        bool letBorrow(Borrow*);
        bool acceptReturn(ReturnBook*);
        void listBorrows() const;
};

#endif