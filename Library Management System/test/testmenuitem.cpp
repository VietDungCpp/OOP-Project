#include "menuitem.h"
#include <iostream>
#include <functional>
#include "test.h"

using namespace std;

void printItem()
{
    cout << "hello";
}

void testMenuItem()
{
    function<void()> fn = printItem;
    MenuItem item1(1, "print", fn);
    item1.execute();

    MenuItem item2(2, "lambda", []() {
        cout << "lambda";
    });

    item2.execute();
}