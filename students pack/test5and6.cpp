#include "student.cpp"
#include "teacher.cpp"
#include "teacher5.cpp"
#include "lesson.cpp"
#include <iostream>
int main()
{

    vector<shared_ptr<Student>> students = { // создаем студентов
        make_shared<Student>("Вася"),
        make_shared<Student>("Петя"),
        make_shared<Student>("Вова"),
        make_shared<Student>("Никита"),
        make_shared<Student>("Жора"),
        make_shared<Student>("Влад"),

    };
    //инициализация урока и учителя который всегда выставляет 5
    Lesson l1;
    shared_ptr <Teacher5> t1 = make_shared<Teacher5>("Елена Петровна");
    l1.setTeacher(t1);
    //добавляем студентов в класс
    for (int i = 0; i< students.size();i++){
        l1.addStudents(students[i]);
    }

    // проводим урок и подводим итог
    l1.LessonStarts();
    for (int i = 0; i < students.size(); i++)
    {
        cout << students[i]->getName() << " получил за 1 урок:\n"<< endl;
        for (int j = 0; j < students[i]->getMarks().size(); j++)
        {
            cout << students[i]->getMarks()[j] << endl;
        }
    }
    cout << endl;

    //инициализация второго урока и учителя который всегда ставит 2
    Lesson l2;
    shared_ptr <Teacher2> t2 = make_shared<Teacher2>("Вера Сергеевна");
    l2.setTeacher(t2);
     for (int i = 0; i< students.size();i++){
        l2.addStudents(students[i]);
    }
    l2.LessonStarts();
    for (int i = 0; i < students.size(); i++)
    {
        cout << students[i]->getName() << " в сумме за 2 урока получил:\n"<< endl;
        for (int j = 0; j < students[i]->getMarks().size(); j++)
        {
            cout << students[i]->getMarks()[j] << endl;
        }
    }
    return 0;
}