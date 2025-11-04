#include "Triangle.h"

#include "Point.h"

void Triangle::read(std::istream& input) {
    vertex_list.clear();
    std::cout << "Введите 3 точки треугольника(в формате: n.0 m.0):\n";
    for (int idx = 0; idx < 3; idx++) {
        Point vertex; 
        std::cout << "Точка " << (idx + 1) << ": "; 
        input >> vertex.coord_x >> vertex.coord_y;
        vertex_list.push_back(vertex);
    }
}

void Triangle::print(std::ostream& output) const {
    output << "Треугольник: площадь=" << area() << " центр=(" << center().coord_x << "," << center().coord_y << ")";
}

double Triangle::area() const {
    if (vertex_list.size() != 3) return 0;
    double area_sum = 0;
    for (int idx = 0; idx < 3; ++idx) {
        int next_idx = (idx + 1) % 3;
        area_sum += vertex_list[idx].coord_x * vertex_list[next_idx].coord_y - 
                   vertex_list[next_idx].coord_x * vertex_list[idx].coord_y;
    }
    return std::abs(area_sum) / 2;
}

bool Triangle::operator==(const Figure& other) const {
    auto triangle_ptr = dynamic_cast<const Triangle*>(&other);
    return triangle_ptr && vertex_list == triangle_ptr->vertex_list;
}
