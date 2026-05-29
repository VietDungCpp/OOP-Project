#include "menuitem.h"

using namespace std;

MenuItem::MenuItem(int number, string name, function<void()> action) : item_number(number), item_name(name), item_action(action) {}

int MenuItem::getNumber() const
{
    return item_number;
}

string MenuItem::getName() const
{
    return item_name;
}

void MenuItem::execute() const
{
    item_action();
}