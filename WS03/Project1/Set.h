/* ------------------------------------------------------
Workshop 3 part 2
Author	Maksym Sorokan
ID 106544208
Date 05.06.2022(dd.mm.yyyy)
Email msorokan@myseneca.ca
-----------------------------------------------------------
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#ifndef SDDS_SET_H
#define SDDS_SET_H
#include <iostream>
#include <cmath>
#include <string>
#include "Pair.h"
#include "Collection.h"
namespace sdds {
    template<class T>
    class Set : public Collection<T, 100> {
        const size_t CAPACITY = 100;
    public:
        Set() {}
        bool add(const T& item) {
            for (size_t i = 0; i < this->number; i++)
            {
                if (item == this->array[i]) return false;
            }
            return Collection<T, 100>::add(item);
        }
    };

    template<>
    bool Set<double>::add(const double& item) {
        for (size_t i = 0; i < this->number; i++)
        {
            if (std::fabs(item - this->array[i]) <= 0.01) return false;
        }
        return Collection<double, 100>::add(item);
    };
}
#endif 