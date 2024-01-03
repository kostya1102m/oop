#include "parent.cpp"
class Meeting {
private:
    vector<shared_ptr<Parent>> parents;
    vector<shared_ptr<Teacher>> teachers;
    
public:
    void addParent(shared_ptr<Parent> parent) {
        parents.push_back(parent);
    }
    void addTeacher(shared_ptr<Teacher> teacher) {
        teachers.push_back(teacher);
    }

    void discussLessons() {
        for (auto parent : parents) {
            
        }
    }
};