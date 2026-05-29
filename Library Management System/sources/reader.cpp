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

ostream& operator<<(ostream& os, const Reader& r)
{
    os << r.reader_id << " - " << r.reader_name << '\n';
    return os;
}