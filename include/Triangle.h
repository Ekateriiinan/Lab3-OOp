#pragma once

#include "Figure.h"

class Triangle : public Figure {
public:
    Triangle() = default;
    Triangle(const Triangle& other) : Figure(other) {}  
    Triangle(Triangle&& other) noexcept : Figure(std::move(other)) {}
    Triangle& operator=(const Triangle& other) {
        Figure::operator=(other);
        return *this;
    }
    Triangle& operator=(Triangle&& other) noexcept {
        Figure::operator=(std::move(other));
        return *this;
    }
    
    void read(std::istream& input) override;
    void print(std::ostream& output) const override;
    double area() const override;
    Triangle* clone() const override { return new Triangle(*this); }
    bool operator==(const Figure& other) const override;
};