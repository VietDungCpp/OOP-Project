#include <iostream>
#include <vector>
#include "date.h"
#include "book.h"
#include "reader.h"
#include "library.h"

using namespace std;

int main()
{
    Book b1(1, "Cpp basic", "1234");
    Book b2(2, "Cpp advanced", "5678");

    // Author au1(1, "Bjarne Stroustrup");
    // b1.setAuthor(&au1);

    // Author au2(2, "Viet Dung");
    // Author au3(3, "Viet Tien");
    // b2.setAuthor(&au2);
    // b2.setAuthor(&au3);

    // cout << b1 << '\n' << b2 << '\n';

    // Date d1, d2;
    // d1.setDate("26/5/2026");
    // d2.setDate("31/12/2026");

    // string d1Date = d1.getDateString();
    // string d2Date = d2.getDateString();
    // cout << d1Date;
    // cout << d2Date;

    // cout <<  "days diff: " << daysDiff(d1, d2) << "days";

    // cout << "\ncompare\n";
    // cout << (d1 > d2) << '\n';
    // cout << (d1 < d2) << '\n';
    // cout << (d1 == d2) << '\n';

    Reader r1(1, "dung");
    Borrow* bo1 = r1.borrowBook(b1);

    // cout << bo1->getReaderID() << " " << bo1->getBookID() << " " << bo1->getDate().getDateString() << '\n';

    // ReturnBook* rb1 = r1.returnBook(b1);

    // cout << rb1->getReaderID() << " " << rb1->getBookID() << " " << rb1->getDate().getDateString() << '\n';

    // Date borrowdate = bo1->getDate();
    // Date returndate = rb1->getDate();

    // cout << (borrowdate < returndate);

    Library lib;
    lib.addBooks(vector<Book*>{&b1, &b2});

    // lib.listBooks();

    // lib.deleteBook(&b1);

    // lib.listBooks();

    cout << lib.checkBook(&b1);
}