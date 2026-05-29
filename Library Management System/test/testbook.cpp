#include <iostream>
#include <cassert>
#include <sstream>
#include "test.h"
#include "book.h"

using namespace std;

void testBook()
{
    cout << "\n[ testBook ]\n";

    Book b(10, "Cpp Basic", "ISBN-001");

    assert(b.getID() == 10);
    assert(b.getTitle() == "Cpp Basic");
    assert(b.getISBN() == "ISBN-001");
    assert(b.getAuthor().empty());

    Author a1(1, "viet dung");
    Author a2(2, "viet tien");
    b.addAuthor(&a1);
    assert(b.getAuthor().size() == 1);

    b.addAuthors({&a2});
    assert(b.getAuthor().size() == 2);
    assert(b.getAuthor()[0]->getAuthorName() == "viet dung");
    assert(b.getAuthor()[1]->getAuthorName() == "viet tien");

    ostringstream oss;
    oss << b;
    string s = oss.str();

    assert(s.find("Cpp Basic") != string::npos);
    assert(s.find("ISBN-001") != string::npos);
    assert(s.find("viet dung") != string::npos);
}