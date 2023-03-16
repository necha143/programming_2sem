#include "Exception.h"

Exception::Exception(string problem, int cd) {
    this->err = std::move(problem);
    this->code = cd;
}

Exception::~Exception() = default;

int Exception::Code() {
    return code;
}

string Exception::What() {
    return err;
}