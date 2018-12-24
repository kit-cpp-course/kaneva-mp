//
//  ClassTriangulation.hpp
//  m1
//
#pragma once
#include "triangle.hpp"
#include <vector>
/*
 * Абстрактный класс, выполняющий триангуляцию
 */
class ClassTriangulation {
public:
    virtual std::vector<triangle> triangulate() = 0;
};
