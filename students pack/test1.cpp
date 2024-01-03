#include "student.cpp"
#include <iostream>
int main()
{
    Student s1("Петр");
    s1.addMarks(5);
    s1.addMarks(5);
    s1.addMarks(5);
    s1.addMarks(5);
    s1.GSorNot();

    Student s2("Маша");
    s2.addMarks(5);
    s2.addMarks(4);
    s2.addMarks(4);
    s2.addMarks(4);
    s2.GSorNot();

    return 0;

}
