#include "parent.cpp"
#include "lesson.cpp"
class Meeting
{
private:
    vector<shared_ptr<Parent>> parents;
    vector<shared_ptr<Teacher>> teachers;
    vector<shared_ptr<Lesson>> lessons;
    vector<shared_ptr<Student>> LostStudents;

public:
    Meeting(vector<shared_ptr<Lesson>> &l, vector<shared_ptr<Teacher>> &t, vector<shared_ptr<Parent>> &p) : lessons(l), teachers(t), parents(p) {}

    shared_ptr<Parent> StudentsParent(shared_ptr<Student> student)
    {
        for (int i = 0; i < parents.size(); i++)
        {
            if (find(parents[i]->getChild().begin(), parents[i]->getChild().end(), student) != parents[i]->getChild().end())
            {
                return parents[i];
            }
        }
        return nullptr;
    }
    void ListOfLostStudents()
    {
        cout << "Список тех студентов, чьи родители отстутстовали на собрании:\n";
        for (int i = 0; i < LostStudents.size(); i++)
        {
            cout << LostStudents[i]->getName() << endl;
        }
    }
    void discussLessons()
    {
        for (int k = 0; k < lessons.size(); k++)
        {

            cout << "Обсуждение про " << k + 1 << " -ое занятие";
            if (find(teachers.begin(), teachers.end(), lessons[k]->getTeacher()) == teachers.end())
                cout << "Учитель " << k + 1 << "-го занятия отствутствует на собрании\n";

            else
            {
                cout << " которое провел - " << lessons[k]->getTeacher()->getName() << endl;
                for (int j = 0; j < lessons[k]->getStudents().size(); j++)
                {
                    if (lessons[k]->getStudents()[j]->getMarks().empty())
                        cout << lessons[k]->getStudents()[j]->getName() << " не получил оценок за " << k + 1 << " урок\n";

                    else
                    {
                        shared_ptr<Parent> p = StudentsParent(lessons[k]->getStudents()[j]);
                        if (p == nullptr)
                        {
                            if (find(LostStudents.begin(), LostStudents.end(), lessons[k]->getStudents()[j]) == LostStudents.end())
                                LostStudents.push_back(lessons[k]->getStudents()[j]);
                        }
                        else
                            p->tellAboutOwnSpecificChild(lessons[k]->getStudents()[j]);
                    }
                }
            }
        }
        cout << endl;
        ListOfLostStudents();
    }
};
