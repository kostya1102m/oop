#include "teacher.h"
#include <iostream>

void Teacher::setMood(Mood m)
{
    mood = m;
}

Mood Teacher::getMood()
{
    return mood;
}
string Teacher::getName(){
    return name;
}
unsigned Teacher::getMarkcount()
{
    return markcount;
}
void Teacher::giveMark(shared_ptr<Student> &student)
{
    srand(time(0));
    unsigned mark;
    if (markcount == 5)
    {
        mood = static_cast<Mood>(rand() % 3);
    }
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
        short int num = rand() % 3 == 0;
        mark = (num == 0) ? 3 : (num == 1 ? 4 : 5);
    }
    else
    {
        if (rand() % 2 == 0)
            mark = 2;
        else
            mark = 3;
    }
    markcount++;
    student->addMarks(mark);
}
