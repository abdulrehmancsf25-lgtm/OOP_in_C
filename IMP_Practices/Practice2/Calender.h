// BCSF25M_521
// ABDUL REHMAN ARSHAD 
#pragma once
class Calender
{
public:
    int month, day, year;
    Calender(); // Ctor

    ~Calender(); // Dtor
    int DayOfTheMonth(int D, int M, int Y);

    bool LeapYear(int Y = 0);

    int Number_of_Days_in_Month(int m, int y);

    void get_a_date();

    void printCalender(int d, int m, int y);

    void setUpCalander();
};