#pragma once
#include <vector>
#include <iostream>
#include <ctime>
#include "student.h"
#include <memory>

enum class Mood
{
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
    Teacher(string n) : name(n)
    {
        srand(time(0));
        mood = static_cast<Mood>(rand() % 3);
    };

    Mood getMood();

    virtual void giveMark(shared_ptr<Student> &student);

    void setMood(Mood m);
};
