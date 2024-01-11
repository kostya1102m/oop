#include "teacher.h"
#include <algorithm>
class Lesson
{
private:
    vector<shared_ptr<Student>> students;
    shared_ptr<Teacher> teacher;

public:
    void addStudents(shared_ptr<Student> student)
    {
        students.push_back(student);
    }

    void setTeacher(shared_ptr<Teacher> _teacher)
    {
        teacher = _teacher;
    }
    shared_ptr<Teacher> getTeacher()
    {
        return teacher;
    }

    vector<shared_ptr<Student>> getStudents()
    {
        return students;
    }
    void LessonStarts()
{
    if (!students.empty())
    {
        srand(time(0));
        short numStudentsToMark = rand() % students.size();

        std::random_shuffle(students.begin(), students.end());

        if (teacher != nullptr) {
            for (int i = 0; i < numStudentsToMark; i++)
            {
                teacher->giveMark(students[i]);
            }
        }
         else
            cout << "Учителя нет\n";
    }
}
};
