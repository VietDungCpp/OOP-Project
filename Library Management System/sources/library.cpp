#include "library.h"
#include <iostream>
#include <algorithm>

using namespace std;

Library::Library() {}

Library::~Library()
{
    for (Book* b : books)
    {
        delete b;
    }

    for (Reader* r : readers)
    {
        delete r;
    }

    for (Borrow* bw : borrows)
    {
        delete bw;
    }

    books.clear();
    readers.clear();
    borrows.clear();
}

Book* Library::findBook(int id)
{
    auto it = find_if(books.begin(), books.end(), [id](Book* b) {
        return b->getID() == id;
    });

    return (it != books.end()) ? *it : nullptr;
}

const Book* Library::findBook(int id) const
{
    auto it = find_if(books.begin(), books.end(), [id](Book* b) {
        return b->getID() == id;
    });

    return (it != books.end()) ? *it : nullptr;
}

Reader* Library::findReader(int id)
{
    auto it = find_if(readers.begin(), readers.end(), [id](Reader* r) {
        return r->getID() == id;
    });
    
    return (it != readers.end()) ? *it : nullptr;
}

const Reader* Library::findReader(int id) const
{
    auto it = find_if(readers.begin(), readers.end(), [id](Reader* r) {
        return r->getID() == id;
    });
    
    return (it != readers.end()) ? *it : nullptr;
}

void Library::addBook(Book* b)
{
    if (b)
    {
        books.push_back(b);
    }
}

void Library::addBooks(const vector<Book*>& b)
{
    books.insert(books.end(), b.begin(), b.end());
}

bool Library::deleteBook(int id)
{
    auto it = find_if(books.begin(), books.end(), [id](Book* b) {
        return b->getID() == id; 
    });

    if (it == books.end())
    {
        return false;
    }

    delete *it;
    books.erase(it);

    return true;
}

void Library::listBooks() const
{
    for (const Book* b : books)
    {
        cout << *b << '\n';
    }
}

void Library::addReader(Reader* r)
{
    if (r)
    {
        readers.push_back(r);
    }
}

bool Library::deleteReader(int id)
{
    auto it = find_if(readers.begin(), readers.end(), [id](Reader* r) {
        return r->getID() == id;
    });

    if (it == readers.end())
    {
        return false;
    }

    delete *it;
    readers.erase(it);

    return true;
}

void Library::listReaders() const
{
    for (const Reader* r : readers)
    {
        cout << *r << '\n';
    }
}

bool Library::letBorrow(Borrow* bw)
{
    if (!bw)
    {
        return false;
    }

    borrows.push_back(bw);

    return true;
}

bool Library::acceptReturn(ReturnBook* rb)
{
    if (!rb)
    {
        return false;
    }

    auto it = find_if(borrows.begin(), borrows.end(), [&](const Borrow* bw) {
        return bw->getReaderID() == rb->getReaderID() && bw->getBookID() == rb->getBookID();
    });

    if (it == borrows.end())
    {
        return false;
    }

    delete *it;
    borrows.erase(it);

    return true;
}

Borrow* Library::borrowBook(int r_id, int b_id)
{
    Reader* r = findReader(r_id);
    Book* b = findBook(b_id);

    if (!r || !b)
    {
        return nullptr;
    }

    Borrow* bw = r->borrowBook(*b);

    if (!letBorrow(bw))
    {
        delete bw;
        return nullptr;
    }

    return bw;
}

ReturnBook* Library::returnBook(int r_id, int b_id)
{
    Reader* r = findReader(r_id);
    Book* b = findBook(b_id);

    if (!r || !b)
    {
        return nullptr;
    }

    ReturnBook* rb = r->returnBook(*b);

    if (!acceptReturn(rb))
    {
        delete rb;
        return nullptr;
    }

    return rb;
}

void Library::listBorrows(int r_id) const
{
    const Reader* r = findReader(r_id);
    if (!r)
    {
        return;
    }

    bool fo = false;
    for (const Borrow* bw : borrows)
    {
        if (bw->getReaderID() != r_id)
        {
            continue;
        }

        const Book* b = findBook(bw->getBookID());

        cout << "Reader : " << r->getID() << " - " << r->getName() << '\n'
             << "Book   : " << b->getID()   << " - " << b->getTitle()  << '\n'
             << "Borrowed: " << bw->getDate() << '\n'
             << "-----\n";
        fo = true;
    }

    if (!fo)
    {
        return;
    }
}