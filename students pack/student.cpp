#include "student.h"


void Student::addMarks(const int mark) // получить оценку
{
    if (mark > 1 && mark < 6)
        marks.push_back(mark);
    else cout <<" invalid mark\n";
}

vector<int> Student::getMarks()
{
    return marks;
}

bool Student::Otlichnik()
{
    GreatStudent();
    if (GS == true) 
        cout << this->name <<" Учиться на отлично\n";
    else cout << this->name << " Учитсья не на отлично\n";
    return GS;
}

void Student::GreatStudent()
{
    for (auto i : marks)
    {
        if (i != 5)
        {
            GS = false;
            return;
        }
    }
    GS = true;
}
