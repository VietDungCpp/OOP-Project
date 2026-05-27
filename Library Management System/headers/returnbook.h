#ifndef RETURNBOOK_H
#define RETURNBOOK_H

#include "date.h"
#include "hire.h"

class ReturnBook : public Hire
{
    private:
        Date return_date;
    public:
        ReturnBook() {};
        ReturnBook(int r_id, int b_id, Date d) : Hire(r_id, b_id), return_date(d) {}        

        Date getDate() const
        {
            return return_date;
        }
};

#endif