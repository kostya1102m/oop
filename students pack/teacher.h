#pragma once
#include <vector>
#include <iostream>
#include <ctime>
#include "student.h"
#include <memory>

enum class Mood{
    Terrible,
    Good,
    Great
};

class Teacher
{
private:
    string name;
    Mood mood;
    
public:
    Teacher(string n):name(n){};

    Mood getMood();

    void giveMark(shared_ptr<Student>& student);

    void setMood(const Mood m);

};
