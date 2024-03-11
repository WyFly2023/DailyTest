//
// Created by wyf on 2024/3/9.
//

#ifndef MYSTRING_MYSTRING_H
#define MYSTRING_MYSTRING_H

#include<iostream>
#include<cstring>
#include<cassert>

using namespace std;
namespace Mine {
    class myString {
    public:
        friend ostream &operator<<(ostream &_cout, const myString &s);

        myString(const char *str = "");

        ~myString();

        size_t size() const;

        size_t capacity() const;

        char &operator[](int pos);

        const char &operator[](int pos) const;

        typedef char *iterator;

        iterator begin();

        iterator end();

        void reserve(size_t n);

        void push_back(char s);

        void append(const char *s);

        void insert(size_t pos, char s);

        void erase(size_t pos, size_t len = npos);

        myString(const myString& s);

    private:
        char *_str;
        size_t _size;
        size_t _capacity;
    public:
        static const int npos;
    };
}

#endif //MYSTRING_MYSTRING_H
