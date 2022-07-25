#pragma once
#include <exception>

class myException: public std::exception {

public:
    virtual void myThrow() const = 0;
};

class BootException: public myException {

public:    
    const char* what() const noexcept override {
        return "you have caught a boot";
    }
    void myThrow() const override {
        throw BootException();
    }
};

class FishException: public myException {

public:
    const char* what() const noexcept override {
        return "you have caught a fish";
    }
    void myThrow() const override {
        throw FishException();
    }
};