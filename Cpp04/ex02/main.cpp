#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main() {
    // Correct usage with derived classes
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    delete j; // Calls Dog destructor and Brain destructor
    delete i; // Calls Cat destructor and Brain destructor

    // Creating an array of Animal pointers
    Animal* animals[4];

    for (int idx = 0; idx < 4; ++idx) {
        if (idx < 2) {
            animals[idx] = new Dog();
        } else {
            animals[idx] = new Cat();
        }
    }

    // Cleanup
    for (int idx = 0; idx < 4; ++idx) {
        delete animals[idx];
    }

    // Testing deep copy
    Dog originalDog;
    originalDog.setIdea(0, "Chase the ball");
    originalDog.setIdea(1, "Eat food");

    Dog copiedDog = originalDog; // Test deep copy

    std::cout << "Original Dog Idea 0: " << originalDog.getIdea(0) << std::endl;
    std::cout << "Copied Dog Idea 0: " << copiedDog.getIdea(0) << std::endl;

    return 0;
}
