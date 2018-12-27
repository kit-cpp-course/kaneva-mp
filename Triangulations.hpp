//  Triangulations.hpp
//  m1
//
#pragma once
#include "triangle.hpp"
#include <vector>
/*
 * Абстрактный класс, выполняющий триангуляцию
 */
class Triangulations {
public:
    virtual std::vector<triangle> triangulate() = 0;
};
