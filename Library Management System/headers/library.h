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
        bool deleteBook(int);
        void listBooks() const;

        void addReader(Reader*);
        void listReaders() const;
        bool deleteReader(int);

        Borrow* borrowBook(int, int);
        ReturnBook* returnBook(int, int);
        void listBorrows(int) const;
    private:
        Book* findBook(int);
        Reader* findReader(int);
        const Book* findBook(int) const;
        const Reader* findReader(int) const;

        bool letBorrow(Borrow*);
        bool acceptReturn(ReturnBook*);
    };

#endif