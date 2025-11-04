#include "FigureArray.h"

FigureArray::~FigureArray() {
    for (auto figure_ptr : figure_collection) delete figure_ptr;
}

void FigureArray::addFigure(Figure* fig) {
    figure_collection.push_back(fig);
}

void FigureArray::removeFigure(int index) {
    if (index < 0 || index >= figure_collection.size()) return;
    delete figure_collection[index];
    figure_collection.erase(figure_collection.begin() + index);
}

double FigureArray::totalArea() const {
    double total_area = 0;
    for (auto figure_ptr : figure_collection) total_area += figure_ptr->area();
    return total_area;
}

FigureArray::FigureArray(const FigureArray& other) {
    for (const auto& figure_ptr : other.figure_collection) {
        figure_collection.push_back(figure_ptr->clone());
    }
}

FigureArray::FigureArray(FigureArray&& other) noexcept 
    : figure_collection(std::move(other.figure_collection)) {
    other.figure_collection.clear();
}

FigureArray& FigureArray::operator=(const FigureArray& other) {
    if (this != &other) {
        for (auto figure_ptr : figure_collection) delete figure_ptr;
        figure_collection.clear();
        for (const auto& figure_ptr : other.figure_collection) {
            figure_collection.push_back(figure_ptr->clone());
        }
    }
    return *this;
}

FigureArray& FigureArray::operator=(FigureArray&& other) noexcept {
    if (this != &other) {
        for (auto figure_ptr : figure_collection) delete figure_ptr;
        figure_collection = std::move(other.figure_collection);
        other.figure_collection.clear();
    }
    return *this;
}
