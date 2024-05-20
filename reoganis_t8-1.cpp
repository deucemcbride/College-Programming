#include <iostream>
using namespace std;

class Shape {
protected:
    double dimension1;
    double dimension2;

public:
    void get_data() {
        cout << "Enter base and height: ";
        cin >> dimension1 >> dimension2;
    }
    virtual double display_area() = 0;
};

class Triangle : public Shape {
public:
    double display_area() override {
        cout << "Area of triangle is " << 0.5 * dimension1 * dimension2 << endl;
        return 0.5 * dimension1 * dimension2;
    }
};

class Rectangle : public Shape {
public:
    double display_area() override {
        cout << "Area of rectangle is " << dimension1 * dimension2 << endl;
        return dimension1 * dimension2;
    }
};

int main() {
    Triangle triangle;
    Rectangle rectangle;

    triangle.get_data();
    triangle.display_area();

    rectangle.get_data();
    rectangle.display_area();

    return 0;
}
