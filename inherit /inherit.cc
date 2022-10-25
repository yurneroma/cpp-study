#include <iostream>
using namespace std;

class Person 
{
    public:
        string profession;
        int age; 
        Person():age(16), profession("unemployed"){}
        void display() {
            walk();
            talk();
            cout << "我的职业是: " << profession << endl;
            cout << "我的年龄是: " << age << endl;
        }

        void walk() { cout << "I can walk" << endl; }
        void talk() { cout << "I can talk" << endl; }
};

class Teacher :  public Person
{
    public:
        void teach()
        {
            cout << "i can teach" << endl;
        }
};

class FootballPlayer : public Person 
{
    public:
        void play()
        {
            cout << "I can play football" << endl;
        }
};

int main() {
    Teacher teacher;
    teacher.profession = "teacher";
    teacher.age = 33;
    teacher.display();
    teacher.teach();

    FootballPlayer player;
    player.age = 30;
    player.profession = "footballplayer";
    player.display();
    player.play();
}