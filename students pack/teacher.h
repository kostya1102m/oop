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
enum class Classes{
    
};

class Teacher
{
protected:
    string name;
    Mood mood;
    unsigned markcount;//для смены настроения

public:
    Teacher(string n) : name(n)
    {
        srand(time(0));
        mood = static_cast<Mood>(rand() % 3);
        markcount = 0;
    };

    Mood getMood();

    virtual void giveMark(shared_ptr<Student> &student);

    unsigned getMarkcount();

    string getName();

    void setMood(Mood m);
};