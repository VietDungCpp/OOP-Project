#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <vector>
#include "author.h"

using namespace std;

class Book
{
    private:
        int book_id;
        string book_title, book_isbn;
        vector<Author*> authors; 
    public:
        Book(int, string, string);
        ~Book();

        int getID() const;
        string getTitle() const;
        string getISBN() const;
        vector<Author*> getAuthor() const;

        void addAuthor(Author*);
        void addAuthors(const vector<Author*>&);
        
        friend ostream& operator<<(ostream&, const Book&);
};

#endif