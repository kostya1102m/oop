#pragma once
#include "teacher.h"

class Teacher5 : public Teacher
{
public:
    void giveMark(std::shared_ptr<Student>& student) override;
};
class Teacher2 : public Teacher
{   
    void giveMark(std::shared_ptr<Student>& student) override;
};