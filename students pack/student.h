#pragma once
#include <vector>
#include <iostream>
using namespace std;
class Student
{
private:
    string name;

private:
    vector<int> marks;

    bool GS = true;

public:
    void addMarks(int mark);

    vector<int> getMarks();
    
    string getName();

    bool Otlichnik();

    void GSorNot();

    Student(string n):name(n){};
};
