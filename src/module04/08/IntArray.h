#ifndef _INTARRAR_H_
#define _INTARRAY_H_

class IntArray
{
private:
    int m_length;
    int *m_pointer;
    IntArray(int len);
    bool construct();

public:
    static IntArray &NewInstance(int len);
    IntArray(const IntArray &obj);
    IntArray &operator=(const IntArray &obj);
    int getLength();
    bool getValue(int index, int &value);
    bool setVaule(int index, int value);
    void outArray();
    IntArray &self();
    int* getAddress()
    {
        return m_pointer;
    }
    void free();
};

#endif