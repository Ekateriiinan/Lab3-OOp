#include "Figure.h"

Figure::Figure(const Figure& other) : vertex_list(other.vertex_list) {}

Figure::Figure(Figure&& other) noexcept : vertex_list(std::move(other.vertex_list)) {}

Figure& Figure::operator=(const Figure& other) {
    if (this != &other) vertex_list = other.vertex_list;
    return *this;
}

Figure& Figure::operator=(Figure&& other) noexcept {
    if (this != &other) vertex_list = std::move(other.vertex_list);
    return *this;
}

Point Figure::center() const {
    double sum_x = 0, sum_y = 0;
    for (const auto& vertex : vertex_list) { 
        sum_x += vertex.coord_x; 
        sum_y += vertex.coord_y; 
    }
    return vertex_list.empty() ? Point() : Point(sum_x / vertex_list.size(), sum_y / vertex_list.size());
}

std::ostream& operator<<(std::ostream& os, const Figure& fig) {
    fig.print(os);
    return os;
}

std::istream& operator>>(std::istream& is, Figure& fig) {
    fig.read(is);
    return is;
}