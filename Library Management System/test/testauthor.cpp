#include <iostream>
#include <cassert>
#include <sstream>
#include "test.h"
#include "author.h"

using namespace std;

void testAuthor()
{
    cout << "\n[ test Author ]\n";

    Author a(1, "Bjarne Stroustrup");

    assert(a.getAuthorID() == 1);
    assert(a.getAuthorName() == "Bjarne Stroustrup");

    ostringstream oss;
    oss << a;
    assert(oss.str() == "Bjarne Stroustrup");
}