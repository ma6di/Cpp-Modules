#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
    // Testing the Animal, Dog, and Cat
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;

    i->makeSound(); // Cat sound
    j->makeSound(); // Dog sound
    meta->makeSound(); // Animal sound

    delete meta;
    delete j;
    delete i;

    // Testing the WrongAnimal and WrongCat
    const WrongAnimal* wrongMeta = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();

    std::cout << wrongCat->getType() << " " << std::endl;

    wrongCat->makeSound(); // WrongAnimal sound (not polymorphic)
    wrongMeta->makeSound(); // WrongAnimal sound

    delete wrongMeta;
    delete wrongCat;

    return 0;
}
