/***************************************
Tip Calculator
Author: Lawjay Lee
Date Completed: 2024-01-23
Description: Provides tip amount based on inputted service
***************************************/

#include <iostream>
using namespace std;

int main() {
    cout.precision(2);
    cout.setf(ios::fixed);

    cout << "Welcome to the tip calculator tool!" << endl << endl;
    cout << "How much were you charged? (in dollars)" << endl;

    float chargeAmount;
    cin >> chargeAmount;

    cout << endl;
    cout << "How was the service?" << endl;
    cout << "1. Very Good (20%)" << endl;
    cout << "2. Good (15%)" << endl;
    cout << "3. Poor (10%)" << endl;
    cout << "4. Very Poor (5%)" << endl;

    int serviceRating;
    cin >> serviceRating;

    float tipPercentage;

    switch (serviceRating) {
    case 1:
        tipPercentage = 0.20;
        break;
    case 2:
        tipPercentage = 0.15;
        break;
    case 3:
        tipPercentage = 0.10;
        break;
    case 4:
        tipPercentage = 0.05;
        break;
    default:
        cout << endl << "Not a valid service rating number" << endl;
        // returning -1 ends the program early and
        // could signal that an error occurred
        return -1;
    }

    float tipAmount = chargeAmount * tipPercentage;

    cout << endl;
    cout << "Tip Amount: $" << tipAmount << endl;
    cout << "Total: $" << chargeAmount + tipAmount << endl;

    // returning 0 could later represent a successful
    // run of the tip calculator
    return 0;
}
