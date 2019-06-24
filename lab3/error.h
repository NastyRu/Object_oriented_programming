#ifndef ERROR_H
#define ERROR_H
#include <exception>

class Base_error : public std::exception {
public:
    virtual const char* what() const throw() = 0;
};

class Num_error : public Base_error {
public:
    const char* what() const throw() {
        return "Incorrect number of floor";
    }
};

#endif // ERROR_H
