#include <iostream>
#include <string>

using namespace std;

class Phone {
    private:
        string brand;
        string model;
        int RAM;
        int storage;
        int batteryCapacity;
        int camera;
    public:
        void setBrand(string brand){
            this->brand = brand;
        }

        void setModel(string model){
            this->model = model;
        }

        void setRAM(int RAM){
            this->RAM = RAM;
        }

        void setStorage(int storage){
            this->storage = storage;
        }

        void setBattery(int batteryCapacity){
            this->batteryCapacity = batteryCapacity;
        }

        void setCamera(int camera){
            this->camera = camera;
        }

        void showInfo(){
            cout << "Brand: " << brand << endl;
            cout << "Model: " << model << endl;
            cout << "RAM: " << RAM << endl;
            cout << "Storage: " << storage << endl;
            cout << "Battery capacity: " << batteryCapacity << endl;
            cout << "Camera: " << camera << endl;
        }
};

class Builder {
    private:
        Phone *phone;
    public:
        Builder(){
            phone = new Phone;
        }

        Phone* buildBrand(string brand){
            phone->setBrand(brand);
            return phone;
        }

        Phone* buildModel(string model){
            phone->setModel(model);
            return phone;
        }

        Phone* buildRAM(int RAM){
            phone->setRAM(RAM);
            return phone;
        }

        Phone* buildStorage(int storage){
            phone->setStorage(storage);
            return phone;
        }

        Phone* buildBattery(int batteryCapacity){
            phone->setBattery(batteryCapacity);
            return phone;
        }

        Phone* buildCamera(int camera){
            phone->setCamera(camera);
            return phone;
        }

        Phone *build(){
            return phone;
        }
};

class Director{
    public:
        void construct_iPhone(Builder &builder){
            builder.buildBrand("Apple");
            builder.buildModel("iPhone 13");
            builder.buildRAM(4);
            builder.buildStorage(128);
            builder.buildBattery(3240);
            builder.buildCamera(12);
        }

        void construct_Pixel(Builder &builder){
            builder.buildBrand("Google");
            builder.buildModel("Pixel 9 Pro");
            builder.buildRAM(16);
            builder.buildStorage(256);
            builder.buildBattery(4700);
            builder.buildCamera(50);
        }
};

int main(){
    Director director;
    Builder builder;

    director.construct_iPhone(builder);
    Phone *iPhone = builder.build();
    iPhone->showInfo();
    cout << endl;

    director.construct_Pixel(builder);
    Phone *Pixel = builder.build();
    iPhone->showInfo();

    delete iPhone;
    delete Pixel;

    return 0;
}

