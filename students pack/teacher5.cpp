#include "teacher5and2.h"
// Пусть у учителей которые всегда выставляют 5 и 2 настроения меняются по разному
void Teacher5::giveMark(shared_ptr<Student> &student) 
{
    student->addMarks(5);
    markcount++;
    if (this->markcount == 2){
        this->setMood((Mood)(rand() % 3));
    }
}
void Teacher2::giveMark(shared_ptr<Student> &student)
{
    student->addMarks(2);
    markcount++;
    if (this->markcount == 8){
         this->setMood((Mood)(rand() % 3));
    }
}
