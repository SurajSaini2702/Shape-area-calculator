#include <iostream>
#include <cmath>
using namespace std;

// Base class
class Shape
{
public:
    // Virtual function for area (runtime polymorphism)
    virtual void input() = 0;   // Pure virtual function for input
    virtual double area() = 0;  // Pure virtual function for calculating area
    virtual void display() = 0; // Pure virtual function for displaying result
    virtual ~Shape() {}         // Virtual destructor
};

// Derived class for Circle
class Circle : public Shape
{
private:
    double radius;

public:
    void input() override
    {
        cout << "Enter radius of Circle: ";
        cin >> radius;
    }

    double area() override
    {
        return 3.14159 * radius * radius;
    }

    void display() override
    {
        cout << "Area of Circle: " << area() << endl;
    }
};

// Derived class for Rectangle
class Rectangle : public Shape
{
private:
    double length, width;

public:
    void input() override
    {
        cout << "Enter length of Rectangle: ";
        cin >> length;
        cout << "Enter width of Rectangle: ";
        cin >> width;
    }

    double area() override
    {
        return length * width;
    }

    void display() override
    {
        cout << "Area of Rectangle: " << area() << endl;
    }
};

// Derived class for Triangle
class Triangle : public Shape
{
private:
    double base, height;

public:
    void input() override
    {
        cout << "Enter base of Triangle: ";
        cin >> base;
        cout << "Enter height of Triangle: ";
        cin >> height;
    }

    double area() override
    {
        return 0.5 * base * height;
    }

    void display() override
    {
        cout << "Area of Triangle: " << area() << endl;
    }
};

// Main function
int main()
{
    Shape *shape = nullptr;
    int choice;

    cout << "========== Shape Area Calculator ==========\n";
    cout << "1. Circle\n";
    cout << "2. Rectangle\n";
    cout << "3. Triangle\n";
    cout << "4. Exit\n";
    cout << "===========================================\n";

    while (true)
    {
        cout << "\nEnter your choice (1-4): ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            shape = new Circle();
            break;
        case 2:
            shape = new Rectangle();
            break;
        case 3:
            shape = new Triangle();
            break;
        case 4:
            cout << "Exiting program. Goodbye!" << endl;
            return 0;
        default:
            cout << "Invalid choice! Try again." << endl;
            continue;
        }

        shape->input();
        shape->display();

        delete shape; // Prevent memory leak
    }

    return 0;
}