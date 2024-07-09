// FahrToCels.h
#pragma once

class FahrToCels {
private:
    float fahrTemp;

public:
    FahrToCels();
    ~FahrToCels();
    void setTemp(float temp);
    float operator()() const;
};