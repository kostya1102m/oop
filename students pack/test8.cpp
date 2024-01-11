#include "meeting.cpp"
#include <iostream>
using namespace std;

int main()
{
    srand(time(0));
    vector<shared_ptr<Student>> s1 = {
        // создаем студентов
        make_shared<Student>("Вася"),
        make_shared<Student>("Петя"),
    };
    vector<shared_ptr<Student>> s2 = {
        make_shared<Student>("Вова"),
        make_shared<Student>("Никита"),
    };
    vector<shared_ptr<Student>> s3 = {
        make_shared<Student>("Жора"),
        make_shared<Student>("Роман"),
    };

    vector<shared_ptr<Parent>> parents = {
        make_shared<Parent>("1", s1),
        make_shared<Parent>("2",s2),
        make_shared<Grandparent>("3",s3)
        };

   
    vector<shared_ptr<Teacher>> teachers = {
        make_shared<Teacher>("Борис Трушин"),
        make_shared<Teacher>("Математик МГУ"),
        make_shared<Teacher>("Одиозный дед")
    };

    vector<shared_ptr<Lesson>> lessons = {
        make_shared<Lesson>(),
        make_shared<Lesson>(),
        make_shared<Lesson>()
    };
    for (int i = 0; i < s1.size(); i++)
    {
        lessons[0]->addStudents(s1[i]);
        lessons[0]->addStudents(s2[i]);
        lessons[0]->addStudents(s3[i]);
        lessons[1]->addStudents(s1[i]);
        lessons[1]->addStudents(s2[i]);
        lessons[1]->addStudents(s3[i]);
        lessons[2]->addStudents(s1[i]);
        lessons[2]->addStudents(s2[i]);
        lessons[2]->addStudents(s3[i]);
    }

    lessons[0]->setTeacher(teachers[0]);
    lessons[1]->setTeacher(teachers[1]);
    lessons[2]->setTeacher(teachers[2]);

    lessons[0]->LessonStarts();
    lessons[1]->LessonStarts();
    lessons[2]->LessonStarts();
    for (int i = 0; i < s1.size(); i++)
    {
        cout << s1[i]->getName() << " в сумме за 3 урока получил:\n"<< endl;
        for (int j = 0; j < s1[i]->getMarks().size(); j++)
        {
            cout << s1[i]->getMarks()[j] << endl;
        }
    }
    for (int i = 0; i < s2.size(); i++)
    {
        cout << s2[i]->getName() << " в сумме за 3 урока получил:\n"<< endl;
        for (int j = 0; j < s2[i]->getMarks().size(); j++)
        {
            cout << s2[i]->getMarks()[j] << endl;
        }
    }
    for (int i = 0; i < s3.size(); i++)
    {
        cout << s3[i]->getName() << " в сумме за 3 урока получил:\n"<< endl;
        for (int j = 0; j < s3[i]->getMarks().size(); j++)
        {
            cout << s3[i]->getMarks()[j] << endl;
        }
    }

    shared_ptr<Meeting> meeting = make_shared<Meeting>(lessons, teachers, parents);

    meeting->discussLessons(); 
    return 0;
}