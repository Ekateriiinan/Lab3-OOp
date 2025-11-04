#pragma once 

#include <iostream>
#include <vector>
#include <cmath>

#include "Point.h"


class Figure {
protected:
    std::vector<Point> vertex_list;
    
public:
    Figure()  = default; ;
    Figure(const Figure& other);
    Figure(Figure&& other) noexcept;
    virtual ~Figure()  = default; ; 

    virtual void read(std::istream& input) = 0;
    virtual void print(std::ostream& output) const = 0;
    virtual double area() const = 0;
    virtual Figure* clone() const = 0;
    virtual bool operator==(const Figure& other) const = 0;
    
    Figure& operator=(const Figure& other);
    Figure& operator=(Figure&& other) noexcept;

    Point center() const;  
    
    friend std::ostream& operator<<(std::ostream& os, const Figure& fig);
    friend std::istream& operator>>(std::istream& is, Figure& fig);
};
