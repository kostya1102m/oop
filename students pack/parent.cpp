#include "lesson.cpp"
class Parent
{
private:
    string name;
    vector<shared_ptr<Student>> Children;
    Mood parentmood;
    bool ChildrenNumberCheck()
    {
        if (this->Children.size() == 0)
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
                otl = Children[i]->getGS() || otl;

            if (otl == true)
                return true;
            else
                return false;
        }
    }

public:
    virtual void addChild(shared_ptr<Student> child)
    {
        this->Children.push_back(child);
        if (child->getParent() > 2)
        {
            this->Children.pop_back();
            cout << "У ребенка не может быть больше 2 родителей\n";
        }
    }
    virtual void tellAboutOwnAllChildren()
    {
        if (ChildrenNumberCheck())
        {
            if (areChildrenExcellent() && parentmood == Mood::Great)
            {
                for (int i = 0; i < this->Children.size(); i++)
                    if (Children[i]->getGS())
                    {
                        Children[i]->GSorNot();
                        cout << "\nЭТОТ ГРЫЗУН КРАСАВА";
                    }
                    else
                    {
                        Children[i]->GSorNot();
                        cout << "\nЭТОТ ГРЫЗУН БАЛБЕСИНА";
                    }
            }
            else
            {
                cout << "ОНИ ВСЕ БАЛБЕСЫ\n";
            }
        }
    }
    virtual void tellAboutOwnRandomChild()
    {
        if (ChildrenNumberCheck())
        {
            if (parentmood == Mood::Great)
            {
                srand(time(0));
                int childindex = rand() % Children.size() + 1;
                if (Children[childindex]->Otlichnik())
                    cout << Children[childindex]->getName() << " молодец, я очень сильно люблю этого ребенка\n";
                else
                    cout << Children[childindex]->getName() << " старается, этому ребенку есть куда расти\n";
            }
            else if (parentmood == Mood::Good)
            {
                srand(time(0));
                int childindex = rand() % Children.size() + 1;
                if (Children[childindex]->Otlichnik())
                    cout << Children[childindex]->getName() << " хорошо справляется с поставленными задачами\n";
                else
                    cout << Children[childindex]->getName() << " ленится и не может ответственно подойти к учебе\n";
            }
            else
            {
                srand(time(0));
                int childindex = rand() % Children.size() + 1;
                if (Children[childindex]->Otlichnik())
                    cout << Children[childindex]->getName() << " не может полностью раскрыть свой потенциал\n";
                else
                    cout << Children[childindex]->getName() << " - это потеря потерь\n";
            }
        }
    }
    virtual void tellAboutOwnSpecificChild(shared_ptr<Student> child)
    {
        if (ChildrenNumberCheck())
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
    }
};

class Grandparent : public Parent
{
public:
    void tellAboutOwnAllChildren() override
    {
    }

    void tellAboutOwnRandomChild() override
    {
    }

    void tellAboutOwnSpecificChild(shared_ptr<Student> child) override
    {
    }
};
