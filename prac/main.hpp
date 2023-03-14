#ifndef MAIN_HPP
# define MAIN_HPP

#include <iostream>

class Simple
{
private:
    int m_ID;

public:
    Simple(int id)
    {
        SetID(id);
    }

    void SetID(int id)
    {
        m_ID = id;
    }

    int GetID()
    {
        return m_ID;
    }
};

#endif
