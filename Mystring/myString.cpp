//
// Created by wyf on 2024/3/9.
//

#include "myString.h"

namespace Mine {
    const int Mine::myString::npos = -1;

    myString::myString(const char *str) : _size(strlen(str)) {
        _capacity = _size;
        _str = new char[_capacity + 1];
        strcpy(_str, str);
    }

    myString::~myString() {
        delete[] _str;
        _str = nullptr;
        _size = _capacity = 0;
    }

    ostream &operator<<(ostream &_cout, const myString &s) {
        return _cout << s._str;
    }

    size_t myString::size() const {
        return _size;
    }

    size_t myString::capacity() const {
        return _capacity;
    }

    char &myString::operator[](int pos) {
        assert(pos >= 0);
        return _str[pos];
    }

    const char &myString::operator[](int pos) const {
        assert(pos >= 0);
        return _str[pos];
    }

    char *myString::begin() {
        return _str;
    }

    char *myString::end() {
        return _str + _size;
    }

    void myString::reserve(size_t n) {
        if (n > _capacity) {
            char *tmp = new char[n + 1];
            strcpy(tmp, _str);
            delete[] _str;
            _str = tmp;
            _capacity = n;
        }
    }

    void myString::push_back(char s) {
        if (_size == _capacity)
            reserve(_capacity == 0 ? 4 : 2 * _capacity);

        _str[_size++] = s;
        _str[_size] = '\0';
    }

    void myString::append(const char *s) {
        size_t len = strlen(s);
        if (_size + len >= _capacity)
            reserve(_size + len);
        strcpy(_str + _size, s);
        _size += len;
    }

    void myString::insert(size_t pos, char s) {
        assert(pos <= _size);
        if (_size == _capacity)
            reserve(_capacity == 0 ? 4 : 2 * _capacity);
        size_t end = _size + 1;
        while (end > pos) {
            _str[end] = _str[end - 1];
            --end;
        }
        _str[pos] = s;
        ++_size;
    }

    void myString::erase(size_t pos, size_t len) {
        assert(pos < _size);
        if (len == npos || len >= _size - pos) {
            _str[pos] = '\0';
            _size = pos;
        }
        else {
            strcpy(_str + pos, _str + pos + len);
            _size -= len;
        }
    }
    myString::myString( const Mine::myString &s) {
        _str = new char[s._capacity + 1];
        strcpy(_str,s._str);
        _size = s._size;
        _capacity = s._capacity;
    }
}

