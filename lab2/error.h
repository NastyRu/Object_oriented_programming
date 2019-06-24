#ifndef ERROR_H
#define ERROR_H
#include <exception>

class Base_error : public std::exception {
public:
    virtual const char* what() const throw() = 0;
};

class Kol_error : public Base_error {
public:
    const char* what() const throw() {
        return "Incorrect number of elements";
    }
};

class Mem_error : public Base_error {
public:
    const char* what() const throw() {
        return "Memory doesn't allocated";
    }
};

class Empty_error : public Base_error {
public:
    const char* what() const throw() {
        return "List is empty";
    }
};

class Iterator_error : public Base_error {
public:
    const char* what() const throw() {
        return "Iterator error";
    }
};

#endif // _ERRORS_H
