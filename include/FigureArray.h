#include "Figure.h"

#pragma once 

#include <vector>

class FigureArray {
private:
    std::vector<Figure*> figure_collection;
public:
    ~FigureArray();
    void addFigure(Figure* fig);
    void removeFigure(int index);
    double totalArea() const;
    size_t size() const { return figure_collection.size(); } 

    Figure* operator[](int index) { return figure_collection[index]; }
    const Figure* operator[](int index) const { return figure_collection[index]; }
    
    FigureArray() = default;
    FigureArray(const FigureArray& other);
    FigureArray(FigureArray&& other) noexcept;
    FigureArray& operator=(const FigureArray& other);
    FigureArray& operator=(FigureArray&& other) noexcept;
};