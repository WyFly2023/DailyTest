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

//    ostream &operator<<(ostream &_cout, const myString &s) {
//        return _cout << s._str;
//    }

    ostream &operator<<(ostream &_cout, const myString &s) {
        for (auto ch: s)
            _cout << ch;
        return _cout;
    }

    istream &operator>>(istream &_cin, myString &s) {
//        s.clear();
//        char ch;
//        //_cin>>ch  读不到空格和换行
//        ch = _cin.get();
//
//        while (ch != ' ' && ch != '\n') {
//            s += ch;
//            ch = _cin.get();
//        }
        s.clear();
        char ch;
        //_cin>>ch  读不到空格和换行
        ch = _cin.get();
        char buff[128];
        size_t i = 0;
        while (ch != ' ' && ch != '\n') {
            //s += ch;
            buff[i++] = ch;

            if(i == 127){
                buff[127] = '\0';
                s += buff;
                i = 0;
            }

            ch = _cin.get();
        }
        if(i > 0){
            buff[i] = '\0';
            s += buff;
        }
        return _cin;
    }

    void getline(std::istream &_cin, Mine::myString &s) {
        s.clear();
        char ch;
        //_cin>>ch  读不到空格和换行
        ch = _cin.get();
        char buff[128];
        size_t i = 0;
        while (ch != '\n') {
            //s += ch;
            buff[i++] = ch;

            if(i == 127){
                buff[127] = '\0';
                s += buff;
                i = 0;
            }

            ch = _cin.get();
        }
        if(i > 0){
            buff[i] = '\0';
            s += buff;
        }
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

    char *myString::begin() const {
        return _str;
    }

    char *myString::end() const {
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

    void myString::insert(size_t pos, const char *s) {
        assert(pos <= _size);
        size_t len = strlen(s);
        if (_size + len > _capacity)
            reserve(_size + len);
        size_t end = _size + len;
        while (end >= pos + len) {
            _str[end] = _str[end - len];
            --end;
        }
        strncpy(_str + pos, s, len);
    }

    void myString::erase(size_t pos, size_t len) {
        assert(pos < _size);
        if (len == npos || len >= _size - pos) {
            _str[pos] = '\0';
            _size = pos;
        } else {
            strcpy(_str + pos, _str + pos + len);
            _size -= len;
        }
    }

    myString::myString(const Mine::myString &s) {
        _str = new char[s._capacity + 1];
        strcpy(_str, s._str);
        _size = s._size;
        _capacity = s._capacity;
    }

    myString &myString::operator+=(char s) {
        push_back(s);
        return *this;
    }

    myString &myString::operator+=(const char *s) {
        append(s);
        return *this;
    }

    void myString::swap(Mine::myString &s) {
        std::swap(_str, s._str);
        std::swap(_capacity, s._capacity);
        std::swap(_size, s._size);
    }

    void swap(myString &s1, myString &s2) {
        s1.swap(s2);
    }

    size_t myString::find(char s, size_t pos) const {
        assert(pos < _size);
        for (size_t i = pos; i < _size; ++i) {
            if (s == _str[i])
                return i;
        }
        return npos;
    }

    size_t myString::find(const char *sub, size_t pos) const {
        assert(pos < _size);
        char *p = strstr(pos + _str, sub);
        if (p)
            return p - _str;
        return npos;
    }
    void myString::clear() {
        _size = 0;
        _str[_size] = '\0';
    }
}

