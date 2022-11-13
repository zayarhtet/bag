#include "bag.hpp"

using namespace std;

void Bag::insert(int element) {
    for (int i = 0; i < elements.size(); i++) {
        if (elements[i].element == element) {
            elements[i].frequency++;
            mostFreq = calculateMost();
            return;
        }
    }
    Pair p;
    p.element = element;
    p.frequency = 1;
    elements.push_back(p);
    mostFreq = calculateMost();
}

void Bag::remove(int element) {
    for (int i = 0; i < elements.size(); i++) {
        if (elements[i].element == element) {
            elements[i].frequency--;
            if (elements[i].frequency == 0) {
                elements.erase(elements.begin() + i);
            }
            mostFreq = calculateMost();
            return;
        }
    }
    throw NonExistingElementException("There is no element in the bag");
}

int Bag::getFrequency(int element) const {
    for (int i = 0; i < elements.size(); i++) {
        if(elements[i].element == element) {
            return elements[i].frequency;
        }
    }
    return 0;
}

int Bag::mostFrequentElement() {
    if (elements.size() == 0) {
        throw EmptyBagException("The bag is empty");
    }
    return mostFreq;
}

ostream& operator<<(std::ostream& s, const Bag& b) {
        s<<"\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n\n";
        s<<"Number of elements: "<< b.elements.size()  << "\nContent: " <<endl;
        for (int i = 0; i < b.elements.size(); i++) {
            s << "(" << b.elements[i].element << "," << b.elements[i].frequency << ")" << " ";
        }
        s << endl;
        s<<"\nMost frequent element: "<< b.mostFreq << endl;
        s<<">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n";
        return s;
}

int Bag::calculateMost() {
    int max = 0;
    int maxElement = 0;

    for (int i = 0; i < elements.size(); i++) {
        if (elements[i].frequency > max) {
            max = elements[i].frequency;
            maxElement = elements[i].element;
        }
    }
    return maxElement;
}

int Bag::size() {
    return elements.size();
}