#include <iostream>
#include "Child.h"
using namespace std;
namespace sdds {
    Child::Child() {
    }
    Child::Child(std::string name, int age, const Toy** toy, size_t count) {
        m_toy = new const Toy * [count];
        for (size_t i = 0; i < count; ++i) {
           //m_toy[i] = new Toy(*toy[i]);
            m_toy[i] = toy[i];
        }
        m_name = name;
        m_age = age;
        m_num = count;
    }
    Child::Child(const Child& C) {
        *this=(C);
    }
    Child& Child::operator=(const Child& C) {
        if (this != &C) {
            delete[] m_toy;
            m_toy = new const Toy * [C.m_num];
            
            for (size_t i = 0; i < m_num; i++) {
                //m_toy[i] = C.m_toy[i];
               // m_toy[i] = nullptr;
                delete m_toy[0];
                m_toy[i] = new const Toy(*C.m_toy[i]);
            }
            
            m_name = C.m_name;
            m_age = C.m_age;
            m_num = C.m_num;
        }
        return *this;
    }
    Child::Child(Child&& C) {
        *this=move(C);
    }
    Child::~Child() {
        //for (unsigned int i = 0; i < m_num; ++i)
//delete m_toy[i];
        delete[] m_toy;
    }
    Child& Child::operator=(Child&& C) {
        if (this != &C) {
            delete[] m_toy;
            m_toy = C.m_toy;
            C.m_toy = nullptr;
            m_name = C.m_name;
            m_age = C.m_age;
            m_num = C.m_num;
            if (C.m_name != "") C.m_name = "";
            C.m_age = 0;
            C.m_num = 0;
        }
        return *this;
    }
    size_t Child::size() const {
        return m_num;
    }
    std::ostream& Child::display(std::ostream& ostr) const {
        static size_t CALL_CNT = 1;
        ostr << "--------------------------" << endl;
        ostr << "Child " << CALL_CNT << ": " << m_name << " " << m_age << " years old:" << endl;
        ostr << "--------------------------" << endl;
        if (m_num == 0) {
            ostr << "This child has no toys!" << endl;
        }
        else {
            for (size_t i = 0; i < m_num; i++) {
                m_toy[i]->display();
            }
        }
        ostr << "--------------------------" << endl;
        CALL_CNT++;
        return ostr;
    }
    std::ostream& operator<<(std::ostream& ostr, const Child& C) {
        return C.display(ostr);
    }
}