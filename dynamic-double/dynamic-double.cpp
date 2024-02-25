/***************************************
Dynamic Double
Author: Lawjay Lee
Date Completed: 2024-02-24
Description: Collects starting integer value
from user and then allows user to double it
as many times as they want
***************************************/

#include <iostream>
using namespace std;

int *DoubleIt(int x) {
    return new int(x * 2);
}

int main() {
    cout << "Enter the starting integer value: ";
    int val;
    cin >> val;

    while (true) {
        cout << "\nThe current value is " << val << "\n";
        cout << "\nWould you like to double the value? (y = yes, n = no)\n";
        char choice;
        cin >> choice;

        if (choice == 'n') {
            break;
        }

        // assuming it was y, not handling if non-char / non-y
        int *doublePtr = DoubleIt(val);
        val = *doublePtr;
        delete doublePtr;
        doublePtr = nullptr; // not necessary because it goes out of scope
    }

    return 0;
}
