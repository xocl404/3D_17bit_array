#ifndef LABWORK5_XOCL404_MATRIX_H
#define LABWORK5_XOCL404_MATRIX_H

#include <iostream>
#include <cstdint>

class Array {
public:
    Array() = default;
    ~Array();
    static Array MakeArray(size_t x, size_t y, size_t z);
    Array operator*(uint32_t number);
    Array operator+(Array& array);
    Array operator-(Array& array);
    Array& operator[](size_t index);
    Array& operator=(uint32_t new_element);
    explicit operator uint32_t();
    friend std::ostream& operator<<(std::ostream& stream, Array& array);
    friend std::istream& operator>>(std::istream& stream, Array& array);

private:
    uint16_t* arr;
    size_t size_x;
    size_t size_y;
    size_t size_z;
    bool index_x;
    bool index_y;
    bool index_z;
    size_t index;
    Array (size_t x, size_t y, size_t z);
    size_t GetIndex (size_t x, size_t y, size_t z) const;
    void WriteElement(uint32_t element);
    uint32_t ReadElement();
};

#endif //LABWORK5_XOCL404_MATRIX_H
