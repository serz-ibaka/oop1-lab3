#ifndef _POSTFIKS_GENERATOR_H_
#define _POSTFIKS_GENERATOR_H_
#include "izraz.h"
#include "lista.h"
#include <exception>

using namespace std;

class GPostfiks : public exception {
public:
    const char* what() const override {
        return "***Neispravan izraz!";
    }
};

class PostfiksGenerator {
public:
    static PostfiksGenerator& generator() {
        static PostfiksGenerator g;
        return g;
    }

    PostfiksGenerator(const PostfiksGenerator&) = delete;
    PostfiksGenerator& operator=(const PostfiksGenerator&) = delete;
    
    Izraz& operator()(const Izraz& i);


private:
    PostfiksGenerator() {}
};

#endif