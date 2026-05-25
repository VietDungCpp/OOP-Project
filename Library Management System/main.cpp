#include <iostream>
#include "library.h"

using namespace std;

int main()
{
    Library lib;

    int ch;

    do
    {
        cout << "\n===== LIBRARY MENU =====\n";

        cout << "0. Exit\n";
        cout << "1. Add Book\n";
        cout << "2. Show Books\n";
        cout << "3. Search Book\n";
        cout << "4. Borrow Book\n";
        cout << "5. Return Book\n";

        cout << "Enter choice: ";
        cin >> ch;

        switch (ch)
        {
            case 0:
                cout << "Goodbye\n";
                break;
            case 1:
                lib.addBook();
                break;
            case 2:
                lib.showBooks();
                break;
            case 3:
                lib.searchBookbyTitle();
                break;
            case 4:
                lib.borrowBook();
                break;
            case 5:
                lib.returnBook();
                break;
            default:
                cout << "Invalid choice\n";
        }
        
    } while (ch != 0);   
}