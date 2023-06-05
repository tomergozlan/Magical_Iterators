//
// Created by tomergozlan on 6/5/23.
//
#include "doctest.h"
#include "sources/MagicalContainer.hpp"

using namespace ariel;

TEST_CASE("Test #1 : MagicalContainer methods") {
    MagicalContainer container;
    CHECK(container.size() == 0);

    SUBCASE("Adding Elements") {
        for (int i = 0; i < 5; ++i) {
            CHECK_NOTHROW(container.addElement(i));
        }
        CHECK(container.size() == 5);
    }

    SUBCASE("Getters functions") {
        std::vector<int> elements = container.getElements();
        for (int i = 0; i < 5; ++i) {
            CHECK_NOTHROW(container.addElement(i));
        }
        for (std::vector<int>::size_type i = 0; i < elements.size(); ++i) {
            CHECK(static_cast<int>(elements[i]) == static_cast<int>(i));
        }
        for (int i = 0; i < 5; ++i) {
            CHECK(container.getElement(i) == i);
        }
    }

    SUBCASE("Removing elements") {
        for (int i = 0; i < 5; ++i) {
            CHECK_NOTHROW(container.addElement(i));
        }
        container.removeElement(3);
        CHECK(container.size() == 4);
    }
    SUBCASE("Setting elements") {
        std::vector<int> newElements = {9, 8, 7};
        container.setElements(newElements);
        CHECK(container.size() == 3);
        std::vector<int> elements = container.getElements();
        CHECK(elements.size() == 3);
        CHECK(elements[0] == 9);
        CHECK(elements[1] == 8);
        CHECK(elements[2] == 7);
    }
}
TEST_CASE("Test #2 : Check the ascendingIterator") {
    MagicalContainer container;
    container.addElement(5);
    container.addElement(3);
    container.addElement(1);
    container.addElement(2);
    container.addElement(4);

    MagicalContainer::AscendingIterator ascending(container);

    CHECK(* ascending.begin() == 1);
    CHECK(* ++ascending.begin() == 2);
    CHECK(* ++ ++ascending.begin() == 3);
    CHECK(* ++ ++ ++ascending.begin() == 4);
    CHECK(* ++ ++ ++ ++ascending.begin() == 5);
}

TEST_CASE("Test #3 : PrimeIterator") {
    // Create a MagicalContainer and add elements
    MagicalContainer container;
    container.addElement(11);
    container.addElement(15);
    container.addElement(3);
    container.addElement(70);
    container.addElement(2);

    // Create a PrimeIterator
    MagicalContainer::PrimeIterator prime(container);

    // Test the iterator functionality
    CHECK(*prime.begin() == 11);
    CHECK(*++prime.begin() == 3);
    CHECK(*++++prime.begin() == 2);
}