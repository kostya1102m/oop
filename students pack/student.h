#pragma once
#include <vector>
#include <iostream>
using namespace std;
class Student
{
private:
    string name;
    void GreatStudent(); // отличник или нет

private:
    vector<int> marks;

    bool GS = true;

public:
    void addMarks(const int grade);

    vector<int> getMarks();

    bool Otlichnik();

    Student(string n):name(n){};
};
