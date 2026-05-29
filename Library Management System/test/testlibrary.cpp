#include <iostream>
#include <cassert>
#include <sstream>
#include "test.h"
#include "library.h"

using namespace std;

void testLibrary()
{
    cout << "\n [ testLibrary ]\n";

    Library lib;
    Book b1(1, "Cpp Basic", "ISBN-001");
    Book b2(2, "Cpp Advanced", "ISBN-002");
    Reader r1(1, "Dung");
    Reader r2(2, "Tien");
    
    lib.addBook(&b1);
    lib.addBook(&b2);
    lib.addReader(&r1);
    lib.addReader(&r2);

    assert(lib.checkBook(1) == true);
    assert(lib.checkBook(3) == false);
    assert(lib.checkReader(1) == true);
    assert(lib.checkReader(3) == false);

    Borrow* bw1 = r1.borrowBook(b1);
    assert(lib.letBorrow(bw1) == true);

    Borrow* bw2 = new Borrow(1, 3, Date());
    assert(lib.letBorrow(bw2) == false);
    delete bw2;

    Borrow* bw3 = new Borrow(3, 1, Date());
    assert(lib.letBorrow(bw2) == false);
    delete bw3;
    
    assert(lib.deleteBook(&b1) == false);

    ReturnBook* rb1 = r1.returnBook(b1);
    assert(lib.acceptReturn(rb1) == true);
    delete rb1;

    assert(lib.deleteBook(&b1) == true);
    assert(lib.checkBook(1) == false);

    ReturnBook* rb2 = r2.returnBook(b2);
    assert(lib.acceptReturn(rb2) == false);
    delete rb2;

    Borrow* bw2 = r2.borrowBook(b2);
    lib.letBorrow(bw2);
    assert(lib.deleteReader(&r2) == false);

    ReturnBook* rb3 = r2.returnBook(b2);
    lib.acceptReturn(rb3);
    delete rb3;

    assert(lib.deleteReader(&r2) == true);
    assert(lib.checkReader(2) == false);

    assert(lib.deleteReader(&r2) == false);
}