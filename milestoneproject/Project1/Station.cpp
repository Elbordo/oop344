//Milestone 2
// Name: Maksym Sorokan
// Seneca Student ID: 106544208
// Seneca email: msorokan@myseneca.ca
// Date of completion: 30.07.2022(dd.mm.yyyy)
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#include <iostream>
#include <iomanip>
#include "Utilities.h"
#include "Station.h"

namespace sdds {

    size_t Station::m_widthField = 0;
    size_t Station::id_generator = 1;
    const std::string WHITESPACE = " \n\r\t\f\v";
    std::string rtrim(const std::string& s)
    {
        size_t end = s.find_last_not_of(WHITESPACE);
        return (end == std::string::npos) ? "" : s.substr(0, end + 1);
    }
    Station::Station(const std::string& record)
    {
        m_id = id_generator++;

        Utilities utils;
        size_t npos = 0;
        bool more;

        try {
            m_name = utils.extractToken(record, npos, more);
            m_name = rtrim(rtrim(m_name));
            m_nextSerial = std::stoi(utils.extractToken(record, npos, more));
            m_stockQty = std::stoi(utils.extractToken(record, npos, more));

            m_widthField = std::max(utils.getFieldWidth(), m_widthField);

            m_desc = utils.extractToken(record, npos, more);
        }
        catch (std::string& err) {
            std::cout << err;
        }
    }

    const std::string& Station::getItemName() const
    {
        return m_name;
    }

    size_t Station::getNextSerialNumber()
    {
        return m_nextSerial++;
    }

    size_t Station::getQuantity() const
    {
        return m_stockQty;
    }

    void Station::updateQuantity()
    {
        if (0 > --m_stockQty) m_stockQty = 0;
    }

    void Station::display(std::ostream& os, bool full) const
    {
        os << std::setfill('0') << std::setw(3) << std::right << m_id;
        os << " | " << std::setw(m_widthField) << std::setfill(' ') << std::left << m_name;
        os << " | " << std::setfill('0') << std::setw(6) << std::right << m_nextSerial << " | ";

        if (full) {
            os << std::right << std::setw(4) << std::setfill(' ') << m_stockQty << " | ";
            os << std::left << m_desc << std::endl;
        }
        else os << std::endl;
    }
}