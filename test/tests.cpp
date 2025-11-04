#include <gtest/gtest.h>

#include <sstream>

#include "FigureArray.h"
#include "Triangle.h"
#include "Square.h"


TEST(FigureTest, MoveSemantics) {
    Triangle first_triangle;
    first_triangle.read(std::istringstream("0 0\n4 0\n2 3\n"));
    
    Triangle second_triangle = std::move(first_triangle);
    EXPECT_NEAR(second_triangle.area(), 6.0, 0.001);
}

TEST(FigureTest, FigureArrayMove) {
    FigureArray first_array;
    Triangle* triangle_obj = new Triangle();
    triangle_obj->read(std::istringstream("0 0\n4 0\n2 3\n"));
    first_array.addFigure(triangle_obj);
    
    FigureArray second_array = std::move(first_array);
    EXPECT_EQ(second_array.size(), 1);
    EXPECT_EQ(first_array.size(), 0);
    EXPECT_NEAR((*second_array[0]).area(), 6.0, 0.001);  
}

TEST(FigureTest, CenterCalculation) {
    Triangle triangle_obj;
    triangle_obj.read(std::istringstream("0 0\n4 0\n2 3\n"));
    Point center_point = triangle_obj.center();
    EXPECT_NEAR(center_point.coord_x, 2.0, 0.001);
    EXPECT_NEAR(center_point.coord_y, 1.0, 0.001);
}

TEST(FigureTest, ArrayOperatorAccess) {
    FigureArray array;
    Triangle* triangle_obj = new Triangle();
    triangle_obj->read(std::istringstream("0 0\n4 0\n2 3\n"));
    array.addFigure(triangle_obj);
    
    EXPECT_NEAR(array[0]->area(), 6.0, 0.001);  
    Point center = array[0]->center();
    EXPECT_NEAR(center.coord_x, 2.0, 0.001);
}
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();

}
