#include <iostream>
#include <cmath>

class Equation {
public:
    virtual void Solve() = 0; 
};

class LinearEquation : public Equation {
private:
    double a, b;

public:
    LinearEquation(double a, double b) : a(a), b(b) {}

    void Solve() override {
        if (a == 0) {
            if (b == 0)
                std::cout << "The equation has infinitely many solutions." << std::endl;
            else
                std::cout << "The equation has no solutions." << std::endl;
        }
        else {
            double x = -b / a;
            std::cout << "The equation has one solution: x = " << x << std::endl;
        }
    }
};

class QuadraticEquation : public Equation {
private:
    double a, b, c; 

public:
    QuadraticEquation(double a, double b, double c) : a(a), b(b), c(c) {}

    void Solve() override {
        if (a == 0) {
            LinearEquation linear(b, c);
            linear.Solve();
            return;
        }

        double discriminant = b * b - 4 * a * c;

        if (discriminant > 0) {
            double x1 = (-b + sqrt(discriminant)) / (2 * a);
            double x2 = (-b - sqrt(discriminant)) / (2 * a);
            std::cout << "The equation has two solutions: x1 = " << x1 << ", x2 = " << x2 << std::endl;
        }
        else if (discriminant == 0) {
            double x = -b / (2 * a);
            std::cout << "The equation has one repeated solution: x = " << x << std::endl;
        }
        else {
            std::cout << "The equation has no real solutions." << std::endl;
        }
    }
};

int main() {
   
    Equation* eq1 = new LinearEquation(2, -4);
    eq1->Solve();
    delete eq1;

    Equation* eq2 = new QuadraticEquation(1, -3, 2);
    eq2->Solve();
    delete eq2;

    return 0;
}
