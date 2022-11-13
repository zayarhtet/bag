#ifndef BAG_HPP_INCLUDED
#define BAF_HPP_INCLUDED

#include <iostream>
#include <vector>

#pragma once

inline bool valid (int a) {return true;}

struct Pair {
    int element;
    int frequency;

    // for testing
    Pair () {}
    Pair (int e, int f) : element(e), frequency(f) {}

    friend std::ostream& operator<<(std::ostream& s, const Pair& p) {
        s << "(" << p.element << "," << p.frequency << ")";
        return s;
    }
};



class Bag {
    public:
        class NonExistingElementException : public std::exception {
            public:
                NonExistingElementException(const char* msg) : msg(msg) {}
                const char* what() const noexcept {return msg;}
            private:
                const char* msg;
        };
        class EmptyBagException : public std::exception {
            public:
                EmptyBagException(const char* msg) : msg(msg) {}
                const char* what() const noexcept {return msg;}
            private:
                const char* msg;
        };

        void insert(int element);
        void remove(int element);
        int getFrequency(int element) const;
        int mostFrequentElement();

        friend std::ostream& operator<<(std::ostream& s, const Bag& b);

        int size();

    private:
        std::vector<Pair> elements;
        int calculateMost();
        int mostFreq;
};

#endif