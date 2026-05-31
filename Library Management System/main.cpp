#include "librarymenu.h"

int main()
{
    Library lib;
    LibraryMenu controller(lib);

    controller.run();
}