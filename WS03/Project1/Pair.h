/* ------------------------------------------------------
Workshop 3 part 2
Author	Maksym Sorokan
ID 106544208
Date 05.06.2022(dd.mm.yyyy)
Email msorokan@myseneca.ca
-----------------------------------------------------------
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#ifndef SDDS_PAIR_H
#define SDDS_PAIR_H
#include <iostream>
#include <string>
namespace sdds {
    class Pair {
        std::string m_key{};
        std::string m_value{};
    public:
        const std::string& getKey() const {
            return m_key;
        }
        const std::string& getValue() const {
            return m_value;
        }
        Pair(const std::string& key, const std::string& value) : m_key{ key }, m_value{ value }{};
        Pair() : m_key{ "" }, m_value{ "" }{};
        virtual std::ostream& display(std::ostream& ostr = std::cout) const;
        bool operator==(const Pair& p)const {
            return m_key == p.getKey();
        }
    };
    std::ostream& operator<<(std::ostream& ostr, const Pair& p);
}
#endif 