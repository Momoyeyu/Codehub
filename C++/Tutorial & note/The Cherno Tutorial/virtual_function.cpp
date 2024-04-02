#include <iostream>
#include <string>

class Entity
{
public:
    virtual std::string GetName() { return "Entity"; } // 虚函数

    virtual int GetAge() = 0; // complete virtual method (or "interface") 纯虚函数
    // can't create instance of class with "complete virtual method" (like the one above) 不可实例化
};

class Player : public Entity
{
private:
    std::string m_Name;
    int m_Age;

public:
    Player(const std::string &name) : m_Name(name), m_Age(-1) {}

    // override 指明我们对基类的虚函数进行重载
    std::string GetName() override { return m_Name; }

    // 若子类没有实现基类的纯函数，则子类也不可以实例化
    int GetAge() override { return m_Age; }
};

void PrintName(Entity *entity)
{
    std::cout << entity->GetName() << std::endl;
}

int main()
{
    Player *player = new Player("Cherno");

    PrintName(player);
    std::cout << player->GetAge() << std::endl;

    delete player;

    std::cin.get();
}
