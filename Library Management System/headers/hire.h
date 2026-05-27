#ifndef HIRE_H
#define HIRE_H

class Hire
{
    protected:
        int reader_id;
        int book_id;
    public:
        Hire() {};
        Hire(int r_id, int b_id) : reader_id(r_id), book_id(b_id) {}

        int getBookID() const
        {
            return book_id;
        }

        int getReaderID() const
        {
            return reader_id;
        }
};

#endif