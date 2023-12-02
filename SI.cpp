/* Реализовать класс Human. Создать несколько объектов класса Human;
Добавить несколько свойств (не забывать добавить значимые поля в конструктор);
Добавить getter'ы и setter'ы для созданных полей;
Реализовать дочерний класс к Human. Например, Student, Character и др;
Продемонстрировать обращение к свойствам объектов дочерних и родительских классов;
Добавить несколько наследников от различных родителей (сделать дерево из минимум из 5 классов);
Поэкспериментировать с множественным наследованием;
Поэкспериментировать с абстрактными классами/интерфейсами.

Каждый шаг фиксировать с помощью коммитов! */
#include <iostream>
#include <string>
using namespace std;

class Human
{
private:
    string name;
    short int age;
public:
    Human(string n, int a) : name(n), age(a){};

    void setName(string n)
    {
        name = n;
    }
    string getName()
    {
        return name;
    }
    void setAge(short int a)
    {
        age = a;
    }
    int getAge()
    {
        return age;
    }
};
class Student : public Human
{
private:
    string school;
public:
    Student(string n, int a, string s) : Human(n, a), school(s){};
    string getSchool()
    {
        return school;
    }
    void setSchool(string _school)
    {
        this->school = _school;
    }
    virtual void goesToSchool(){
        cout << getName()<< " учится в " << getSchool() << endl;
    }
};
class Person
{
private:
    string character;
public:
    Person(string c):character(c){}
    string getCharacter()
    {
        return character;
    }
    void setCharacter(string _character)
    {
        character = _character;
    }
    virtual void doHobby() = 0;
};
class ToughGuy : public Student, public Person
{
public:
    ToughGuy(string n, int a, string s, string c):Student(n,a,s), Person(c){}
    void fighteverybody(){
        cout << getName() << " дерётся со всеми\n";
    }
    void doHobby () override
    {
        cout << getName() << " играет в футбол\n";
    }
    void goesToSchool() override
    {
        cout << "Ничего не делает и не ходит в уник\n";
    }
};
int main()
{
    Human s1("Попов Роман",19);
    Student s2 ("Александр",25,"ВИ-ШРМИ");
    s2.goesToSchool();
    ToughGuy t("Иван",20,"ИМКТ","Скромняга");
    cout << t.getName() << " - "<<t.getCharacter() << endl;
    t.goesToSchool();
    t.fighteverybody();
    t.doHobby();

}
