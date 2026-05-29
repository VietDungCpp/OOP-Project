#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <chrono>
#include <ctime>

using namespace std;
using namespace std::chrono;

class Date
{
    private:
        system_clock::time_point tp;
        unsigned int day, month;
        int year;
        
        void tp_to_date();
        void date_to_tp();
    public:
        Date();
        Date(const system_clock::time_point&);
        Date(const string&);
        Date(int, int, int);
        ~Date();

        void setDate(const string&);
        void setDate(const system_clock::time_point&);
        void setDate(int, int, int);

        const system_clock::time_point& getTimePoint() const;
        string getDateString() const;
        
        auto operator<=>(const Date&) const = default;

        friend ostream& operator<<(ostream&, const Date&);
        friend long long daysDiff(const Date&, const Date&);
};

#endif