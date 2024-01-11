#include "lesson.cpp"
class Parent
{
private:
    string name;
    vector<shared_ptr<Student>> Children;
    Mood parentmood;
    unsigned parents;

public:
    Parent(string n, Mood m)
    {
        name = n;
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
    int getparents()
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
    void addChild(shared_ptr<Student> child)
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
                    if (Children[i]->Otlichnik())
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
    void tellAboutOwnSpecificChild(shared_ptr<Student> child)
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
private:
    vector<shared_ptr<Parent>> GrandparentChildren;

public:
    Grandparent(string n, Mood grandmood) : Parent(n, grandmood) {}
    void addChild(shared_ptr<Parent> GChild)
    {
        this->GrandparentChildren.push_back(GChild);
        if (GChild->getparents() > 2)
        {
            this->GrandparentChildren.pop_back();
            cout << "У ребенка не может быть больше 2 родителей\n";
        }
    }
    bool ChildrenNumberCheck() override
    {
        if (this->GrandparentChildren.empty())
        {
            cout << "У этого родителя нет детей(это у бабушки или у дедушки)\n";
            return false;
        }
        else
            return true;
    }
    void tellAboutOwnAllChildren() override
    {
        if (ChildrenNumberCheck())
        {

            for (int i = 0; i < this->GrandparentChildren.size() - 1; i++)
            {
                for (int j = 0; j < this->GrandparentChildren[i]->getChild().size() - 1; j++)
                {
                    GrandparentChildren[i]->getChild()[j]->GSorNot();
                    cout << "Внучок молодец\n";
                }
            }
        }
    }

    void tellAboutOwnRandomChild() override
    {
        if (ChildrenNumberCheck())
        {
            srand(time(0));
            int Parentchildindex = rand() % GrandparentChildren.size() + 1;
            int childindex = rand() % GrandparentChildren[Parentchildindex]->getChild().size() + 1;
            if (GrandparentChildren[Parentchildindex]->getChild()[childindex]->Otlichnik())
                cout << GrandparentChildren[Parentchildindex]->getChild()[childindex]->getName() << " Старики уже не те, за то наши внуки - это будущее\n";
            else
                cout << GrandparentChildren[Parentchildindex]->getChild()[childindex]->getName() << " Это еще не конец, пойдем кашки покушаем?\n";
        }
    }

    void tellAboutOwnSpecificChild(shared_ptr<Student> child)
    {
        if (ChildrenNumberCheck())
        {
            for (int i = 0; i < this->GrandparentChildren.size() - 1; i++)
            {
                for (int j = 0; j < this->GrandparentChildren[i]->getChild().size() - 1; j++)
                {
                    if (child == GrandparentChildren[i]->getChild()[j])
                    {
                        if (child->Otlichnik())
                            cout << child->getName() << " внучок старается изо всех сил, он самый лучший\n";
                        else
                            cout << child->getName() << " красавааааааааааа\n";
                    }
                }
            }
        }
    }
    void tellAboutAnotherChild() 
    {

    }
};
