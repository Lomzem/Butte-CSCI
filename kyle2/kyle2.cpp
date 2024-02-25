/***********************************************************
Program Name: Stargaze Simulator
Program Author: Kyle NoCompile
Date Completed: 9/4/18
Program Description:
    This program allows the user to simulate stargazing
    by allowing them to choose a location to point a
    "telescope" into the "sky" and see different planets.

    Just as in reality, not all locations reveal a planet,
    so the user must explore through trial and error.

    Planetary data source:
    https://nssdc.gsfc.nasa.gov/planetary/factsheet/

Modified by: Lawjay Lee
Modified Date: 2024-02-24
Modified Description: fixed syntax errors
***********************************************************/

// #implement < streamio>
// #implement < array>
// these two should be include not implement
#include <array>
#include <iostream> // iostream not streamio

using namespace std; // should be using not including, also missing ;

// Definition of Planet custom data type
class Planet { // class brackets should be {} not ()
    // Member variables (shouldn't be modified from outside of object)
    string name_;              // should be a string not int
    float distanceFromSum_;    // in kilometers * 10^6
    int diameter_;             // in kilometers
    float averageTemperature_; // in celsius
    int moonCount_;

    // classes private by default
    // everything under this needs to be public to be accessible
  public:
    // Planet constructor with initializer list to initialize member variables
    Planet(string name, float distFromSun, int diameter, float averageTemp,
           int moons) // constructors should be () not [] and have same name as
                      // datatype
        // initializer list should be separated by commas
        : name_(name), distanceFromSum_(distFromSun), diameter_(diameter),
          averageTemperature_(averageTemp), moonCount_(moons) {
    }

    // Name getter member function
    string getName() { // doesn't need any parameters?
        return name_;
    }

    // Distance from sun getter member function
    float getDistanceFromSun() {
        return distanceFromSum_; // return doesn't need =, also missing ;
    }

    // Diameter getter member function
    int getDiameter() {
        return diameter_;
    }

    // Average temperator getter member function
    float
    getAverageTemperature() { // should return float not bool? temp is a float
        return averageTemperature_;
    }

    // Moon count getter member function
    // function brackets should be {} not ()
    int getMoonCount() {
        return moonCount_;
    }

}; // missing ; after class

// Definition of Telescope custom data type
class Telescope {          // should be class not classy, should be {} not []
  public:                  // Member variable used to point to a Planet object
    Planet *targetPlanet_; // should have * after type to signal pointer

  private:
    // Telescope constructor with initializer list that initializes the
    // target planet to nullptr
    // everything under here should be public to be accessible
  public:
    Telescope() // constructor shouldn't have return type
        : targetPlanet_(nullptr) {
    }

    // Target planet setter member function
    // should not have semicolon when making functions
    void setTargetPlanet(Planet *newTarget) {
        targetPlanet_ =
            newTarget; // should be = for setting, not == for equality
    }

    // Member function to print target planet details to Stdout
    void targetPlanetToStdout() { // doesn't need to return anything?
        // Only print planet details if telescope is actually pointing to a
        // Planet object
        if (targetPlanet_ != nullptr) {
            // since it's a pointer use -> notation instead of .
            cout << "Planet Name: " << targetPlanet_->getName()
                 << endl; // cout should have << not <
            cout << "Distance From Sun: "
                 << targetPlanet_
                        ->getDistanceFromSun() // cout should have << not >>
                 << " * 10^6 kilometers\n";
            cout << "Diameter: " << targetPlanet_->getDiameter()
                 << " kilometers\n";
            cout << "Average Temperature: "
                 << targetPlanet_->getAverageTemperature()
                 << " degrees (C)\n";      // missing semicolon
            cout << "Number Of Moons: " << // should be << not <
                targetPlanet_->getMoonCount() << endl;
        } else { // should be else not else if since there's no alternative
                 // condition
            cout << "No planet found!\n"; // string needs to be surrounded by ""
        }
    }
};

int main() {
    // Instantiate array of pointer to Planet objects and
    // use brace-initialization to initialize array.

    // All Planet objects use dynamic memory (i.e., heap memory)

    // Adding several nullptr values in the array to signify
    // distance between planets in solar system.

    array<Planet *, 40> planets{
        {new Planet("Mercury", 57.9, 4879, 167, 0),
         nullptr,
         new Planet("Venus", 108.2, 12104, 464, 0), // needs new keyword
         new Planet("Mars", 227.9, 6792, -65, 2),
         nullptr,
         nullptr,
         new Planet("Jupiter", 778.6, 142984, -110,
                    79), // making planets so use new instead of delete
         nullptr,
         nullptr,
         nullptr,
         nullptr,
         nullptr,
         new Planet("Saturn", 1433.5, 120536, -140, 82),
         nullptr,
         nullptr,
         nullptr,
         nullptr,
         nullptr,
         nullptr,
         nullptr,
         nullptr,
         new Planet("Uranus", 2872.5, 51118, -195,
                    27), // should be new not newer
         nullptr,
         nullptr,
         nullptr,
         nullptr,
         nullptr,
         nullptr,
         nullptr, // missing comma
         nullptr,
         nullptr,
         nullptr,
         nullptr,
         nullptr,
         nullptr,
         new Planet("Neptune", 4495.1, 49528, -200, 14), // missing comma
         nullptr,
         nullptr,
         nullptr,
         new Planet("Pluto", 5906.4, 2370, -225, 5)}};

    // Instantiate Telescope object that will be used to
    // target (i.e., look at) Planet objects
    Telescope telescope; // missing ;

    cout << "Welcome to Stargaze Simulator!\n"; // should be << not >>

    // Use simple single character variable to indicate
    // if the user wants to keep running the program
    char keepGazing = 'y';      // chars should be surrounded by ''
    while (keepGazing == 'y') { // equality check should be == not =

        // Prompt user for telescope location number to use and collect user
        // input
        int location;
        cout << "\nChoose a location to point the telescope. Select a location "
                "number between 1-40.\n";
        cin >> location; // should be >> not <<

        // Validate that the user entered a valid location number (i.e., between
        // 1-40 inclusive)
        if (location < 1 || location > 40) { // should be OR not AND
            cout << "You must select a location number between 1-40\n";
        } else {
            // chould be location-- since array index starts at 0
            location--;
            // Set the telescope's target planet to the corresponding Planet
            // object in the array. Since array's use zero-based indexes, be
            // sure to translate user input to actual array index
            telescope.setTargetPlanet(
                planets.at(location)); // should be .at not ->at since not
                                       // pointer, missing ;

            // Display the target information to the CLI
            telescope.targetPlanetToStdout(); // call method with ()
        }

        // Prompt user to keep going and collect user input
        cout
            << "\nWould you like to keep stargazing? (y = yes, n = no)\n"; // should
                                                                           // be
                                                                           // cout
                                                                           // not
                                                                           // out
        cin >> keepGazing; // missing ;
    }

    // Delete dynamic memory before closing program...
    // why did you start i at 1 instead of 0?
    for (int i(0); i < planets.size(); ++i) // for loop needs {} not []
    {
        // Check to see if pointer at array index actually points to a Planet
        // object
        if (planets.at(i) != nullptr) // conditional should be surrounded by ()
        {
            delete planets.at(i);    // should be delete not del
            planets.at(i) = nullptr; // don't leave dangling pointer
        }
    }

    return 0; // missing ;
}
