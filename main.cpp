#include <iostream>

#include "FigureArray.h"
#include "Triangle.h"
#include "Square.h"
#include "Octagon.h"
#include "Point.h"


int main() {

    FigureArray figure_container;
    
    std::cout << "~ Добавление фигур ~\n";
    
    Triangle* triangle_obj = new Triangle();
    std::cin >> *triangle_obj;
    figure_container.addFigure(triangle_obj);
    
    Square* square_obj = new Square();
    std::cin >> *square_obj;
    figure_container.addFigure(square_obj);
    
    FigureArray moved_container = std::move(figure_container);
    std::cout << "\nПосле перемещения - исходный массив: " << figure_container.size() << " фигур";
    std::cout << "\nНовый массив: " << moved_container.size() << " фигур\n";
    
    std::cout << "\n~ Все фигуры ~\n";
    for (int idx = 0; idx < moved_container.size(); ++idx) {
        std::cout << *moved_container[idx] << std::endl; 
    }
    
    std::cout << "\nОбщая площадь: " << moved_container.totalArea() << std::endl;
    
    std::cout << "\n~ Центры фигур ~\n";
    for (int idx = 0; idx < moved_container.size(); ++idx) {
        Point center_point = moved_container[idx]->center(); 
        std::cout << "Фигура " << idx << ": (" << center_point.coord_x << ", " << center_point.coord_y << ")" << std::endl;
    }
    
    return 0;
}