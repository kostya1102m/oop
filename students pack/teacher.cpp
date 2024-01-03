#include "teacher.h"
#include <iostream>

void Teacher::setMood(Mood m)
{
    this->mood = m;
}

Mood Teacher::getMood()
{
    return this->mood;
}

void Teacher::giveMark(shared_ptr<Student> &student)
{
    srand(time(0));
    short int mark;
    if (mood == Mood::Great && student->Otlichnik())
        mark = 5;
    else if (!student->Otlichnik() && mood == Mood::Good)
    {
        if (rand() % 2 == 0)
            mark = 3;
        else
            mark = 4;
    }
    else if (!student->Otlichnik() && mood == Mood::Great)
    {
        if (rand() % 2 == 0)
            mark = 4;
        else
            mark = 5;
    }
    else if (student->Otlichnik() && (mood == Mood::Good || mood == Mood::Terrible))
    {
        short int n = rand() % 3 == 0;
        mark = (n == 0) ? 3 : (n == 1 ? 4 : 5);
    }
    else
    {
        if (rand() % 2 == 0)
            mark = 2;
        else
            mark = 3;
    }

    student->addMarks(mark);
}

