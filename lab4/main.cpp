#include "iostream"
#include "Triangle.h"
#include "Circle.h"
#include "vector"

int main() {
    std::vector<IFigure*> storage;
    int command;
    CVector2D center;

    while (true) {
        std::cout << "1. show all\n";
        std::cout << "2. add\n";
        std::cout << "3. sum perims\n";
        std::cout << "4. sum squares\n";
        std::cout << "5. weight center\n";
        std::cout << "6. show fig memory usage\n";
        std::cout << "7. sort\n";
        std::cout << "8. exit\n";

        std::cin >> command;
        if (command == 1) {
            for (auto& fig: storage) {
                fig->draw();
            }
        } else if (command == 2) {
            std::cout << "\t1. circle\n";
            std::cout << "\t2. trinagle\n";
            std::cin >> command;
            if (command == 1) {
                storage.push_back(new Circle());
            } else if (command == 2) {
                storage.push_back(new Triangle());
            } else {
                std::cout << "\tcommand not found\n";
            }
        } else if (command == 3) {
            double sum = 0;
            for (auto& fig: storage) {
                sum += fig->perimeter();
            }
            std::cout << "sum perim: " << sum << '\n';
        } else if (command == 4) {
            double sum = 0;
            for (auto& fig: storage) {
                sum += fig->square();
            }
            std::cout << "sum square: " << sum << '\n';
        } else if (command == 5) {
            double massAll = 0;
            double x = 0;
            double y = 0;
            for (auto& figure : storage) {
                x += figure->position().x * figure->mass();
                y += figure->position().y * figure->mass();
                massAll += figure->mass();
            }
            center.x = x / massAll;
            center.y = y / massAll;
            std::cout << "center weight coords: " << center << '\n';
        } else if (command == 6) {
            unsigned int sum = 0;
            for (auto& fig: storage) {
                sum += fig->size();
            }
            std::cout << "sum size: " << sum << '\n';
        } else if (command == 7) {
            sort(storage.begin(), storage.end(), [](IFigure* x, IFigure* y) {return *x < *y;});
            for (auto& fig: storage) {
                fig->draw();
            }
        } else if (command == 8) {
            return 0;
        } else {
            std::cout << "command not found\n";
        }
    }

}   