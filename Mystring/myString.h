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
        //friend ostream &operator<<(ostream &_cout, const myString &s);

        myString(const char *str = "");

        ~myString();

        size_t size() const;

        size_t capacity() const;

        char &operator[](int pos);

        const char &operator[](int pos) const;

        typedef char *iterator;

        iterator begin() const;

        iterator end() const;

        void reserve(size_t n);

        void push_back(char s);

        void append(const char *s);

        void insert(size_t pos, char s);

        void insert(size_t pos, const char *s);

        void erase(size_t pos, size_t len = npos);

        myString(const myString &s);

        //myString& operator=(const myString &s);

        myString& operator=(myString s);

        myString &operator+=(char s);

        myString &operator+=(const char *s);

        void swap(myString &s);

        size_t find(char s, size_t pos = 0) const;

        size_t find(const char *sub, size_t pos = 0) const;

        void clear();

    private:
        char *_str = nullptr;
        size_t _size = 0;
        size_t _capacity = 0;
    public:
        static const int npos;
    };

    void swap(myString &s1, myString &s2);

    ostream &operator<<(ostream &_cout, const myString &s);

    istream &operator>>(istream &_cin, myString &s);

    void getline(istream &_cin, myString &s);
}


#endif //MYSTRING_MYSTRING_H
