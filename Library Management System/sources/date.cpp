#include <iostream>
#include <ctime>
#include <sstream>
#include <chrono>
#include <iomanip>
#include <stdexcept>
#include "date.h"

using namespace std;
using namespace std::chrono;

void Date::tp_to_date()
{
    sys_days sd = floor<days>(tp);
    year_month_day ymd{sd};

    year = static_cast<int>(ymd.year());
    month = static_cast<unsigned>(ymd.month());
    day = static_cast<unsigned>(ymd.day());
}

void Date::date_to_tp()
{
    year_month_day ymd {
        chrono::year{year},
        chrono::month{month},
        chrono::day{day}
    };

    if (!ymd.ok())
    {
        throw invalid_argument("Invalid date: " + getDate());
    }

    tp = sys_days(ymd);
}

Date::Date() : tp(system_clock::now())
{
    tp_to_date();
}

Date::Date(const system_clock::time_point& t) : tp(t)
{
    tp_to_date();
}

Date::Date(const string& s)
{
    setDate(s);
}

Date::Date(int d, int m, int y)
{
    setDate(d, m, y);
}

Date::~Date() {}

void Date::setDate(const string& s)
{
    unsigned int d, m;
    int y;
    char slash1, slash2;

    istringstream iss(s);
    iss >> d >> slash1 >> m >> slash2 >> y;

    if (iss.fail() || slash1 != '/' || slash2 != '/')
    {
        throw invalid_argument("Date string must be DD/MM/YYYY, entered: " + s);
    }

    day = static_cast<int>(d);
    month = static_cast<int>(m);
    year = y;

    date_to_tp();
}

void Date::setDate(const system_clock::time_point& t)
{
    tp = t;
    tp_to_date();
}

void Date::setDate(int d, int m, int y)
{
    day = d;
    month = m;
    year = y;
    date_to_tp();
}

const system_clock::time_point& Date::getTimePoint() const
{
    return tp;
}

string Date::getDate() const
{
    ostringstream oss;
    oss << setw(2) << setfill('0') << day << '/'
        << setw(2) << setfill('0') << month << '/'
        << year;
    return oss.str();
}

ostream& operator<<(ostream& os, const Date& d)
{
    os << d.getDate();
    return os;
}

long long daysDiff(const Date& d1, const Date& d2)
{
    return duration_cast<chrono::days>(d2.tp - d1.tp).count();
}