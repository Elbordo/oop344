/* ------------------------------------------------------
Workshop 3 part 2
Author	Maksym Sorokan
ID 106544208
Date 05.06.2022(dd.mm.yyyy)
Email msorokan@myseneca.ca
-----------------------------------------------------------
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#include<iostream>
#include "Pair.h"
using namespace std;
namespace sdds {
    ostream& Pair::display(ostream& ostr) const {
        ostr.width(20);
        ostr << right << getKey();
        ostr << left << ": " << getValue();
        return ostr;
    }

    ostream& operator<<(ostream& ostr, const Pair& p) {
        return p.display(ostr);
    }
}