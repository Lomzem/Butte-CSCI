/***************************************
Writers Conference
Author: Lawjay Lee
Date Completed: 2024-02-24
Description: Allows user to view conference
sessino information at a story writers conference
***************************************/

#include <iostream>
using namespace std;

class ConferenceSession {
    string Title;
    string Description;
    int Room;

  public:
    ConferenceSession(string title, string description, int room)
        : Title(title), Description(description), Room(room){};

    const string &title() const {
        return Title;
    }

    const string &desc() const {
        return Description;
    }

    int room() const {
        return Room;
    }
};

int main() {
    ConferenceSession conf1(
        "Meet Your Characters",
        "Creating authentic characters is a challenge for every writer. This "
        "is an opportunity to meet your characters in the flesh. Come learn "
        "techniques to turn any actor into one of your characters within a few "
        "minutes.",
        3);

    ConferenceSession conf2(
        "The Power Of Staging",
        "How we feel is revealed through our body language, our physical "
        "relationship to others, and to the environment. Conversely, we can "
        "trigger genuine emotional reactions in the actors and in the audience "
        "through the staging of each and every moment in a scene. Come learn "
        "techniques that can enhance every scene and every character in every "
        "moment.",
        4);

    ConferenceSession conf3(
        "Action Scenes",
        "In this action-packed session, you'll learn how to write an effective "
        "plot twist, create unbearable suspense, and design exciting action "
        "sequences using reversals, diversion, and anticipation. Don't miss "
        "this session with dozens of techniques that can be used in any genre.",
        2);

    ConferenceSession conf4(
        "Building The Board",
        "Walk into a writers' room in Hollywood and what do you see? Boards. "
        "Boards are all over the walls! After you've done your beat sheet, the "
        "Board is the best way to take things to the next level. Learn how to "
        "turn your beat sheet into 40 cards that lay out your entire story, "
        "and how to track conflict and emotional changes in every scene.",
        1);

    int choice(0);

    cout << "Welcome to the story writers conference!\n";

    while (true) {
        cout << "\nWhich session would you like to view?\n";

        cout << "1. " << conf1.title() << "\n";
        cout << "2. " << conf2.title() << "\n";
        cout << "3. " << conf3.title() << "\n";
        cout << "4. " << conf4.title() << "\n";
        cout << "5. Exit\n";

        cin >> choice;

        if (choice == 5) {
            break;
        }

        ConferenceSession *choiceConf;

        switch (choice) {
        case 1:
            choiceConf = &conf1;
            break;
        case 2:
            choiceConf = &conf2;
            break;
        case 3:
            choiceConf = &conf3;
            break;
        case 4:
            choiceConf = &conf4;
            break;
        }

        cout << "\n"
             << choiceConf->title() << ", Room " << choiceConf->room() << "\n";
        cout << "Description: " << choiceConf->desc() << "\n";
    }
    return 0;
}
