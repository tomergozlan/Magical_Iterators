//
// Created by Tomer Gozlan on 04/06/2023.
//

#include "MagicalContainer.hpp"
#include <stdexcept>
#include <cmath>

namespace ariel {

    void MagicalContainer::addElement(int element) {
        this->elements.emplace_back(element);
    }

    void MagicalContainer::removeElement(int element) {
        for (auto it = elements.begin(); it != elements.end(); ++it) {
            if (*it == element) {
                this->elements.erase(it);
                break;
            }
        }
    }

    int MagicalContainer::size() const {
        return this->elements.size();
    }

    std::vector<int> MagicalContainer::getElements() const {
        return this->elements;
    }

    int MagicalContainer::getElement(int index) const {
        if (index < 0 || index >= elements.size()) {
            throw std::out_of_range("Error: Invalid index.");
        }
        return elements[static_cast<std::vector<int>::size_type>(index)];
    }

    void MagicalContainer::setElements(const std::vector<int> &newElements) {
        this->elements = newElements;
    }

    MagicalContainer::AscendingIterator::AscendingIterator(ariel::MagicalContainer &container) : container(container),
                                                                                                 currentIndex(0) {
        std::sort(this->container.elements.begin(), this->container.elements.end());
    }

    MagicalContainer::AscendingIterator::AscendingIterator(const ariel::MagicalContainer::AscendingIterator &other)

