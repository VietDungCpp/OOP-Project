#ifndef BORROW_H
#define BORROW_H

#include "hire.h"
#include "date.h"

class Borrow : public Hire
{
    private:
        Date borrow_date;
    public:
        Borrow() {}
        Borrow(int r_id, int b_id, Date d) : Hire(r_id, b_id), borrow_date(d) {}
        
        Date getDate() const
        {
            return borrow_date;
        }
};

#endif