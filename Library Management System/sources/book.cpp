#include "book.h"
#include <iostream>
#include <string>

using namespace std;

Book::Book(int id, string title, string isbn) : book_id(id), book_title(title), book_isbn(isbn) {}

Book::~Book() {}

int Book::getID() const
{
    return book_id;
}

string Book::getTitle() const
{
    return book_title;
}

string Book::getISBN() const
{
    return book_isbn;
}

vector<Author*> Book::getAuthor() const
{
    return authors;
}

void Book::addAuthor(Author* au)
{
    authors.push_back(au);
}

void Book::addAuthors(const vector<Author*>& aus)
{
    authors.insert(authors.end(), aus.begin(), aus.end());
}

ostream& operator<<(ostream& os, const Book& b)
{
    os << b.book_id << " - " << b.book_title << " - " << b.book_isbn << '\n';

    if (!b.authors.empty())
    {
        os << " | Authors: ";

        for (size_t i = 0; i < b.authors.size(); i++)
        {
            if (i > 0)
            {
                os << ", ";
            }
            os << *b.authors[i];
        }
    }

    return os;
}