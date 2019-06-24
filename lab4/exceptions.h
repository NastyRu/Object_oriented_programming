#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <exception>

class Manager_exceptions : std::exception
{
public:
    virtual const char* what() const throw() = 0;
};

class Builder_exceptions : Manager_exceptions
{
public:
    const char* what() const throw() {
        return "Incorrect build model";
    }
};

class Work_with_file_exceptions : Manager_exceptions
{
public:
    const char* what() const throw() {
        return "Incorrect work with file";
    }
};

class Draw_exceptions : Manager_exceptions
{
public:
    const char* what() const throw() {
        return "Incorrect draw model";
    }
};

class Transform_exceptions : Manager_exceptions
{
public:
    const char* what() const throw() {
        return "Incorrect model to transform";
    }
};

#endif // EXCEPTIONS_H
