#include <iostream>
#include <vector>
using namespace std;
class Pizza
{
public:
    Pizza(string _name, string _des, int _size, int _cheese, int _salt) : name(_name), description(_des),
                                                                          size(_size), cheese(_cheese), salt(_salt)

    {
        price = calculatePrice();
    }
    ~Pizza(){};
    string getName() const
    {
        return name;
    }

    string getDescription() const
    {
        return description;
    }

    int getSize() const
    {
        return size;
    }

    double getPrice() const
    {
        return price;
    }
    int getCheese() const
    {
        return cheese;
    }

    int getSalt() const
    {
        return salt;
    }
    void setCheese(int _c)
    {
        cheese = _c;
        return;
    }

    void setSalt(int _size)
    {
        salt = _size;
        return;
    }

private:
    string name;
    string description;
    int size;
    int cheese;
    int salt;
    int price;

    int calculatePrice()
    {
        int basePrice = 100;           // базовая цена за любую пиццу 25 см
        int sizePrice = size * 5;      // цена в зависимости от размера
        int cheesePrice = cheese * 10; // цена за добавленный сыр
        int saltPrice = salt * 5;      // цена за добавленную соль
        if (size == 25)
            return basePrice + cheesePrice + saltPrice;
        return basePrice + sizePrice + cheesePrice + saltPrice;
    }
};
class Menu
{
public:
    virtual void display()
    {
        cout << "\n1) Неаполитано\n";
        cout << "2) Маргарита\n";
        cout << "3) Карбонара\n";
        cout << "4) Ветчина и сыр\n";
    }
    Pizza choosePizza(int choice, int sizeChoice, int cheeseChoice, int saltChoice)
    {
        Pizza pizza("", "", 0, 0, 0);
        switch (sizeChoice)
        {
        case 1:
            sizeChoice = 25;
            break;
        case 2:
            sizeChoice = 30;
            break;
        case 3:
            sizeChoice = 35;
            break;
        case 4:
            sizeChoice = 40;
            break;
        default:
            break;
        }
        switch (choice)
        {
        case 1:
            pizza = Pizza("Неаполитано", "Соус томатный, моцарелла, орегано, анчоусы.", sizeChoice, cheeseChoice, saltChoice);
            break;
        case 2:
            pizza = Pizza("Маргарита", "Соус томатный, моцарелла, орегано.", sizeChoice, cheeseChoice, saltChoice);
            break;
        case 3:
            pizza = Pizza("Карбонара", "Соус томатный, моцарелла, пармезан, яйца, бекончик.", sizeChoice, cheeseChoice, saltChoice);
            break;
        case 4:
            pizza = Pizza("Ветчина и сыр", "Соус томатный, ветчина, моцарелла, пармезан.", sizeChoice, cheeseChoice, saltChoice);
            break;
        default:
            break;
        }
        return pizza;
    }
};
class Order : Menu
{
private:
    int total = 0;

public:
    vector<Pizza> pizzas;

    void addPizza(Pizza pizza)
    {
        pizzas.push_back(pizza);
    }

    void display() override
    {
        cout << "ЧЕК:\n";
        for (int i = 0; i < pizzas.size(); i++)
        {
            cout << i + 1 << ") Позиция\n";
            cout << "Название: " << pizzas[i].getName() << endl;
            cout << "Описание: " << pizzas[i].getDescription() << endl;
            cout << "Размер: " << pizzas[i].getSize() << endl;
            cout << "Кол-во сыра: " << pizzas[i].getCheese() << endl;
            cout << "Кол-во соли: " << pizzas[i].getSalt() << endl;
            total += pizzas[i].getPrice();
            cout << "Цена за позицию: " << pizzas[i].getPrice() << " тугриков\n";
        }
        cout << "Общая сумма чека: " << total << " тугриков\n";
    }
};

int main()
{
    Order order;
    Menu menu;
    int choice;

    do
    {
        cout << "1-4 - выбор пиццы, 0 - заказ:";
        menu.display();
        cin >> choice;

        if (choice >= 1 && choice <= 4)
        {
            int sizeChoice;
            cout << "1-4 - выбор размера:\n";
            cout << "1) 25\n";
            cout << "2) 30\n";
            cout << "3) 35\n";
            cout << "4) 40\n";
            cin >> sizeChoice;
            if (sizeChoice >= 1 && sizeChoice <= 4)
            {
                int saltChoice, cheeseChoice;
                cout << "Сколько раз добавить сыра?:";
                cin >> cheeseChoice;
                cout << "\nСколько раз посолить?:";
                cin >> saltChoice;
                Pizza pizza = menu.choosePizza(choice, sizeChoice, cheeseChoice, saltChoice);
                order.addPizza(pizza);
            }
        }
    } while (choice != 0);

    order.display();

    return 0;
}
