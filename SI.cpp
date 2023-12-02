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
using namespace std;

class Human
{
public:
    string getName()
    {
        return name;
    }
    void setName(string _name)
    {
        name = _name;
    }

    int getAge()
    {
        return age;
    }
    void setAge(int _age)
    {
        age = _age;
    }


private:
  string name;
  short int age;
  
};
class Student : public Human
{
public:
    string getSchool(){
        return school;
    }
    void setSchool(string _school){
        school = _school;
    }
private:
    string school;
};
class Person
{
public:   
    string getCharacter(){
        return character;
    }
    void setCharacter(string _character){
        character = _character;
    }
private:
    string character;
};
int main()
{

}
