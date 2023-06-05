//
// Created by Tomer Gozlan on 02/06/2023.
//

#ifndef MAGICAL_ITERATORS_MAGICALCONTAINER_HPP
#define MAGICAL_ITERATORS_MAGICALCONTAINER_HPP

#include <vector>
#include <algorithm>

namespace ariel {

    class MagicalContainer {
    private:

        std::vector<int> elements;

    public:

        MagicalContainer() = default;

        ~MagicalContainer() = default;

        MagicalContainer(const MagicalContainer& other) = default;
        MagicalContainer& operator=(const MagicalContainer& other) = default;

        MagicalContainer(MagicalContainer&& other) noexcept = default;
        MagicalContainer& operator=(MagicalContainer&& other) noexcept = default;



        void addElement(int element);

        void removeElement(int element);

        int size() const;

        std::vector<int> getElements() const;

        int getElement(int index) const;

        void setElements(const std::vector<int> &newElements);

        class AscendingIterator {
        private:

            MagicalContainer &container;
            int currentIndex;

        public:

            AscendingIterator(MagicalContainer &container);

            AscendingIterator(const AscendingIterator &other) noexcept;

            ~AscendingIterator();

            AscendingIterator& operator=(const AscendingIterator& other) {
                return *this;
            }

            AscendingIterator(AscendingIterator&& other) noexcept : container(other.container) ,currentIndex(other.currentIndex) {}

            AscendingIterator& operator=(AscendingIterator&& other) noexcept {
                return *this;
            }




            bool operator==(const AscendingIterator &other) const;

            bool operator!=(const AscendingIterator &other) const;

            bool operator>(const AscendingIterator &other) const;

            bool operator<(const AscendingIterator &other) const;

            bool operator>=(const AscendingIterator &other) const;

            bool operator<=(const AscendingIterator &other) const;

            AscendingIterator &operator++();

            int operator*() const;

            AscendingIterator begin() const;

            AscendingIterator end() const;

            int getCurrentIndex() const;

            void setCurrentIndex(int index);

            const MagicalContainer &getContainer() const;
        };

        class SideCrossIterator {

        private:

            const MagicalContainer &container;
            int currentIndex;
            bool moveFromStart;

        public:

            SideCrossIterator(const MagicalContainer &container);

            SideCrossIterator(const SideCrossIterator &other);

            ~SideCrossIterator();

            SideCrossIterator& operator=(const SideCrossIterator& other) {
                return *this;
            }

            SideCrossIterator(SideCrossIterator&& other) noexcept : container(other.container) , currentIndex(other.currentIndex) , moveFromStart(other.moveFromStart) {}

            SideCrossIterator& operator=(SideCrossIterator&& other) noexcept {
                return *this;
            }


                bool operator==(const SideCrossIterator &other) const;

            bool operator!=(const SideCrossIterator &other) const;

            bool operator>(const SideCrossIterator &other) const;

            bool operator<(const SideCrossIterator &other) const;

            bool operator>=(const SideCrossIterator &other) const;

            bool operator<=(const SideCrossIterator &other) const;

            SideCrossIterator &operator++();

            int operator*() const;

            SideCrossIterator begin() const;

            SideCrossIterator end() const;

            int getCurrentIndex() const;

            void setCurrentIndex(int index);

            bool getIsForward() const;

            void setIsForward(bool forward);

            const MagicalContainer &getContainer() const;
        };

        class PrimeIterator {
        private:
            const MagicalContainer &container;
            int currentIndex;

            bool isPrime(int num) const;

        public:
            PrimeIterator(const MagicalContainer &container);

            PrimeIterator(const PrimeIterator &other);

            ~PrimeIterator();

            PrimeIterator& operator=(const PrimeIterator& other) {
                return *this;
            }

            PrimeIterator& operator=(PrimeIterator&& other) noexcept {
                return *this;
            }

            PrimeIterator(PrimeIterator&& other) noexcept:container(other.container),currentIndex(other.currentIndex) {}

            bool operator==(const PrimeIterator &other) const;

            bool operator!=(const PrimeIterator &other) const;

            bool operator>(const PrimeIterator &other) const;

            bool operator<(const PrimeIterator &other) const;

            bool operator>=(const PrimeIterator &other) const;

            bool operator<=(const PrimeIterator &other) const;

            PrimeIterator &operator++();

            int operator*() const;

            PrimeIterator begin() const;

            PrimeIterator end() const;

            int getCurrentIndex() const;

            void setCurrentIndex(int index);

            const MagicalContainer &getContainer() const;

        };

    };

}

#endif //MAGICAL_ITERATORS_MAGICALCONTAINER_HPP