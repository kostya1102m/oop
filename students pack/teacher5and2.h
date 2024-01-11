#pragma once
#include "teacher.h"

class Teacher5 : public Teacher
{
private:
    unsigned markcount;

public:
    Teacher5(string n) : Teacher(n)
    {
        this->markcount = 0;
    }

    void giveMark(shared_ptr<Student> &student) override;
};
class Teacher2 : public Teacher
{
private:
    unsigned markcount;
public:
    Teacher2(string n) : Teacher(n)
    {
        this->markcount = 0;
    }
    void giveMark(shared_ptr<Student> &student) override;
};
