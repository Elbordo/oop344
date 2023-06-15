/* ------------------------------------------------------
Workshop 3 part 2
Author	Maksym Sorokan
ID 106544208
Date 05.06.2022(dd.mm.yyyy)
Email msorokan@myseneca.ca
-----------------------------------------------------------
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#ifndef SDDS_COLLECTION_H
#define SDDS_COLLECTION_H
#include <iostream>
#include <string>
#include "Pair.h"
namespace sdds {
    template<class T, size_t CAPACITY>
    class Collection {
    protected:
        T array[CAPACITY];
        T dummy{};
        size_t number{ 0 };
    public:
        Collection() {}
        virtual ~Collection() {}
        size_t size()const{
            return number;
        }
        void display(std::ostream& ostr = std::cout)const {
            ostr << "----------------------" << std::endl;
            ostr << "|" << " Collection Content " << "|" << std::endl;
            ostr << "----------------------" << std::endl;
            for (size_t i = 0; i < number; i++) ostr << array[i] << std::endl;
            ostr << "----------------------" << std::endl;
        }
        virtual bool add(const T& item) {
            bool flag = false;
            if (number < CAPACITY) {
                array[number] = item;
                number++;
                flag = true;
            }
            return flag;
        }
        T& operator[](size_t i) {
            if (i >= 0 && i < number) return array[i];
            return dummy;
        }
    };
    template<> Collection<Pair, 100>::Collection() {
        Pair a("No Key", "No Value");
        dummy = a;
    };
}
#endif 