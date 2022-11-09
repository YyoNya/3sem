#include <iostream>
class Human
{
protected:
    std::string name;
    int age;
public:
    Human(std::string name_, int age_ = 0) : name(name_), age(age_)
    {
    }
    std::string getName() { return name; }
    int getAge() { return age; }
    virtual ~Human()
    {
        std::cout << "~H\n";
    }
    virtual int calcul(int num)
    {
        int i;
        i = num * 10;
        return i;
    }
    virtual int getNum() { return age; }
    virtual const char* who() const { return "Human"; }
};

class Sportmen : virtual public Human
{
protected:
    int gameAverage;
public:
    Sportmen(std::string name_, int age_, int gameAverage_) :
        Human(name_, age_), gameAverage(gameAverage_)
    {
    }
    ~Sportmen()
    {
        std::cout << "~S\n";
    }
    virtual int getNum() { return gameAverage; }
    virtual const char* who() const { return "Sportmen"; }
};

class BasketballPlayer : public Sportmen
{
protected:
    std::string club;
public:
    BasketballPlayer(std::string name_, int age_, int gameAverage_, std::string club_) :
        Human(name_, age_), Sportmen(name_, age_, gameAverage_), club(club_)
    {
    }
    ~BasketballPlayer()
    {
        std::cout << "~B\n";
    }
    virtual int getNum() { return gameAverage; }
    virtual int calcul(int num)
    {
        int i;
        i = num * 10;
        return i;
    }
    virtual const char* who() const { return "BasketballPlayer"; }
};

class Student :virtual public Human
{
protected:
    int mark;
public:
    Student(int mark_, std::string name_, int age_) :
        Human(name_, age_), mark(mark_)
    {
    }
    ~Student()
    {
        std::cout << "~S\n";
    }
    virtual int calcul(int num)
    {
        int i;
        i = num * 10;
        return i;
    }
    virtual int getNum() { return mark; }
    virtual const char* who() const { return "Student"; }
};
void tell(Human& human)
{
    std::cout << human.getName() << " is " << human.who();
}


int main()
{
    Human** arr = new Human * [3];
    arr[0] = new Human("Kir", 17);
    arr[1] = new BasketballPlayer("Ana", 18, 14, "cbh");
    arr[2] = new Student(9, "Vasia", 17);
    for (int i = 0; i < 3; i++)
    {
        tell(*arr[i]);
        std::cout << "\n" << arr[i]->calcul(arr[i]->getNum()) << "\n";
        delete arr[i];
    }
    return 0;
}