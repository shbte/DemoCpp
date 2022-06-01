#ifndef _INTARRAR_H_
#define _INTARRAY_H_

class IntArray
{
private:
    int m_length;
    int *m_pointer;

public:
    IntArray(int len);
    IntArray(const IntArray& obk);
    int getLength();
    bool getValue(int index, int &value);
    bool setVaule(int index, int value);
    void outArray();
    void free();
};

#endif