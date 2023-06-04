//
// Created by Tomer Gozlan on 04/06/2023.
//

#include "MagicalContainer.hpp"

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

    int MagicalContainer::getSize() const {
        return this->elements.size();
    }

    std::vector<int> MagicalContainer::getElements() const {
        return this->elements;
    }

    int MagicalContainer::getElement(int index) const {
        if (index < 0 || index >= elements.size()) {
            throw std::out_of_range("Error: Invalid index.");
        }
        return elements[index];
    }

    void MagicalContainer::setElements(const std::vector<int> &newElements) {
        this->elements = newElements;
    }

    MagicalContainer::AscendingIterator::AscendingIterator(ariel::MagicalContainer &container) : container(container),
                                                                                                 currentIndex(0) {}

    MagicalContainer::AscendingIterator::AscendingIterator(const ariel::MagicalContainer::AscendingIterator &other)
            : container(other.container), currentIndex(other.currentIndex) {}

    bool
    MagicalContainer::AscendingIterator::operator==(const ariel::MagicalContainer::AscendingIterator &other) const {
        //TODO:implementation this method.
        return true;
    }

    bool
    MagicalContainer::AscendingIterator::operator!=(const ariel::MagicalContainer::AscendingIterator &other) const {
        //TODO:implementation this method.
        return true;
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
        //TODO:implementation this method.
        return -1;
    }

    AscendingIterator &MagicalContainer::AscendingIterator::operator++() {
        //TODO:implementation this method.
        return *this;
    }

    AscendingIterator MagicalContainer::AscendingIterator::begin() const {
        //TODO:implementation this method.
        return *this;
    }

    AscendingIterator MagicalContainer::AscendingIterator::end() const {
        //TODO:implementation this method.
        return *this;
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

    bool MagicalContainer::SideCrossIterator::operator==(const SideCrossIterator &other) const {
        //TODO:implementation this method.
        return true;
    }

    bool MagicalContainer::SideCrossIterator::operator!=(const SideCrossIterator &other) const {
        //TODO:implementation this method.
        return true;
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

    SideCrossIterator &MagicalContainer::SideCrossIterator::operator++() {
        //TODO:implementation this method.
        return *this;
    }

    int MagicalContainer::SideCrossIterator::operator*() const {
        //TODO:implementation this method.
        return -1;
    }

    SideCrossIterator MagicalContainer::SideCrossIterator::begin() const {
        //TODO:implementation this method.
        return *this;
    }

    SideCrossIterator MagicalContainer::SideCrossIterator::end() const {
        //TODO:implementation this method.
        return *this;
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
        return *this;
    }

    MagicalContainer::PrimeIterator::PrimeIterator(const ariel::MagicalContainer &container) : container(container),
                                                                                               currentIndex(0), {}

    MagicalContainer::PrimeIterator::PrimeIterator(const ariel::MagicalContainer::PrimeIterator &other) : container(
            other.container), currentIndex(other.currentIndex) {}

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
        // TODO: implementation this method.
        return true;
    }

    bool MagicalContainer::PrimeIterator::operator!=(const PrimeIterator &other) const {
        // TODO: implementation this method.
        return true;
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

    int MagicalContainer::PrimeIterator::operator++() {
        // TODO: implementation this method.
        return *this;
    }

    int MagicalContainer::PrimeIterator::operator*() const {
        // TODO: implementation this method.
        return -1;
    }

    PrimeIterator MagicalContainer::PrimeIterator::begin() const {
        // TODO: implementation this method.
        return *this;
    }


    PrimeIterator MagicalContainer::PrimeIterator::end() const {
        // TODO: implementation this method.
        return *this;
    }

    int MagicalContainer::PrimeIterator::getCurrentIndex() const {
        // TODO: implementation this method.
        return -1;
    }

    void MagicalContainer::PrimeIterator::setCurrentIndex(int index) {
        // TODO: implementation this method.
    }

    const MagicalContainer &MagicalContainer::PrimeIterator::getContainer() const {
        // TODO: implementation this method.
        return *this;
    }
}