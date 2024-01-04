#include "parent.cpp"
class Meeting
{
private:
    vector<shared_ptr<Parent>> parents;
    vector<shared_ptr<Teacher>> teachers;
    vector<shared_ptr<Lesson>> lessons;

public:
    void addLessonToDiscuss(shared_ptr<Lesson> lesson)
    {
        lessons.push_back(lesson);
    }
    void addParent(shared_ptr<Parent> parent)
    {
        parents.push_back(parent);
    }
    void addTeacher(shared_ptr<Teacher> teacher)
    {
        teachers.push_back(teacher);
    }

    void discussLessons()
    {
        for (int k = 0; k < lessons.size(); k++)
        {
            cout << "Обсуждение про " << k << " -ое занятие,";
            cout << "проведенное " << lessons[k]->getTeacher()->getName() << endl;
            for (int i = 0; i < parents.size(); i++)
            {
                for (int j = 0; j < parents[i]->getChild().size(); j++)
                {
                    if (parents[i]->getChild()[j]->getMarks().size() != 0) //кто получил оценки
                    {
                        if (parents[i]->getChild()[j]->Otlichnik())
                        {
                            cout << parents[i]->getChild()[j]->getName() << " красава\n";
                        }
                        else
                            cout << parents[i]->getChild()[j]->getName() << " балбесина\n";
                    }
                }
            }
        }
    }
};