#pragma once
#include <vector>
#include <algorithm>
#include <ctime>
#include <iostream>
#include <memory>
using namespace std;
class Student
{
private:
    string name;
    unsigned parents;// типо счетчик родителей, чтобы не было более двух
    vector<int> marks;
    bool GS = true;

public:
    unsigned getParentNumber();
    void addMarks(unsigned mark);

    vector<int> getMarks();
    
    string getName();

    bool Otlichnik();

    void GSorNot();

    Student(string n):name(n){};
};
