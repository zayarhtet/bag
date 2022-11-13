#include <iostream>
#include "menu.hpp"
#include "read.hpp"
#include <sstream>

using namespace std;

#define menuCount 6

bool check(int a) {return a>=0 && a <= menuCount;}
bool validate(int a) {return true;}

void Menu::Run() 
{
    int choice;
    do {
        choice = MenuPrint();
        switch (choice) {
            case 1:
                insert();
                break;
            case 2:
                remove();
                break;
            case 3:
                getFrequency();
                break;
            case 4:
                mostFrequentElement();
                break;
            case 5:
                print();
                break;
            default:
                cout << "Goodbye!" << endl;
                break;
        }
    } while (choice != 0);
}

int Menu::MenuPrint() {
    int choice;
    cout << "\n*********************************************************\n";
    cout << "0, Exit\n";
    cout << "1, Insert\n";
    cout << "2, Remove\n";
    cout << "3, Get Frequency\n";
    cout << "4, Most Frequent Element\n";
    cout << "5, Print\n";
    cout << "*********************************************************\n";

    ostringstream s;
    s << "choose a number between 0 and " << menuCount << "!";
    string errmsg = s.str();
    choice = read<int>("Enter your choice: ", errmsg, check);

    cout << endl;
    return choice;
}

void Menu::insert() {
    int element;
    element = read<int>("Enter an integer: ", "Integer is needed!", validate);
    cout << endl;
    bag.insert(element);
    cout << "Successfully inserted!" << endl;
}

void Menu::remove() {
    int element;
    element = read<int>("Enter an integer to remove: ", "Only integer is accepted!", validate);
    cout << endl;
    try {
        bag.remove(element);
        cout << "\nSuccess!" << endl;
    } catch (Bag::NonExistingElementException e) {
        cout << e.what() << endl;
    }
}

void Menu::getFrequency() {
    int element;
    element = read<int>("Enter an integer to get frequency: ", "Only integer is accepted!", validate);
    cout << endl;
    cout << "Frequency of " << element << " is " << bag.getFrequency(element) << endl;
}

void Menu::mostFrequentElement() {
    try{
        int res = bag.mostFrequentElement();
        cout << "Most frequent element is " << res << endl;
    } catch (Bag::EmptyBagException e) {
        cout << e.what() << endl;
    }
}

void Menu::print() {
    cout << bag;
}