#include <iostream>
#include <vector>
#include "bag.hpp"
#include "menu.hpp"

using namespace std;

//#define NORMAL_MODE
#ifdef NORMAL_MODE

int main()
{
    cout << "Bag: " << endl;

    Menu menu;
    menu.Run();

    return 0;
}

#else

#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "bag.hpp"

TEST_CASE("insert", "[Bag]") {
    Bag bag;
    
    bag.insert(1);
    CHECK(1 == bag.getFrequency(1));
    CHECK(1 == bag.size());

    bag.insert(1);
    CHECK(2 == bag.getFrequency(1));
    CHECK(1 == bag.size());

    bag.insert(100);
    CHECK(1 == bag.getFrequency(100));
    CHECK(2 == bag.size());

    bag.insert(100);
    CHECK(2 == bag.getFrequency(100));
    CHECK(2 == bag.size());

    bag.insert(0);
    CHECK(1 == bag.getFrequency(0));
    CHECK(3 == bag.size());

    bag.insert(100);
    
    CHECK(3 == bag.getFrequency(100));
    CHECK(3 == bag.size());

}

TEST_CASE("remove", "[Bag]") {
    Bag bag;
    
    bag.insert(-100);

    bag.insert(1);
    bag.insert(1);
    bag.insert(1);
    bag.insert(1);

    bag.insert(4);
    bag.insert(4);
    bag.insert(4);
    
    bag.insert(0);
    bag.insert(0);

    bag.insert(100);

    CHECK(5 == bag.size());
    CHECK(4 == bag.getFrequency(1));
    bag.remove(1);
    CHECK(3 == bag.getFrequency(1));

    CHECK(2 == bag.getFrequency(0));
    bag.remove(0);
    CHECK(1 == bag.getFrequency(0));

    CHECK(1 == bag.getFrequency(-100));
    CHECK(5 == bag.size());
    bag.remove(-100);
    CHECK(0 == bag.getFrequency(-100));
    CHECK(4 == bag.size());

    CHECK_THROWS(bag.remove(5));
    
}

TEST_CASE("getFrequency", "[Bag]") {
    Bag bag;
    
    bag.insert(1);
    bag.insert(1);
    bag.insert(1);
    bag.insert(1);

    bag.insert(4);
    bag.insert(4);
    bag.insert(4);
    
    bag.insert(0);
    bag.insert(0);

    bag.insert(100);

    CHECK(4 == bag.size());
    CHECK(4 == bag.getFrequency(1));
    CHECK(2 == bag.getFrequency(0));
    CHECK(1 == bag.getFrequency(100));
    CHECK(3 == bag.getFrequency(4));
    CHECK(0 == bag.getFrequency(5));
}

TEST_CASE("mostFrequentElement", "[Bag]") {
    Bag bag;

    bag.insert(1);
    bag.insert(1);
    bag.insert(1);
    bag.insert(1);

    CHECK(1 == bag.mostFrequentElement());
    CHECK(4 == bag.getFrequency(1));

    bag.insert(4);
    bag.insert(4);
    bag.insert(4);
    CHECK(1 == bag.mostFrequentElement());
    CHECK(3 == bag.getFrequency(4));

    bag.insert(4);
    CHECK(1 == bag.mostFrequentElement());
    CHECK(4 == bag.getFrequency(4));

    bag.insert(4);
    CHECK(4 == bag.mostFrequentElement());
    CHECK(5 == bag.getFrequency(4));
}

TEST_CASE("Exceptions", "[Bag]") {
    Bag bag;

    try {
        bag.mostFrequentElement();
    } catch (Bag::EmptyBagException ex) {
        CHECK( ex.what() == "The bag is empty");
    }

    try {
        bag.remove(5);
    } catch (Bag::NonExistingElementException ex) {
        CHECK( ex.what() == "There is no element in the bag");
    }

    bag.insert(8);
    try {
        bag.mostFrequentElement();
    } catch (Bag::EmptyBagException ex) {
        CHECK( ex.what() == "The bag is empty");
    }

    bag.insert(8);
    try {
        CHECK(8 == bag.mostFrequentElement());
    } catch (Bag::EmptyBagException ex) {
        cout << ex.what() << endl;
        CHECK( ex.what() == "The bag is empty");
    }

    try {
        bag.remove(5);
    } catch (Bag::NonExistingElementException ex) {
        CHECK( ex.what() == "There is no element in the bag" );
    }
}

#endif