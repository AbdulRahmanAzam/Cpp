#include <iostream>
using namespace std;

template <class T>
class Pet{
    private:
    string name;
    int age;
    T characteristics;

    public:
    Pet(string name, int age, T characteristics) : name(name), age(age), characteristics(characteristics) {}

    virtual void makeSound() = 0;
};

template <class T>
class Cat : public Pet<T> {
    private:

    public:
    Cat(string name, int age, T characteristics) : Pet<T>(name, age, characteristics) {}
    
    void makeSound() override{
        cout << "Meow" << endl;
    }
};

template <class T>
class Dog : public Pet<T> {
    private:

    public:
    Dog(string name, int age, T characteristics) : Pet<T>(name, age, characteristics) {}

    void makeSound() override {
        cout << "Woof" << endl;
    }
};
template <class T>
class Bird : public Pet<T> {
    private:

    public:
    Bird(string name, int age, T characteristics) : Pet<T>(name, age, characteristics) {}

    void makeSound() override {
        cout << "Chirp" << endl;
    }
};

int main(){
    Cat<float> cat("cat", 5, 9.0);
    Dog<int> dog("dog", 12, 55);
    Bird<string> bird("bird", 2, "Fly in water");

    cat.makeSound();
    dog.makeSound();
    bird.makeSound();
}