    noexcept
    :
    container(other
    .container),
    currentIndex(other
    .currentIndex) {
}

MagicalContainer::AscendingIterator::~AscendingIterator() {}

bool
MagicalContainer::AscendingIterator::operator==(const ariel::MagicalContainer::AscendingIterator &other) const {
    return &container == &other.container && currentIndex == other.currentIndex;
}

bool
MagicalContainer::AscendingIterator::operator!=(const ariel::MagicalContainer::AscendingIterator &other) const {
    return !(*this == other);
}

bool MagicalContainer::AscendingIterator::operator>(const ariel::MagicalContainer::AscendingIterator &other) const {
    //TODO:implementation this method.
    return true;
}

bool MagicalContainer::AscendingIterator::operator<(const ariel::MagicalContainer::AscendingIterator &other) const {
    //TODO:implementation this method.
    return true;
}

bool
MagicalContainer::AscendingIterator::operator<=(const ariel::MagicalContainer::AscendingIterator &other) const {
    //TODO:implementation this method.
    return true;
}

bool
MagicalContainer::AscendingIterator::operator>=(const ariel::MagicalContainer::AscendingIterator &other) const {
    //TODO:implementation this method.
    return true;
}

int MagicalContainer::AscendingIterator::operator*() const {
    return container.getElement(currentIndex);
}

MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator++() {
    ++currentIndex;
    return *this;
}

MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::begin() const {
    AscendingIterator beginIter(container);  // Create an iterator pointing to the first element
    beginIter.setCurrentIndex(0); // Set the current index to 0
    return beginIter;
}

MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::end() const {
    AscendingIterator it(container);
    it.currentIndex = container.elements.size();
    return it;
}

int MagicalContainer::AscendingIterator::getCurrentIndex() const {
    return currentIndex;
}

void MagicalContainer::AscendingIterator::setCurrentIndex(int index) {
    currentIndex = index;
}

const MagicalContainer &MagicalContainer::AscendingIterator::getContainer() const {
    return container;
}

MagicalContainer::SideCrossIterator::SideCrossIterator(const ariel::MagicalContainer &container) : container(
        container), currentIndex(0), moveFromStart(true) {}

MagicalContainer::SideCrossIterator::SideCrossIterator(const ariel::MagicalContainer::SideCrossIterator &other)
        : container(other.container), currentIndex(other.currentIndex), moveFromStart(other.moveFromStart) {}

MagicalContainer::SideCrossIterator::~SideCrossIterator() {}

bool MagicalContainer::SideCrossIterator::operator==(const SideCrossIterator &other) const {
    return &container == &other.container && currentIndex == other.currentIndex && moveFromStart == other.moveFromStart;
}

bool MagicalContainer::SideCrossIterator::operator!=(const SideCrossIterator &other) const {
    return !(*this == other);
}


bool MagicalContainer::SideCrossIterator::operator>(const SideCrossIterator &other) const {
    //TODO:implementation this method.
    return true;
}

bool MagicalContainer::SideCrossIterator::operator<(const SideCrossIterator &other) const {
    //TODO:implementation this method.
    return true;
}

bool MagicalContainer::SideCrossIterator::operator>=(const SideCrossIterator &other) const {
    //TODO:implementation this method.
    return true;
}

bool MagicalContainer::SideCrossIterator::operator<=(const SideCrossIterator &other) const {
    //TODO:implementation this method.
    return true;
}

MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator++() {
    ++currentIndex;
    return *this;
}

int MagicalContainer::SideCrossIterator::operator*() const {
    return container.getElement(currentIndex);
}

MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::begin() const {
    SideCrossIterator beginIter(container);  // Create an iterator pointing to the first element
    beginIter.setCurrentIndex(0); // Set the current index to 0
    return beginIter;
}

MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::end() const {
    SideCrossIterator it(container);
    it.currentIndex = container.elements.size();
    return it;
}

int MagicalContainer::SideCrossIterator::getCurrentIndex() const {
    // TODO: implementation this method.
    return -1;
}

void MagicalContainer::SideCrossIterator::setCurrentIndex(int index) {
    // TODO: implementation this method.
}

bool MagicalContainer::SideCrossIterator::getIsForward() const {
    // TODO: implementation this method.
    return true;
}

void MagicalContainer::SideCrossIterator::setIsForward(bool forward) {
    // TODO: implementation this method.
}

const MagicalContainer &MagicalContainer::SideCrossIterator::getContainer() const {
    // TODO: implementation this method.
    return container;
}

MagicalContainer::PrimeIterator::PrimeIterator(const ariel::MagicalContainer &container) : container(container),
                                                                                           currentIndex(0) {

}

MagicalContainer::PrimeIterator::PrimeIterator(const ariel::MagicalContainer::PrimeIterator &other) : container(
        other.container), currentIndex(other.currentIndex) {
    }

MagicalContainer::PrimeIterator::~PrimeIterator() {}

bool MagicalContainer::PrimeIterator::isPrime(int num) const {
    if (num < 2)
        return false;

    for (int i = 2; i <= sqrt(num); ++i) {
        if (num % i == 0)
            return false;
    }
    return true;
}

bool MagicalContainer::PrimeIterator::operator==(const PrimeIterator &other) const {
    return &container == &other.container && currentIndex == other.currentIndex;
}

bool MagicalContainer::PrimeIterator::operator!=(const PrimeIterator &other) const {
    return !(*this == other);
}

bool MagicalContainer::PrimeIterator::operator>(const PrimeIterator &other) const {
    // TODO: implementation this method.
    return true;
}

bool MagicalContainer::PrimeIterator::operator<(const PrimeIterator &other) const {
    // TODO: implementation this method.
    return true;
}

bool MagicalContainer::PrimeIterator::operator>=(const PrimeIterator &other) const {
    // TODO: implementation this method.
    return true;
}

bool MagicalContainer::PrimeIterator::operator<=(const PrimeIterator &other) const {
    // TODO: implementation this method.
    return true;
}

MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator++() {
    currentIndex++;
    while (currentIndex < container.size() && !isPrime(container.getElement(currentIndex))) {
        currentIndex++;
    }
    return *this;
}

int MagicalContainer::PrimeIterator::operator*() const {
    return container.getElement(currentIndex);
}

MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::begin() const {
    PrimeIterator beginIter(container);
    beginIter.setCurrentIndex(0);
    return beginIter;
}

MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::end() const {
    PrimeIterator it(container);
    it.currentIndex = container.elements.size();
    return it;
}

int MagicalContainer::PrimeIterator::getCurrentIndex() const {
    // TODO: implementation this method.
    return -1;
}

void MagicalContainer::PrimeIterator::setCurrentIndex(int index) {
    currentIndex = index;
}

const MagicalContainer &MagicalContainer::PrimeIterator::getContainer() const {
    // TODO: implementation this method.
    return container;
}

}