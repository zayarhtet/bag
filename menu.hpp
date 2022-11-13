#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include "bag.hpp"

class Menu {
    public:
        Menu() {};
        void Run();

    private:
        Bag bag;
        int MenuPrint();
        void insert();
        void remove();
        void getFrequency();
        void mostFrequentElement();
        void print();
};

#endif