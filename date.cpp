#include <iostream>
#include <tuple>
using namespace std;
class Date
{
protected:
    void setYear(int y)
    {
        try
        {
            if (y >= 0)
                this->year = y;
            else
                throw invalid_argument("Не верное значение года");
        }
        catch (invalid_argument &e)
        {
            cout << e.what() << endl;
        }
    }
    void setMonth(int m)
    {
        try
        {
            if (m >= 1 && m <= 12)
                this->month = m;
            else
                throw invalid_argument("Не верное значение месяца");
        }
        catch (invalid_argument &e)
        {
            cout << e.what() << endl;
        }
    }
    void setDay(int d)
    {
        try
        {
            if (d >= 1 && d <= 31)
            {
                if (VisOrNot(this->year) && this->month == 2 && d == 28)
                    throw invalid_argument("Год високосный, а дней меньше");
                else
                    this->day = d;
            }
            else
                throw invalid_argument("Не верное значение дня");
        }
        catch (invalid_argument &e)
        {
            cout << e.what() << endl;
        }
    }
    void setHour(int h)
    {
        try
        {
            if (h >= 0 && h <= 23)
                this->hour = h;
            else
                throw invalid_argument("Не верное значение часа");
        }
        catch (invalid_argument &e)
        {
            cout << e.what() << endl;
        }
    }
    void setMinute(int min)
    {
        try
        {
            if (min >= 0 && min <= 59)
                this->minute = min;
            else
                throw invalid_argument("Не верное значение минуты");
        }
        catch (invalid_argument &e)
        {
            cout << e.what() << endl;
        }
    }
    void setSecond(int sec)
    {
        try
        {
            if (sec >= 0 && sec <= 59)
                this->second = sec;
            else
                throw invalid_argument("Не верное значение секунды");
        }
        catch (invalid_argument &e)
        {
            cout << e.what() << endl;
        }
    }

private:
    int year, month, day, hour, minute, second;
    bool IsOurEra;
    bool VisOrNot(int y)
    {
        if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0))
            return true;
        return false;
    }
    int daysInMonth(int month, int year)
    {
        if (month == 2)
        {
            if (VisOrNot(year))
                return 29;
            else
                return 28;
        }
        else if (month == 4 || month == 6 || month == 9 || month == 11)
            return 30; // апр июнь сен нояб
        else
            return 31; // янв март май июль авг окт дек
    }

public:
    Date()
    {
        year = 1960;
        month = 1;
        day = 1;
        hour = 0;
        minute = 0;
        second = 0;
        IsOurEra = true;
    }
    Date(int y, int m, int d, int h, int min, int sec, bool era) : IsOurEra(era)
    {
        setYear(y);
        setMonth(m);
        setDay(d);
        setHour(h);
        setMinute(min);
        setSecond(sec);
    }

    Date &add(int y, int m, int d, int h, int min, int sec)
    {
        if (IsOurEra == true)
            year += y;
        else
            year -= y;
        month += m;
        day += d;
        hour += h;
        minute += min;
        second += sec;
        while (year < 0 || month > 12 || day > daysInMonth(month, year) || hour > 24 || minute >= 60 || second >= 60)
        {
            if (year < 0)
            {
                year = abs(year);
                IsOurEra = true;
            }
            if (month > 12)
            {
                year += month / 12;
                month %= 12;
            }
            if (day > daysInMonth(month, year))
            {
                month += day / daysInMonth(month, year);
                day %= daysInMonth(month, year);
            }
            if (hour > 24)
            {
                day += hour / 24;
                hour %= 24;
            }
            if (minute >= 60)
            {
                hour += minute / 60;
                minute %= 60;
            }
            if (second >= 60)
            {
                minute += second / 60;
                second %= 60;
            }
        }
        return *this;
    }
    Date &subtract(int y, int m, int d, int h, int min, int sec)
    {
        if (IsOurEra == false)
            year += y;
        else
            year -= y;
        month -= m;
        day -= d;
        hour -= h;
        minute -= min;
        second -= sec;
        while (year < 0 || month < 0 || day < 0 || hour < 0 || minute < 0 || second < 0)
        {
            if (year < 0)
            {
                year = abs(year);
                IsOurEra = false;
            }
            if (month < 1)
            {
                year -= abs(month / 12) + 1;
                month = 12 - abs(month % 12);
            }
            if (day < 1)
            {
                month -= abs(day / daysInMonth(month, year)) + 1;
                day = daysInMonth(month, year) - abs(day % daysInMonth(month, year));
            }
            if (hour < 0)
            {
                day -= abs(hour / 24) + 1;
                hour = 24 - abs(hour % 24);
            }
            if (minute < 0)
            {
                hour -= abs(minute / 60) + 1;
                minute = 60 - abs(minute % 60);
            }
            if (second < 0)
            {
                minute -= abs(second / 60) + 1;
                second = 60 - abs(second % 60);
            }
        }
        return *this;
    }

