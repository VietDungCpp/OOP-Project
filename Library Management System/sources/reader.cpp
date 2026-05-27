#include "reader.h"

using namespace std;

Borrow* Reader::borrowBook(const Book& b)
{
    return new Borrow(reader_id, b.getID(), Date());
}

ReturnBook* Reader::returnBook(const Book& b)
{
    return new ReturnBook(reader_id, b.getID(), Date());
}