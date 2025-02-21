#include "iostream"
#include "string.h"
using namespace std;

class Engine{
    public:
        bool isRunning;
        Engine(){
            cout << "Engine Constructed" << endl;
        }
        void start(){
            if (!isRunning){
                cout << "Engine started" << endl;
                isRunning = true;
            }
        }
        void stop(){
            if (isRunning){
                cout << "Engine stopped" << endl;
                isRunning = false;
            }
        }
        ~Engine (){
            cout << "Engine Destroyed" << endl;
        }
};

class Car{
    Engine engine;
    public:
        Car(){
            cout << "Car Constructed" << endl;
        }
        void startCar(){
            engine.start();
        }
        void stopCar(){
            engine.stop();
        }
        ~Car (){
            cout << "Car Destroyed" << endl;
        }
};

int main(){

    Car car1;

    car1.startCar();
    car1.stopCar();

    // The engine is being created when the Car instance is created
    // without any instance of itself hence it can be concluded that
    // Engine is owned by the Car

    return 0;
}