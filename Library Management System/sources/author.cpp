#include "author.h"
#include <iostream>

using namespace std;

Author::Author(int id, string name) : author_id(id), author_name(name) {}

Author::~Author() {}

int Author::getAuthorID() const
{
    return author_id;
}

string Author::getAuthorName() const
{
    return author_name;
}

ostream& operator<<(ostream& os, const Author& b)
{
    os << b.author_name;
    return os;
}