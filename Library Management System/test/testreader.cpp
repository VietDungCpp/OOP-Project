#include <iostream>
#include <cassert>
#include <sstream>
#include "test.h"
#include "reader.h"

using namespace std;

void testReader()
{
    cout << "\n [ testReader ]\n";

    Reader r(5, "Dung");
    assert(r.getID() == 5);
    assert(r.getName() == "Dung");

    ostringstream oss;
    oss << r;
    assert(oss.str().find("Dung") != string::npos);

    Book b(1, "Cpp Basic", "ISBN-001");
    Borrow* bw = r.borrowBook(b);
    assert(bw != nullptr);
    assert(bw->getReaderID() == 5);
    assert(bw->getBookID() == 1);
    delete bw;

    ReturnBook* rb = r.returnBook(b);
    assert(rb != nullptr);
    assert(rb->getReaderID() == 5);
    assert(rb->getBookID() == 1);
    delete rb;
}