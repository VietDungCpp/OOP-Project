#ifndef READER_H
#define READER_H

#include "borrow.h"
#include "returnbook.h"
#include "book.h"
#include <string>
#include <iostream>

using namespace std;

class Reader
{
    private:
        int reader_id;
        string reader_name;
    public:
        Reader(int id, string name) : reader_id(id), reader_name(name) {}

        int getID() const
        {
            return reader_id;
        }
        string getName() const
        {
            return reader_name;
        }

        Borrow* borrowBook(const Book&);
        ReturnBook* returnBook(const Book&);

        friend ostream& operator<<(ostream&, const Reader&);
};

#endif