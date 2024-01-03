#include "student.cpp"
#include "teacher.cpp"
#include <iostream>
int main()
{
    Teacher t1("Любовь");
    //выставим настроение
    t1.setMood(Mood::Great);
    shared_ptr<Student> s3 = make_shared<Student>("Петя");
    t1.giveMark(s3);
    s3->addMarks(3);
    cout << s3->getName() << "'s marks:\t";
    for (int mark : s3->getMarks()) {
        cout << mark << " ";
    }
    cout << endl;
    s3->GSorNot();
    //поменяем настроение учителя и выдадим оценку Пете
    t1.setMood(Mood::Terrible);
    t1.giveMark(s3);
    cout << s3->getName() << "'s marks after mood Teacher's changing:\t";
    for (int mark : s3->getMarks()) {
        cout << mark << " ";
    }
    cout << endl;
    s3->GSorNot();
    return 0;

}