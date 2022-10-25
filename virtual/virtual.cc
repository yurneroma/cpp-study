#include <iostream>
using namespace std;


class Animal{
    public:
        virtual void speak() = 0;

};

class Dog: public Animal{
    public:
        void speak() override {
            cout << "my specify is  dog "  << "I can wang wang" << endl;
        }

};


class Cat: public Animal {
    public:
        void speak() override {
            cout << "my specify is cat " << "I can miao miao" << endl;
        }
};


int main() {
    Animal *dog = new Dog();
    Animal *cat = new Cat();

    dog->speak();
    cat->speak();
}

