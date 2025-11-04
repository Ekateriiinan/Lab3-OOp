#include "Figure.h"

#pragma once 

class Octagon : public Figure {
public:
    Octagon() = default;
    Octagon(const Octagon& other) : Figure(other) {} 
    Octagon(Octagon&& other) noexcept : Figure(std::move(other)) {}
    Octagon& operator=(const Octagon& other) {
        Figure::operator=(other);
        return *this;
    }
    Octagon& operator=(Octagon&& other) noexcept {
        Figure::operator=(std::move(other));
        return *this;
    }
    
    void read(std::istream& input) override;
    void print(std::ostream& output) const override;
    double area() const override;
    Octagon* clone() const override { return new Octagon(*this); }
    bool operator==(const Figure& other) const override;
};