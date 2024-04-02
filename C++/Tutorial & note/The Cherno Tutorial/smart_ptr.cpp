// smart pointer

/*
    Smart pointer can help you manage your memory automatically.
    It can prevent the case that you forget to call "delete" to free those memory alloc by "new".
*/

#include <iostream>
#include <string>
#include <memory>

class Entity
{
public:
    Entity()
    {
        std::cout << "Created Entity!" << std::endl;
    }

    ~Entity()
    {
        std::cout << "Destroyed Entity!" << std::endl;
    }

    void Print()
    {
        std::cout << "Print is called!\n";
    }
};

int main()
{
    std::cout << "Testing unique_ptr:\n";
    // unique_ptr
    { // explicit "must call constructor"

        std::unique_ptr<Entity> entity = std::make_unique<Entity>(); // std::make_unique must be call when declaring entity

        // std::unique_ptr<Entity> entity(new Entity());

        entity->Print();
    }

    std::cout << "Testing shared_ptr:\n";
    // shared_ptr
    { // implemented through counter
        std::shared_ptr<Entity> entity;
        // we created entity here, but didn't initialize
        {
            std::shared_ptr<Entity> shared_entity = std::make_shared<Entity>(); // initialize entity and make it shared

            entity = shared_entity; // we didn't fulfill operator useability here

            entity->Print();
        }
        // ptr "shared_entity" is unavaible here, but it's memory isn't free
        entity->Print();
        // because ptr "entity" hold it's memory
    }

    // weak_ptr
    { // it can refer to a shared_ptr, but didn't affect the counter
        std::weak_ptr<Entity> entity;
        // we created entity here, but didn't initialize
        {
            std::shared_ptr<Entity> shared_entity = std::make_shared<Entity>();

            entity = shared_entity;

            shared_entity->Print();
        }
        // shared_entity died here because the counter turn to 0.
        // weak_ptr can't hold the memory after all shared_ptr destoryed.
        // but we can ask weak_ptr whether it's memory was free
    }

    std::cin.get();
}
