/***************************************
Settling Up
Author: Lawjay Lee
Date Completed: 2024-03-07
Description: Uses linked list to store invoice items
and iterates through them using an iterator
***************************************/

#include "LinkedList.hpp"
#include <iostream>
using namespace std;

struct InvoiceItem {
    string Name;
    float Price;

    InvoiceItem(string name, float price) : Name(name), Price(price){};
};

int main() {
    LinkedList<InvoiceItem> itemList;
    itemList.pushBack(InvoiceItem("Two egg, Two bacon breakfast", 10.99));
    itemList.pushBack(
        InvoiceItem("Country fried steak and eggs breakfast", 16.49));
    itemList.pushBack(InvoiceItem("Denver omelet", 15.99));
    itemList.pushBack(InvoiceItem("Short stack and eggs breakfast", 12.99));
    itemList.pushBack(InvoiceItem("Pot of coffee", 3.29));

    cout.precision(2);
    cout.setf(ios::fixed);

    cout << "Itemized Receipt:\n\n";

    float subTotal(0);
    for (LinkedList<InvoiceItem>::Iterator iter(itemList.generateIterator());
         iter.hasNext(); iter.next()) {
        cout << "$" << iter.current()->Price;
        cout << " - " << iter.current()->Name << "\n";
        subTotal += iter.current()->Price;
    }

    cout << "\nSub Total: $" << subTotal << "\n";
    cout << "Total: $" << subTotal * 1.0725 << "\n";

    return 0;
}
