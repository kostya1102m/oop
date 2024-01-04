#include "teacher.h"
class Lesson {
private:
    vector<shared_ptr<Student>> students;
    shared_ptr<Teacher> teacher;

public:
    void addStudents(shared_ptr<Student> student) {
        students.push_back(student);
    }

    void setTeacher(shared_ptr<Teacher> teacher) {
        this->teacher = teacher;
    }
    shared_ptr<Teacher> getTeacher(){
        return teacher;
    }
    void LessonStarts() { 
         srand(time(0));
        for (auto student : students) {
            int studindex = rand() % students.size() + 1; //рандомно раздаем оценки
            teacher->giveMark(students[studindex]);
        }
    }   
};