public:
    bool operator>(const Date &other)
    {
        if (IsOurEra == other.IsOurEra && IsOurEra)
            return tie(year, month, day, hour, minute, second) > tie(other.year, other.month, other.day, other.hour, other.minute, other.second);
        else if (IsOurEra == other.IsOurEra)
            return tie(year, month, day, hour, minute, second) < tie(other.year, other.month, other.day, other.hour, other.minute, other.second);
        else
            return IsOurEra;
    }
    bool operator<(const Date &other)
    {
        if (*this > other || *this == other)
            return false;
        return true;
    }
    bool operator==(const Date &other)
    {
        return tie(year, month, day, hour, minute, second, IsOurEra) == tie(other.year, other.month, other.day, other.hour, other.minute, other.second, IsOurEra);
    }
    Date operator=(const Date &other)
    {
        tie(year, month, day, hour, minute, second, IsOurEra) =
            tie(other.year, other.month, other.day, other.hour, other.minute, other.second, other.IsOurEra);
        return *this;
    }
    Date &operator+=(const Date &other)
    {
        *this = *this + other;
        return *this;
    }
    Date &operator-=(const Date &other)
    {
        *this = *this - other;
        return *this;
    }
    Date operator+(const Date &other)
    {
        Date result = *this;
        result.add(other.year, other.month, other.day, other.hour, other.minute, other.second);
        return result;
    }
    Date operator-(const Date &other)
    {
        Date result = *this;
        result.subtract(other.year, other.month, other.day, other.hour, other.minute, other.second);
        return result;
    }
    friend ostream &operator<<(ostream &os, const Date &date)
    {
        os << date.year << " год " << date.month << " " << date.day << " " << date.hour << ":" << date.minute << ":" << date.second;
        if (date.year == 0 && date.month == 0 && date.day == 0 && date.hour == 0 && date.minute == 0 && date.second == 0)
            os << " - Точка отсчёта";
        if (date.IsOurEra)
            os << " Нашей эры";
        else
            os << " До нашей эры";
        return os;
    }
};
int main()
{
    Date d1;
    Date dh(100,1,1,0,0,0,1);
    Date d2 = d1.subtract(1960, 1, 1, 0, 0, 0);
    cout << "d2 = " << d2 << endl;
    Date d3(d2);
    d3.add(1, 0, 0, 0, 0, 0);
    d3.subtract(1, 0, 0, 0, 0, 0);
    cout << "d3 = " << d3 << endl;
    Date d4 = d3 + d2;
    cout << "d4 = " << d4 << endl;
    Date dl(1, 1, 1, 1, 1, 1, 1);
    Date d5 = d2 - d2 - d3 + dl;
    cout << d5 << endl;
    Date d6 = d5 - d5 + d5;
    cout << d6 << endl;
    d6-=d5;
    cout << d6 << endl;
    return 0;
}
