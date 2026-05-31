#include <iostream>
#include <cassert>
#include "test.h"
#include "library.h"

using namespace std;

void testLibrary()
{
    cout << "\n[ testLibrary ]\n";

    Library lib;

    Book* b1 = new Book(1, "Cpp Basic", "ISBN-001");
    Book* b2 = new Book(2, "Cpp Advanced", "ISBN-002");

    Reader* r1 = new Reader(1, "Dung");
    Reader* r2 = new Reader(2, "Tien");

    lib.addBook(b1);
    lib.addBook(b2);

    lib.addReader(r1);
    lib.addReader(r2);

    Borrow* bw1 = lib.borrowBook(1, 1);

    assert(bw1 != nullptr);

    Borrow* bw2 = lib.borrowBook(1, 3);

    assert(bw2 == nullptr);

    Borrow* bw3 = lib.borrowBook(3, 1);

    assert(bw3 == nullptr);

    assert(lib.deleteBook(1) == false);

    ReturnBook* rb1 = lib.returnBook(1, 1);

    assert(rb1 != nullptr);

    delete rb1;

    assert(lib.deleteBook(1) == true);

    ReturnBook* rb2 = lib.returnBook(2, 2);

    assert(rb2 == nullptr);

    Borrow* bw4 = lib.borrowBook(2, 2);

    assert(bw4 != nullptr);

    assert(lib.deleteReader(2) == false);

    ReturnBook* rb3 = lib.returnBook(2, 2);

    assert(rb3 != nullptr);

    delete rb3;

    assert(lib.deleteReader(2) == true);

    assert(lib.deleteReader(2) == false);

    cout << "All Library tests passed.\n";
}