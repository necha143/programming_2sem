#pragma once

#include <iostream>

using namespace std;

class Exception {
public:
    Exception(string what, int cd);

    ~Exception();

    int Code();

    string What();

private:
    string err;
    int code{};
};