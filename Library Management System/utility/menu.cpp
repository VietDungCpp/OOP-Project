#include "menu.h"
#include <iostream>
#include <string>
#include <limits>

using namespace std;

int Menu::inputChoice(const string& s)
{
    int val;
    while (true)
    {
        cout << s;
        cin >> val;

        if (cin.good())
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return val;
        }

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "  Invalid input, please enter a number.\n";   
    }
}

Menu::Menu(string t) : title(t) {}

Menu::~Menu()
{
    for (MenuItem* item : items)
    {
        delete item;
    }
}

void Menu::addItem(MenuItem* item)
{
    items.push_back(item);
}

int Menu::show() const
{
    cout << "\n====== " << title << " ======\n";
    cout << "  0. Back / Exit\n";
    for (const MenuItem* item : items)
    {
        cout << "  " << item->getIndex() << ". " << item->getName() << '\n';
    }
    
    int choice = inputChoice("  Choice: ");

    for (const MenuItem* item : items)
    {
        if (item->getIndex() == choice)
        {
            item->execute();
            return choice;
        }
    }

    if (choice != 0)
    {
        cout << "  Unknown option.\n";
    }

    return choice;
}

void Menu::run() const
{
    while (show() != 0);
}