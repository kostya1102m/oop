#include "student.cpp"
#include "teacher.cpp"
class Parent
{
private:
    string name;
    vector<shared_ptr<Student>> Children;
    Mood parentmood;
    unsigned parents;

public:
    Parent() {}
    Parent(string n, vector<shared_ptr<Student>> children) : name(n), Children(children)
    {
        srand(time(0));
        parentmood = static_cast<Mood>(rand() % 3);
    }
     vector<shared_ptr<Student>> getChild()
    {
        return Children;
    }
    Mood getparentmood()
    {
        return parentmood;
    }
    unsigned getparents()
    {
        return parents;
    }
    virtual bool ChildrenNumberCheck()
    {
        if (this->Children.empty())
        {
            cout << "У этого родителя нет детей\n";
            return false;
        }
        else
            return true;
    }

    bool areChildrenExcellent()
    {
        bool otl = true;
        if (ChildrenNumberCheck())
        {
            for (int i = 0; i < this->Children.size(); i++)
                otl = Children[i]->Otlichnik() || otl;

            if (otl == true)
                return true;
            else
                return false;
        }
    }
    virtual void addChild(shared_ptr<Student> child)
    {
        this->Children.push_back(child);
        if (child->getParentNumber() > 2)
        {
            this->Children.pop_back();
            cout << "У ребенка не может быть больше 2 родителей\n";
        }
    }
    void tellAboutChildrenInGeneral()
    {
        if (ChildrenNumberCheck())
        {
            if (areChildrenExcellent())
            {
                switch (parentmood)
                {
                case Mood::Great:
                    std::cout << "О таких детях можно только мечтать\n";
                    break;
                case Mood::Good:
                    std::cout << "Я горжусь ими\n";
                    break;
                case Mood::Terrible:
                    std::cout << "Хоть у меня и ужасное настроение, но надо признать что они гении\n";
                    break;

                default:
                    break;
                }
            }
            else
            {
                switch (parentmood)
                {
                case Mood::Great:
                    std::cout << "У них огромный потенциал\n";
                    break;
                case Mood::Good:
                    std::cout << "Они все равно молодцы\n";
                    break;
                case Mood::Terrible:
                    std::cout << "Это просто кошмар, а не дети!\n";
                    break;

                default:
                    break;
                }
            }
        }
    }
    virtual void tellAboutOwnAllChildren()
    {
        if (ChildrenNumberCheck())
        {
            for (int i = 0; i < Children.size(); i++)
                tellAboutOwnSpecificChild(Children[i]);
        }
    }
    virtual void tellAboutOwnRandomChild()
    {
        if (ChildrenNumberCheck())
        {
            short childindex = rand() % Children.size();
            tellAboutOwnSpecificChild(Children[childindex]);
        }
    }

    virtual void tellAboutOwnSpecificChild(shared_ptr<Student> child)
    {
        if (parentmood == Mood::Great)
        {
            if (child->Otlichnik())
                cout << child->getName() << " молодец, я очень сильно люблю этого ребенка\n";
            else
                cout << child->getName() << " старается, этому ребенку есть куда расти\n";
        }
        else if (parentmood == Mood::Good)
        {

            if (child->Otlichnik())
                cout << child->getName() << " хорошо справляется с поставленными задачами\n";
            else
                cout << child->getName() << " ленится и не может ответственно подойти к учебе\n";
        }
        else
        {
            if (child->Otlichnik())
                cout << child->getName() << " не может полностью раскрыть свой потенциал\n";
            else
                cout << child->getName() << " - это потеря потерь\n";
        }
    } 
};

class Grandparent : public Parent
{
private:
    string name;
    vector<shared_ptr<Student>> Grandchildren;
    Mood grandparentmood;

public:
    Grandparent() {}
    Grandparent(string n, vector<shared_ptr<Student>> grandchildren) : Parent(n, grandchildren)
    {
        srand(time(0));
        grandparentmood = static_cast<Mood>(rand() % 3);
    }
    void addChild(shared_ptr<Student> child) override
    {
        this->Grandchildren.push_back(child); // предположим, что у внука может быть неограниченное количество бабушек, дедушек
    }                                         // но родителя максимум два
    bool ChildrenNumberCheck() override
    {
        if (this->Grandchildren.empty())
        {
            cout << "У старика нет внуков\n";
            return false;
        }
        else
            return true;
    }
    void tellAboutOwnAllChildren() override
    {
        if (ChildrenNumberCheck())
            cout << "Мои внуки самые лучшие!!!!\n";
    }
    void tellAboutOwnRandomChild() override
    {
        if (ChildrenNumberCheck())
        {
            short childindex = rand() % Grandchildren.size();
            tellAboutOwnSpecificChild(Grandchildren[childindex]);
        }
    }
    void tellAboutOwnSpecificChild(shared_ptr<Student> child) override
    {
        if (ChildrenNumberCheck())
            cout << child->getName() << " самый лучший\n";
    }
    void tellAboutOtherRandomChild(shared_ptr<Student> child)
    {
        if (grandparentmood == Mood::Great)
        {
            cout << child->getName() << " - молодец, моим внукам стоит взять пример\n";
        }
        else if (grandparentmood == Mood::Good)
        {
            cout << "Ну неплохо одет, видно родители кормят\n";
        }
        else
            cout << "Этот ребенок и близко с моими внуками не сравнится\n";
    }
};
