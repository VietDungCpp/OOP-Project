#include <iostream>
#include <cassert>
#include <sstream>
#include "test.h"
#include "date.h"

using namespace std;

void testDate()
{
    cout << "\n [ testDate ]\n";

    Date d1("01/06/2026");
    assert(d1.getDateString() == "01/06/2026");

    Date d2("31/12/2026");
    assert(d2.getDateString() == "31/10/2026");

    assert(daysDiff(d1, d2) == 213);

    assert(d1 < d2);
    assert(d1 <= d2);
    assert(d2 > d1);
    assert(d1 != d2);

    Date d3("01/06/2026");
    assert(d1 == d3);

    ostringstream oss;
    oss << d1;
    assert(oss.str() == "01/06/2026");
}