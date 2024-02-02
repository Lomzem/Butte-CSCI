/***************************************
Automatic Introspection
Author: Lawjay Lee
Date Completed: 2024-02-02
Description: Allows user to enter a belief,
re-examine the belief, an ourput analysis
of re-examined belief.
***************************************/

#include <iostream>
using namespace std;

string *MakePhilosophical(string &input) {
    input = input + ", right?";
    return &input;
}

int main() {
    string belief;
    cout << "Enter a simple belief:\n";
    getline(cin, belief);

    cout << "\nRe-examined Belief:\n";
    string *philBelief = MakePhilosophical(belief);
    cout << *philBelief << "\n\n";

    if (philBelief->length() < 25) {
        cout << "Analysis: Pithy and profound!\n";
    } else {
        cout << "Analysis: Best not to think about it\n";
    }

    return 0;
}
