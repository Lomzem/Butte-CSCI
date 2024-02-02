/***************************************
Comic Book Collection
Author: Lawjay Lee
Date Completed: 2024-01-25
Description: Allows user to add entry
into a comic book collection, then displays
all entries after input is done.
***************************************/

#include <iostream>

using namespace std;

struct ComicBook {
    string FullComicBookTitle;
    int IssueNumber;
    int YearPublished;
    string FullAuthorName;
    int ComicRanking;

    void display(int bookNumber) {
        /*
        Template:
        Comic Book 1:
        The Incredible Hulk, issue 1
        Published 1962
        Written by Stan Lee
        Ranking: 2
        */

        cout << "Comic Book " << bookNumber << ":"
             << "\n";
        cout << FullComicBookTitle << ", issue " << IssueNumber << "\n";
        cout << "Published " << YearPublished << "\n";
        cout << "Written by " << FullAuthorName << "\n";
        cout << "Ranking: " << ComicRanking << "\n";
    };
};

ComicBook comicBookFromStdin() {
    string title;
    cout << "Full Comic Book Title: ";
    getline(cin, title);

    int issueNum;
    cout << "Issue Number: ";
    cin >> issueNum;
    cin.ignore();

    int yearPublished;
    cout << "Year Published: ";
    cin >> yearPublished;
    cin.ignore();

    string authorName;
    cout << "Full Author Name: ";
    getline(cin, authorName);

    int ranking;
    cout << "Comic Ranking: ";
    cin >> ranking;
    cin.ignore();

    cout << endl;

    ComicBook c;
    c.FullComicBookTitle = title;
    c.IssueNumber = issueNum;
    c.YearPublished = yearPublished;
    c.FullAuthorName = authorName;
    c.ComicRanking = ranking;
    return c;
}

int main() {
    cout << "Comic Book 1:\n";
    ComicBook comic1 = comicBookFromStdin();

    cout << "Comic Book 2:\n";
    ComicBook comic2 = comicBookFromStdin();

    cout << "Comic Book 3:\n";
    ComicBook comic3 = comicBookFromStdin();

    system("cls||clear");

    comic1.display(1);
    cout << "\n";
    comic2.display(2);
    cout << "\n";
    comic3.display(3);
    return 0;
}
