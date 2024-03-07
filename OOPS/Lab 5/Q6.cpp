#include<iostream>
using namespace std;
class Graphic_rendering_engine{
    public:
    void getter(){
        cout << "Graphic Rendering engine is working" << endl;
    }
};
class input_handler{
    public:
    void getter(){
        cout<< "Input Handler is working " << endl;
    }
};
class physics_engine{
    public:
    void getter(){
        cout << "physics engine is working" <<endl;
    }
};
class Game_Engine{
    Graphic_rendering_engine GraphicRendering;
    input_handler Handling;
    physics_engine engine;
   public:
   void display(){
    GraphicRendering.getter();
    Handling.getter();
    engine.getter();
    cout<<"GAME ENGINE IS WORKING: "<<endl;
   }

};

int main(){
    Game_Engine obj1;
    obj1.display();
    return 0;
}
