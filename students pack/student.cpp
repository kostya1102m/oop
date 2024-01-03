#include "student.h"

void Student::addMarks(int mark)
{
    if (mark > 1 && mark < 6)
        marks.push_back(mark);
    else
        cout << " invalid mark\n";
}

vector<int> Student::getMarks()
{
    return marks;
}
string Student::getName()
{
    return name;
}

bool Student::Otlichnik()
{
    for (auto i : marks)
    {
        if (i != 5)
            GS = false;
            return GS;
    }
    GS = true;
    return GS;
}
void Student::GSorNot(){
    Otlichnik();
    if (GS == true)
        cout << this->getName() <<" учиться на отлично\n";
    else 
        cout << this->getName() <<" учиться не на отлично\n";
}
