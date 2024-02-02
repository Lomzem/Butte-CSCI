/***********************************************************
Simple Math Calculator
Author: Kyle NoCompile
Date Completed: 9/12/18
Description:
        This program performs simple arithmetic calculations.
        The user enters numbers and the math operation to
        perform on those numbers. The program will then display
        the result of the operation.

Modified Date:
Modified Description:
***********************************************************/

/***************************************
No Compile Kyle
Author: Lawjay Lee
Date Completed: 2024-02-02
Description: Fix Kyle's mistakes. App description above
***************************************/

// #include <ioscream>
#include <iostream> // should be iostream not ioscream
using namespace std;

// Definition of Calculator custom data type
// strut Calculator {
struct Calculator { // should be struct not strut
    // Member variables
    // integer FirstNum;
    int FirstNum; // should be int not integer
    // int SecondNum
    int SecondNum; // forgot semicolon
    char *MathOperator;

    // Member function "calculate" used to calcualte the result
    // based on the values currently stored on the object.
    // Will return false if no valid math operator is stored or if
    // the math operator is not a '+' or a '-'
    // Assuming no validation problems, will update the result
    // parameter with the result of the calculation.
    // bol calculate[int & result] {
    bool calculate(int &result) { // should have parentheses not brackets; also
                                  // bool not bol
        if (MathOperator != nullptr) {
            // if (*MathOperator = '+') {
            if (*MathOperator == '+') { // should be == not =
                result = FirstNum + SecondNum;
                return true;
            } else if (*MathOperator == '-') {
                result = FirstNum - SecondNum;
                return true;
            } else {
                // ret false;
                return false; // should be return not ret
            }
            // ) // should be } not )
        }
        return false;
    }
};

// This function shows a nice welcome message
void showWelcome() {
    cout << "******************************************" << endl;
    cout << "Welcome to the simple calculator program!" << endl;
    cout << "This program will do simple addition and"
         << endl; // forgot semicolon
    cout << "subtraction. Math is fun, so enjoy!" << endl;
    cout << "******************************************" << endl;
}

// This function builds a default Calculator object with
// initialized member variables and returns it
Calculator buildCalculator() {
    Calculator c;
    c.FirstNum = 0;
    // c.SecondNum == 0;
    c.SecondNum = 0;          // should be one equals to set the variable
    c.MathOperator = nullptr; // missing semicolon

    return c;
}

// this function asks the user for either the first integer
// or the second and returns the user's input
// int getInteger(boolean firstNumber) {
int getInteger(bool firstNumber) { // should be bool not boolean
    cout << endl << "Please enter the ";

    // if the "firstNumber" variable is true, then this
    // is the first number being collected
    if (firstNumber) {
        cout << "first ";
    }
    // Otherwise, it's the second number being collected
    else {
        cout << "second ";
    } // should have brackets {} instead of parentheses in else

    cout << "integer: ";

    int input; // should have semicolon instead of colon
    // cin << input;
    cin >> input; // arrows should be facing other direction for cin
    return input; // don't need = for return
}

// This is the main function (where the program begins)
int main() {

    // Call the showWelcome() function
    // showWelcome(void); don't need to explicitly say you're passing in void
    showWelcome();

    // originally, showWelcome was after buildCalculator; it should be the other
    // way around
    // Instantiate Calculator object by calling the buildCalculator function
    // Calculator calculator = buildCalculator{};
    // should call functions with parentheses not {}
    Calculator calculator = buildCalculator();

    // Call the getInteger() function (for the first integer)
    // and store the result in the "FirstNum" member variable of the
    // calculator object
    calculator.FirstNum = getInteger(true); // missing semicolon

    // Ask the user to enter a math operator and store the value
    char mathOperator;
    // should have << not <
    cout << endl
         << "Please select a math operator to perform (\"+\" = "
            "Addition, \"-\" = Subtraction): ";
    // in >> mathOperator;
    cin >> mathOperator; // should be cin not in

    // If the math operator entered by the user is a '+' or '-',
    // set the calculator object's MathOperator member variable to point to
    // the entered data
    // if mathOperato
    // if statements should have () around conditions
    // should be or || not and && since it can't be both
    if (mathOperator == '+' || mathOperator == '-') {
        calculator.MathOperator = &mathOperator;
    }

    // Call the getInteger() function (for the second integer)
    // and store the result in the "SecondNum" member variable of the
    // calculator object
    // calculator - SecondNum = getInteger();
    // need to call getInteger with a bool; should be false since its second
    // int, don't need the -, should be .
    calculator.SecondNum = getInteger(false);

    // Run the "calculate" member function on the calculator object and
    // display appropriate message to user
    int result;
    if (calculator.calculate(result)) {
        cout << endl
             << "The result is " << result
             << endl; // arrows should point other way <<
    } else {
        // cout << end << Not a valid math operator<< end;
        // string should be surrounded by ", should be endl not end
        cout << endl << "Not a valid math operator" << endl;
    }

    return 0;
}
