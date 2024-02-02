/***************************************
Cuboid Objects
Author: Lawjay Lee
Date Completed: 2024-01-25
Description: Receives dimensions of cuboid from user,
then displays volume of cuboid
***************************************/

#include <iostream>
using namespace std;

struct Cuboid {
    int length;
    int width;
    int height;

    int volume() {
        return length * width * height;
    }
};

Cuboid buildCuboidFromUserInput(int cuboidNumber) {
    cout << "Cuboid " << cuboidNumber << ":\n";

    int length;
    cout << "Enter the length:\n";
    cin >> length;

    int width;
    cout << "Enter the width:\n";
    cin >> width;

    int height;
    cout << "Enter the height:\n";
    cin >> height;

    cout << "\n";

    Cuboid c;
    c.length = length;
    c.width = width;
    c.height = height;

    return c;
}

int main() {
    Cuboid cube1 = buildCuboidFromUserInput(1);
    Cuboid cube2 = buildCuboidFromUserInput(2);

    cout << "Cuboid 1 Volume: " << cube1.volume() << "\n";
    cout << "Cuboid 2 Volume: " << cube2.volume() << "\n";
    return 0;
}
