#include "library.h"
#include <iostream>
#include <algorithm>

using namespace std;

Library::Library() {}

Library::~Library()
{
    for (Borrow* b : borrows)
    {
        delete b;
    }
    borrows.clear();
}

void Library::addBook(Book* book)
{
    books.push_back(book);
}

void Library::addBooks(const vector<Book*>& book)
{
    books.insert(books.end(), book.begin(), book.end());
}

bool Library::deleteBook(Book* book)
{
    for (const Borrow* bw : borrows)
    {
        if (bw->getBookID() == book->getID())
        {
            return false;
        }
    }

    auto it = find(books.begin(), books.end(), book);
    if (it == books.end())
    {
        return false;
    }

    books.erase(it);
    return true;
}

void Library::listBooks() const
{
    for (Book* b : books)
    {
        cout << *b;
    }
}

void Library::addReader(Reader* reader)
{
    readers.push_back(reader);
}

void Library::listReaders() const
{
    for (const Reader* r : readers)
    {
        cout << *r;
    }
}

bool Library::deleteReader(Reader* reader)
{
    for (const Borrow* bw : borrows)
    {
        if (bw->getReaderID() == reader->getID())
        {
            return false;
        }
    }

    auto it = find(readers.begin(), readers.end(), reader);
    if (it == readers.end())
    {
        return false;
    }

    // if (!checkReader(reader))
    // {
    //     return false;
    // }

    readers.erase(it);
    return true;
}

bool Library::checkBook(const Book* book) const
{
    return checkBook(book->getID());
}

bool Library::checkBook(int id) const
{
    return any_of(books.begin(), books.end(), [id](const Book* b) {
        return b->getID() == id;
    });
}

bool Library::checkReader(const Reader* reader) const
{
    return checkReader(reader->getID());
}

bool Library::checkReader(int id) const
{
    return any_of(readers.begin(), readers.end(), [id](const Reader* r) {
        return r->getID() == id;
    });
}

bool Library::letBorrow(Borrow* bo)
{
    if (checkReader(bo->getReaderID()) && checkBook(bo->getBookID()))
    {
        borrows.push_back(bo);
        return true;
    }

    return false;
}

bool Library::acceptReturn(ReturnBook* re)
{
    auto it = find_if(borrows.begin(), borrows.end(), [&](const Borrow* bw) {
        return bw->getReaderID() == re->getReaderID()
            && bw->getBookID() == re->getBookID();
    });

    if (it == borrows.end())
    {
        return false;
    }

    delete *it;
    borrows.erase(it);

    return true;
}

void Library::listBorrows() const
{
    if (borrows.empty())
    {
        return;
    }

    for (const Borrow* bw : borrows)
    {
        cout << "Reader " << bw->getReaderID()
             << " - Book " << bw->getBookID()
             << " (borrowed: " << bw->getDate() << ")\n";
    }
}