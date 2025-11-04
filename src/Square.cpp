#include "Square.h"

#include "Point.h"

void Square::read(std::istream& input) {
    vertex_list.clear();
    std::cout << "Введите 4 точки квадрата (в формате: n.0 m.0):\n";
    for (int idx = 0; idx < 4; idx++) {
        Point vertex; 
        std::cout << "Точка " << (idx + 1) << ": "; 
        input >> vertex.coord_x >> vertex.coord_y;
        vertex_list.push_back(vertex);
    }
}

void Square::print(std::ostream& output) const {
    output << "Квадрат: площадь=" << area() << " центр=(" << center().coord_x << "," << center().coord_y << ")";
}

double Square::area() const {
    if (vertex_list.size() != 4) return 0;
    double area_sum = 0;
    for (int idx = 0; idx < 4; ++idx) {
        int next_idx = (idx + 1) % 4;
        area_sum += vertex_list[idx].coord_x * vertex_list[next_idx].coord_y - 
                   vertex_list[next_idx].coord_x * vertex_list[idx].coord_y;
    }
    return std::abs(area_sum) / 2;
}

bool Square::operator==(const Figure& other) const {
    auto square_ptr = dynamic_cast<const Square*>(&other);
    return square_ptr && vertex_list == square_ptr->vertex_list;
}
