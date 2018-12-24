//
//  trianglation.hpp
//  m1
//

#pragma once

#include "point.hpp"
#include "List.hpp"
#include "triangle.hpp"
#include "ClassTriangulation.hpp"
/*
 * Направления обхода многоугольника
 */
typedef enum { clockwise, count_clockwise, error } type;
/*
 * Класс, реализующий триаcнгуляцию
 */

class trianglation: public ClassTriangulation {
    /*
     *  Список вершин многоугольника
     */
    List * list;
    /*
     * Три первые, подряд идущие, вершины
     */
    point * first, * second, * third;
    /*
     * Проверка каждой вершины на выпуклость
     */
    void vertexCheckNCut(vector<triangle> & triangles, List * list, type cond);
    /*
     * Отрезание уха
     */
    void cuttingEar(vector<triangle> & triangles, List * list);
    /*
     * Проверка, является ли вершмина ухом
     */
    bool earCheck(List * list);
    
public:
    /*
     * Конструктор, заполняющий список вершин переданными значениями
     */
    trianglation(List * list) : list(list) {
        first = list->cur;
        second = list->cur->next;
        third = list->cur->next->next;
    }
    /*
     * Деструктор
     */
    ~trianglation() {   delete [] list; delete [] first;
                        delete [] second; delete [] third;  }
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

