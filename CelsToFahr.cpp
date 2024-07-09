// CelsToFahr.cpp
#include "CelsToFahr.h"

CelsToFahr::CelsToFahr() : celsTemp(0.0) {}

CelsToFahr::~CelsToFahr() {}

void CelsToFahr::setTemp(float temp) {
    celsTemp = temp;
}

float CelsToFahr::operator()() const {
    return (celsTemp * 9.0 / 5.0) + 32;
}