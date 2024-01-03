#include "teacher5and2.h"

void Teacher5::giveMark(shared_ptr<Student> &student)
{
    student->addMarks(5);
}
void Teacher2::giveMark(shared_ptr<Student> &student)
{
    student->addMarks(2);
}
