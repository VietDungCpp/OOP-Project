#ifndef AUTHOR_H
#define AUTHOR_H

#include <string>

using namespace std;

class Author
{
    private:
        int author_id;
        string author_name;
    public:
        Author(int, string);
        ~Author();

        int getAuthorID() const;
        string getAuthorName() const;

        friend ostream& operator<<(ostream&, const Author&);
};

#endif