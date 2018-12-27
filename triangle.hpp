//
//  triangle.hpp
//  m1
//

#pragma once
#include <vector>
#include "point.hpp"
#include <iostream>
/*
 * Класс, описывающий треугольник
 */
class triangle {
    /*
     * Вершины треугольника, хранящиеся в динамическом массиве
     */
    std::vector<point> points;
public:
    /*
     * Конструктор, заполняющий массив вершин переданными значениями
     */
    triangle(point p1, point p2, point p3) {
        points.insert(points.end(), p1);
        points.insert(points.end(), p2);
        points.insert(points.end(), p3);
    }
    /*
     * Предикат "левый/правый поворот"
     *
     * @returns результат векторного произведения
     */
    static double cross_prod (point * first, point * second, point * third);
    /*
     * Проверка на принадлежность каждой точки треугольнику
     *
     * @param first, second, third вершины треугольника
     * @param cur указатель на точки
     *
     * @returns результат проверки
     */
    static bool is_in_triangle (point * first, point * second, point * third, point * cur);
    /*
     * Вывод координат вершин треугольника
     */
    std::string printPoints();
};

