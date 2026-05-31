#include "menuitem.h"

using namespace std;

MenuItem::MenuItem(int idx, string name, function<void()> action) : item_index(idx),
                                                                       item_name(name), item_action(action) {}

int MenuItem::getIndex() const
{
    return item_index;
}

string MenuItem::getName() const
{
    return item_name;
}

void MenuItem::execute() const
{
    item_action();
}