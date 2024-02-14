/***************************************
Memory Game
Author: Lawjay Lee
Date Completed: 2024-02-10
Description: Digital version of concentration
***************************************/

#include "RandomInt.hpp"

#include <array>
#include <bits/fs_fwd.h>
#include <iostream>
using namespace std;

struct Card {
    string Phrase;
    bool Matched;
};

Card NewCard(const string &phrase) {
    Card c;
    c.Phrase = phrase;
    c.Matched = false;
    return c;
}

bool allCardsMatched(array<Card, 4> &cards) {
    for (int i = 0; i < cards.size(); i++) {
        if (cards.at(i).Matched == false) {
            // if any are not matched then
            // cards cannot all be matched
            // return early
            return false;
        }
    }
    // past for loop, all cards are matched
    return true;
}

void displayGameBoard(array<Card *, 8> &cards) {
    /*
    Format:
    Card 1: Flying Monkey
    Card 2: ?
    Card 3: ?
    Card 4: ?
    Card 5: ?
    Card 6: ?
    Card 7: Flying Monkey
    Card 8: ?
    */
    for (int i = 0; i < cards.size(); i++) {
        if (cards.at(i)->Matched) {
            cout << "Card " << i + 1 << ": " << cards.at(i)->Phrase << "\n";
        } else {
            cout << "Card " << i + 1 << ": ?\n";
        }
    }
}

void buildRandomCardPointerArray(array<Card, 4> &cards,
                                 array<Card *, 8> &cardPointers) {
    // 0 - 3 inclusive randomIntGenerator represents
    // the possible indices for cards array. The 2 means
    // there should be two duplicates in the pointers array
    // for each card in cards array
    Random::RandomInt randomIntGenerator(0, 3, 2);

    for (int i = 0; i < cardPointers.size(); i++) {
        int randomInt = randomIntGenerator.get();
        cardPointers.at(i) = &cards.at(randomInt);
    }
}

int main() {
    Card flying_monkey = NewCard("Flying Monkey");
    Card mad_cow = NewCard("Mad Cow");
    Card magic_genie = NewCard("Magic Genie");
    Card great_pumpkin = NewCard("Great Pumpkin");

    array<Card, 4> cards;
    cards.at(0) = flying_monkey;
    cards.at(1) = mad_cow;
    cards.at(2) = magic_genie;
    cards.at(3) = great_pumpkin;

    array<Card *, 8> cardPointers;

    // sets up game and assigns pairs
    buildRandomCardPointerArray(cards, cardPointers);

    cout << "Welcome to Memory Game!\n\n";

    int totalGuesses = 0;

    while (!allCardsMatched(cards)) {
        cout << "Total Guesses: " << totalGuesses << "\n\n";
        displayGameBoard(cardPointers);
        cout << "\n";

        cout << "Select two different cards between 1 and 8:\n";
        int choice1;
        int choice2;
        cin >> choice1;
        cin >> choice2;

        string phrase1 = cardPointers.at(choice1 - 1)->Phrase;
        string phrase2 = cardPointers.at(choice2 - 1)->Phrase;

        if (phrase1 == phrase2) {
            cout << "You found a matching pair!\n";
            cout << "Both cards say \"" << phrase1 << "\"\n";

            // Update card pair to be matched
            // Only have to update once since both
            // cardPointers point to the same card
            cardPointers.at(choice1 - 1)->Matched = true;

        } else {
            cout << "The cards don't match\n";
            cout << "First card says \"" << phrase1 << "\"\n";
            cout << "Second card says \"" << phrase2 << "\"\n";
        }

        totalGuesses++;

        cout << "PRESS ENTER KEY TO CONTINUE...\n";
        cin.ignore();
        cin.ignore();
        system("cls||clear");
    }

    // allow user to see final board and total guesses
    cout << "Total Guesses: " << totalGuesses << "\n\n";
    displayGameBoard(cardPointers);
    cout << "\n";
    cout << "You matched all of the cards! Game over.\n";

    return 0;
}
