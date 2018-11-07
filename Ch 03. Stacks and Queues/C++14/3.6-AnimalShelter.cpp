// Animal Shelter: An animal shelter, which holds only dogs and cats operates on a strictly "first in, first
// out" basis. People must adopt either the "oldest" (based on arrival time) of all animals at the shelter,
// or they can select whether they would prefer a dog or a cat (and will receive the oldest animal of
// that type). They cannot select which specific animal they would like. Create the data structures to
// maintain this system and implement operations such as enqueue, dequeueAny, dequeueDog,
// and dequeueCat. You may use the built-in LinkedList data structure.

#include <iostream>
#include <limits>
#include <memory>
#include "queue.hpp"

class Animal
{
protected:
    Animal(std::string &&animalName) : name(std::move(animalName))
    {
        orderNo = std::numeric_limits<decltype(orderNo)>::max();
    }

public:
    virtual ~Animal()
    {
    }

    void setOrder(size_t order)
    {
        orderNo = order;
    }

    size_t getOrder() const
    {
        return orderNo;
    }

    const std::string &getName() const
    {
        return name;
    }

    bool operator < (const Animal &other)
    {
        return orderNo < other.orderNo;
    }

    template <typename T>
    static std::shared_ptr<Animal> create(std::string &&name)
    {
        return std::make_shared<T>(std::move(name));
    }

private:
    std::string name;
    size_t orderNo;
};

class Dog: public Animal
{
public:
    Dog(std::string &&name) : Animal(std::move(name))
    {
    }
};

class Cat: public Animal
{
public:
    Cat(std::string &&name) : Animal(std::move(name))
    {
    }
};

class Shelter
{
public:
    Shelter() : nextOrderNo(0)
    {
    }

    void enqueue(std::shared_ptr<Animal> &&animal)
    {
        if (auto dog = std::dynamic_pointer_cast<Dog>(animal))
        {
            dog->setOrder(nextOrderNo++);
            dogs.add(std::move(dog));
        }
        else if (auto cat = std::dynamic_pointer_cast<Cat>(animal))
        {
            cat->setOrder(nextOrderNo++);
            cats.add(std::move(cat));
        }
        else
            throw BadAnimalException();
    }

    std::shared_ptr<Animal> dequeueAny()
    {
        if (dogs.isEmpty())
            return dequeueCat();
        else if (cats.isEmpty())
            return dequeueDog();
        else if (*dogs.peek() < *cats.peek())
            return dequeueDog();
        else
            return dequeueCat();
    }

    std::shared_ptr<Animal> dequeueCat()
    {
        return std::static_pointer_cast<Animal>(cats.remove());
    }

    std::shared_ptr<Animal> dequeueDog()
    {
        return std::static_pointer_cast<Animal>(dogs.remove());
    }

    class BadAnimalException {};

private:
    Queue<std::shared_ptr<Dog>> dogs;
    Queue<std::shared_ptr<Cat>> cats;
    size_t nextOrderNo;
};

int main()
{
    Shelter shelter;
    for (auto name : {"Dog 1", "Cat 1", "Dog 2", "Dog 3 ", "Cat 2", "Cat 3", "Cat 4", "Dog 4", "Dog 5", "Dog 6", "Cat 5", "Cat 6", "Dog 7", "Dog 8", "Cat 7", "Dog 9"})
    {
        if (name[0] == 'D')
            shelter.enqueue(Animal::create<Dog>(std::move(name)));
        else if (name[0] == 'C')
            shelter.enqueue(Animal::create<Cat>(std::move(name)));
    }

    std::cout << "any --> " << shelter.dequeueAny()->getName() << std::endl;
    std::cout << "any --> " << shelter.dequeueAny()->getName() << std::endl;

    std::cout << "dog --> " << shelter.dequeueDog()->getName() << std::endl;
    std::cout << "cat --> " << shelter.dequeueCat()->getName() << std::endl;
    std::cout << "cat --> " << shelter.dequeueCat()->getName() << std::endl;
    std::cout << "cat --> " << shelter.dequeueCat()->getName() << std::endl;
    std::cout << "cat --> " << shelter.dequeueCat()->getName() << std::endl;
    std::cout << "dog --> " << shelter.dequeueDog()->getName() << std::endl;
    std::cout << "dog --> " << shelter.dequeueDog()->getName() << std::endl;
    std::cout << "cat --> " << shelter.dequeueCat()->getName() << std::endl;
    std::cout << "any --> " << shelter.dequeueAny()->getName() << std::endl;
    return 0;
}