#include "Octagon.h"

#include "Point.h"

void Octagon::read(std::istream& input) {
    vertex_list.clear();
    std::cout << "Введите 8 точек восьмиугольника (в формате: n.0 m.0):\n";
    for (int idx = 0; idx < 8; idx++) {
        Point vertex; 
        std::cout << "Точка " << (idx + 1) << ": "; 
        input >> vertex.coord_x >> vertex.coord_y;
        vertex_list.push_back(vertex);
    }
}

void Octagon::print(std::ostream& output) const {
    output << "Восьмиугольник: площадь=" << area() << " центр=(" << center().coord_x << "," << center().coord_y << ")";
}

double Octagon::area() const {
    if (vertex_list.size() != 8) return 0;
    double area_sum = 0;
    for (int idx = 0; idx < 8; ++idx) {
        int next_idx = (idx + 1) % 8;
        area_sum += vertex_list[idx].coord_x * vertex_list[next_idx].coord_y - 
                   vertex_list[next_idx].coord_x * vertex_list[idx].coord_y;
    }
    return std::abs(area_sum) / 2;
}

bool Octagon::operator==(const Figure& other) const {
    auto octagon_ptr = dynamic_cast<const Octagon*>(&other);
    return octagon_ptr && vertex_list == octagon_ptr->vertex_list;
}
