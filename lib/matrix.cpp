#include "matrix.h"

Array::~Array() {
    delete[] arr;
}

Array::Array(size_t x, size_t y, size_t z): size_x(x), size_y(y), size_z(z), index_x(false), index_y(false), index_z(false), index(0) {
    uint32_t size_arr = (x * y * z * 17 + 15) / 16;
    arr = new uint16_t[size_arr];
    for (uint32_t i = 0; i < size_arr; ++i) {
        arr[i] = 0;
    }
}

Array Array::MakeArray(size_t x, size_t y, size_t z) {

    return Array (x, y, z);
}

size_t Array::GetIndex (size_t x, size_t y, size_t z) const{
    return (x * size_y * size_z + y * size_z + z) * 17;
}

void Array::WriteElement(uint32_t element) {
    for (int i = 0; i < 17; ++i) {
        if (element & (1 << i)) {
            arr[(index + i) / 16] += (1 << (index + i) % 16);
        }
    }
    index = 0;
}

uint32_t Array::ReadElement() {
    uint32_t element = 0;
    for (size_t i = 0; i < 17; ++i) {
        bool b = arr[(index + i) / 16] & (1 << (index + i) % 16);
        element += b * (1 << i);
    }
    index = 0;

    return element;
}

Array Array::operator*(uint32_t number) {
    Array new_array (size_x, size_y, size_z);
    for (size_t x = 0; x < size_x; ++x) {
        for (size_t y = 0; y < size_y; ++y) {
            for (size_t z = 0; z < size_z; ++z) {
                index = GetIndex(x, y, z);
                uint32_t new_element = ReadElement() * number;
                new_array.index = new_array.GetIndex(x, y, z);
                new_array.WriteElement(new_element);
            }
        }
    }

    return new_array;
}

Array Array::operator+(Array& array) {
    Array new_array(size_x, size_y, size_z);
    for (size_t x = 0; x < size_x; ++x) {
        for (size_t y = 0; y < size_y; ++y) {
            for (size_t z = 0; z < size_z; ++z) {
                index = GetIndex(x, y, z);
                array.index = array.GetIndex(x, y, z);
                uint32_t new_element = ReadElement() + array.ReadElement();
                new_array.index = new_array.GetIndex(x, y, z);
                new_array.WriteElement(new_element);
            }
        }
    }

    return new_array;
}
Array Array::operator-(Array& array) {
    Array new_array(size_x, size_y, size_z);
    for (size_t x = 0; x < size_x; ++x) {
        for (size_t y = 0; y < size_y; ++y) {
            for (size_t z = 0; z < size_z; ++z) {
                index = GetIndex(x, y, z);
                array.index = array.GetIndex(x, y, z);
                if ((ReadElement() - array.ReadElement()) >= 0) {
                    index = GetIndex(x, y, z);
                    array.index = array.GetIndex(x, y, z);
                    uint32_t new_element = ReadElement() - array.ReadElement();
                    new_array.index = new_array.GetIndex(x, y, z);
                    new_array.WriteElement(new_element);
                }
            }
        }
    }

    return new_array;
}

Array& Array::operator[] (size_t number) {
    if (!index_x) {
        index_x = true;
        index += GetIndex(number, 0, 0);
    } else if (!index_y) {
        index_y = true;
        index += GetIndex(0, number, 0);
    } else if (!index_z) {
        index_z = true;
        index += GetIndex(0, 0, number);
    }

    return *this;
}

Array& Array::operator=(uint32_t new_element) {
    index_x = false;
    index_y = false;
    index_z = false;
    WriteElement(new_element);

    return *this;
}

Array::operator uint32_t() {
    index_x = false;
    index_y = false;
    index_z = false;
    return ReadElement();
}

std::ostream& operator<<(std::ostream& stream, Array& array) {
    array.index_x = false;
    array.index_y = false;
    array.index_z = false;
    stream << array.ReadElement();

    return stream;
}

std::istream& operator>>(std::istream& stream, Array& array) {
    array.index_x = false;
    array.index_y = false;
    array.index_z = false;
    uint32_t new_element;
    stream >> new_element;
    array.WriteElement(new_element);

    return stream;
}
