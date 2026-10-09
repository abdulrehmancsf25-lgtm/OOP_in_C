// BCSF25M_521
// ABDUL REHMAN ARSHAD 
#include "Calender.h"
#include "ConsoleFunctions.h"
#include <iostream>
#include <iomanip>
using namespace std;

ConsoleFunctions cfunc; // object of Console Functions Class

Calender::Calender() : day(1), month(1), year(1900)
{ // Ctor // our min  date
}

Calender::~Calender() {} // Dtor
int Calender :: DayOfTheMonth(int D, int M, int Y)
{
    int y = Y - (14 - M) / 12;
    int x = y + y / 4 - y / 100 + y / 400;
    int m = M + 12 * ((14 - M) / 12) - 2;
    int d = (D + x + (31 * m) / 12) % 7;
    return d;
}

bool Calender::LeapYear(int Y)
{
    if (Y % 4 == 0)
    {
        if (Y % 100 == 0)
        {
            if (Y % 400 == 0)
                return true;
            return false;
        }
        else
            return true;
    }
    else
        return false;
}

int Calender::Number_of_Days_in_Month(int m, int y)
{
    if (m < 1 || m > 12)
        return 0;
    if (m <= 7)
    {
        if (m & 1)
            return 31;
        if (m == 2)
        {
            if (LeapYear(y))
                return 29;
            return 28;
        }
        return 30;
    }
    else if (m > 7)
    {
        if (m & 1)
            return 30;
        return 31;
    }
    return -1;
}
void Calender::get_a_date()
{
    int d, m, y;
    cout << "Enter Year : ";
    cin >> y;
    while (y < 1900 || y > 2099)
    {
        cout << "Enter year again(1900-2099) : ";
        cin >> y;
    }
    this->year = y;
    cout << "Enter month : ";
    cin >> m;
    while (m < 1 || m > 12)
    {
        cout << "Enter month again(1-12) : ";
        cin >> m;
    }
    this->month = m;
    cout << "Enter day : ";
    cin >> d;

    while (d < 1 || d > Number_of_Days_in_Month(m, y))
    {
        cout << "Enter day again in range(" << Number_of_Days_in_Month(m, y) << ") : ";
        cin >> d;
    }
    this->day = d;
}

void Calender::printCalender(int d, int m, int y)
{
    string arr[12] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"};

    cout << "    " << arr[m - 1] << " " << y << endl;
    cout << " S " << " M " << "TU " << " W " << "TH " << " F " << " S " << endl;

    // no of days in that month
    int total_days = Number_of_Days_in_Month(m, y);
    int start_day = DayOfTheMonth(1, m, y);
    int cnt = start_day + 1;
    for (int i = 0; i < start_day * 3; i++)
        cout << ' ';

    for (int i = 1; i <= total_days; i++)
    {
        if (cnt == 8)
        {
            cout << endl;
            cnt = 1;
        }
        if (i == d)
            cout << "\033[31m" << right << setw(2) << i << ' ' << "\033[0m";
        else
            cout << right << setw(2) << i << ' ';
        cnt++;
    }
} // print calender

void Calender::setUpCalander()
{ // CHECKS  APPLIED  FOR  DAY VALIDATION IF IT IS 30 ,31 , 28 OR 29 OF FEB
    get_a_date();
    printCalender(day, month, year);

    //---eboard Key Press event
    while (1)
    {
        cfunc.DetectEvent();
        char c;
        if (cfunc.IsKeyPressEvent(c))
        {
            if (c == 'D' || c == 'd') // Next Month
            {
                if (this->month == 12)
                {
                    this->month = 1;
                    this->year++;
                }
                else
                {
                    this->month++;
                }

                // Check  30, 31 in new month
                int days_in_month = Number_of_Days_in_Month(this->month, this->year);
                if (this->day > days_in_month)
                    this->day = days_in_month;

                cout << endl;
                printCalender(this->day, this->month, this->year);
            }
            else if (c == 'A' || c == 'a') // Previous Month
            {
                if (this->month == 1)
                {
                    this->month = 12;
                    this->year--;
                }
                else
                {
                    this->month--;
                }

                // Check  30, 31 in the previous month
                int days_in_month = Number_of_Days_in_Month(this->month, this->year);
                if (this->day > days_in_month)
                    this->day = days_in_month;

                cout << endl;
                printCalender(this->day, this->month, this->year);
            }
            else if (c == 'W' || c == 'w') // Next Year
            {
                if (this->year < 2099)
                {
                    this->year++;
                    // for leap year
                    if (this->month == 2 && this->day == 29 && !LeapYear(this->year))
                    {
                        this->day = 28;
                    }
                }
                cout << endl;
                printCalender(this->day, this->month, this->year);
            }
            else if (c == 'S' || c == 's') // Previous Year
            {
                if (this->year > 1900)
                {
                    this->year--;
                    // Leap year for FEB
                    if (this->month == 2 && this->day == 29 && !LeapYear(this->year))
                    {
                        this->day = 28;
                    }
                }
                cout << endl;
                printCalender(this->day, this->month, this->year);
            }
            else
            {
                // any other key pressed
                break;
            }
        }
    }
}
