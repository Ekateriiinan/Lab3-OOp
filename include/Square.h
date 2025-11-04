#pragma once

#include "Figure.h"

class Square : public Figure {
public:
    Square() = default;
    Square(const Square& other) : Figure(other) {}  
    Square(Square&& other) noexcept : Figure(std::move(other)) {}
    Square& operator=(const Square& other) {
        Figure::operator=(other);
        return *this;
    }
    Square& operator=(Square&& other) noexcept {
        Figure::operator=(std::move(other));
        return *this;
    }
    
    void read(std::istream& input) override;
    void print(std::ostream& output) const override;
    double area() const override;
    Square* clone() const override { return new Square(*this); }
    bool operator==(const Figure& other) const override;
};