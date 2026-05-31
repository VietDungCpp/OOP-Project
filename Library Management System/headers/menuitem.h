#ifndef MENUITEM_H
#define MENUITEM_H

#include <string>
#include <functional>

using namespace std;

class MenuItem
{
    private:
        int item_index;
        string item_name;
        function<void()> item_action;
    public:
        MenuItem(int, string, function<void()>);
        int getIndex() const;
        string getName() const;
        void execute() const;
};

#endif