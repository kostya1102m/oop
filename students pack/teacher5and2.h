#pragma once
#include "teacher.h"

class Teacher5 : public Teacher
{
public:
    void giveMark(shared_ptr<Student>& student) override;
};
class Teacher2 : public Teacher
{   
    void giveMark(shared_ptr<Student>& student) override;
};