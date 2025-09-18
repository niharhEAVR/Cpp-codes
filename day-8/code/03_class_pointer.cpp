#include<iostream>

class MyCar
{
private:
    std::string brandName;
    std::string modelName;
public:
    MyCar() = default;
    MyCar(std::string brand, std::string model){
        brandName = brand;
        modelName = model;
    };
    
    void start(){
        std::cout << "Car Started" << std::endl;
    }

    void getBrandName(){
        std::cout << "The car Brand Name is: " << brandName << std::endl; 
    }
    void getModelName(){
        std::cout << "The car Model Name is: " << modelName << std::endl; 
    }

};

int main(){
    MyCar* car1 = new MyCar("Toyota","b1");
    car1->start();
    car1->getBrandName();
    car1->getModelName();

    delete car1;
    car1 = nullptr;
    return 0;
}