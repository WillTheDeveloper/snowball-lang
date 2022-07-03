
#include "snowball/export.hpp"
#include "snowball/types/Number.h"

#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "snowball/constants.h"

extern "C" DLLEXPORT Number* Number__new(snowball_int_t n){
    Number* instance;
    instance = (struct Number*)(malloc(sizeof(Number)));

    instance->number = n;

    return instance;
}

extern "C" DLLEXPORT Number* Number__sum(Number* number, Number* sum) {
    return Number__new(number->number + sum->number);
}
