#pragma once
#include <vector>
#include <iostream>
using namespace std;
class Student
{
private:
    string name;
    unsigned parents;// типо счетчик родителей, чтобы не было более двух
    vector<int> marks;
    bool GS = true;

public:
    unsigned getParent();
    void addMarks(unsigned mark);

    vector<int> getMarks();
    
    string getName();

    bool Otlichnik();

    void GSorNot();
    
    bool getGS();

    Student(string n):name(n){};
};
