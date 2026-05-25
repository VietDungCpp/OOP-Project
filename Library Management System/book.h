#ifndef BOOK_H
#define BOOK_H

#include <string>

using namespace std;

class Book
{
    private:
        int m_id;
        string m_title, m_author;
        bool m_available;
    public:
        Book();
        Book(int, string, string);

        void input();
        void display() const;

        int getID() const;
        string getTitle() const;
        bool isAvailable() const;

        void borrowBook();
        void returnBook();
};

#endif