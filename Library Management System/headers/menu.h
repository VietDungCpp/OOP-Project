#ifndef MENU_H
#define MENU_H

#include <string>
#include "menuitem.h"

using namespace std;

class Menu
{
    private:
        string title;
        vector<MenuItem*> items;
    public:
        Menu(string);
        ~Menu();

        void addItem(MenuItem*);
        int show() const;
        void run() const;
    private:
        static int inputChoice(const string&);
};

#endif