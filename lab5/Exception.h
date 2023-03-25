#pragma once

#include <exception>
#include <iostream>
#include <utility>

using namespace std;

class Exception : public exception {
    string err;
public:
    Exception(string msg) : err(std::move(msg)) {};

    ~Exception() override = default;

    string gerError() const { return (err); }
};