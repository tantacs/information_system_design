#include <iostream>

// Abstract class for device.
class IDevice {
    public:
    virtual void TurnOn() = 0;
    virtual void TurnOff() = 0;
};

// A concrete class implementation for Lamp device.
class Lamp : public IDevice {
    public:
    void TurnOn() {
        std::cout << "Turnning lamp on !" << std::endl;
    }
    void TurnOff() {
        std::cout << "Turnning lamp off !" << std::endl;

    }
};

// A concrete class implementation for Engine device.
class Engine : public IDevice {
public:
 void TurnOn() {
     std::cout <<"---- Engine is running " << std::endl;
 }
 void TurnOff() {
     std::cout << "---- Engine is stopped." << std::endl;
 }
};

// Button class uses dependency inversion to control any device
class Button {
    private:
    IDevice* device;
    bool pressed = false;
    public:
    Button(IDevice* device) {
        this->device = device;
    }
    void Press() {
        if (pressed) {
            device->TurnOn();
        } else {
            device->TurnOff();
        }
        pressed = !pressed;
    }

};

int main() {
    Button my_button(new Engine());
    my_button.Press();
    my_button.Press();
    my_button.Press();

    Button another_button(new Lamp());
    another_button.Press();
    another_button.Press();
    another_button.Press();

    return 0;
}