//
//  trianglation.hpp
//  m1
//

#pragma once

#include "point.hpp"
#include "Lists.hpp"
#include "triangle.hpp"
#include "Triangulations.hpp"
/*
 * Направления обхода многоугольника
 */
typedef enum { clockwise, count_clockwise, error } type;
/*
 * Класс, реализующий триаcнгуляцию
 */

class trianglation: public Triangulations {
    /*
     *  Список вершин многоугольника
     */
    Lists * list;
    /*
     * Три первые, подряд идущие, вершины
     */
    point * first, * second, * third;
    /*
     * Проверка каждой вершины на выпуклость
     */
    void vertexCheckNCut(std::vector<triangle> & triangles, Lists * list, type cond);
    /*
     * Отрезание уха
     */
    void cuttingEar(std::vector<triangle> & triangles, Lists * list);
    /*
     * Проверка, является ли вершмина ухом
     */
    bool earCheck(Lists * list);
    
public:
    /*
     * Конструктор, заполняющий список вершин переданными значениями
     */
    trianglation(Lists * list) {
        this->list = list->copyList();
        first = list->cur;
        second = list->cur->next;
        third = list->cur->next->next;
    }
    /*
     * Деструктор
     */
    ~trianglation();
    /*
     * Возвращает направление обхода многоугольника
     */
    type direction ();
    /*
     * Триангуляция
     *
     * @returns массив получившихся треугольников
     */
    std::vector<triangle> triangulate (); //триангуляция
    
};


