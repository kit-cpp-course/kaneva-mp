//
//  trianglation.cpp
//  m1

#include "point.hpp"
#include "triangle.hpp"
#include "List.hpp"
#include "trianglation.hpp"

using namespace std;
/*
 * Возвращает направление обхода многоугольника
 */
type trianglation::direction () {
    point * tmp = list->cur, *min = list->cur;
    double min_x = tmp->getX(), min_y = tmp->getY();
    /*
     * Поиск минимальной "левой" вершины
     */
    if ( !list->is_empty() ) {
        do {
            if ( tmp->getX() < min_x ) {
                min_x = tmp->getX();
                min = tmp;
            }
            if ( tmp->getX() == min_x && tmp->getY() < min_y ) {
                min_y = tmp->getY();
                min = tmp;
            }
            tmp = tmp->next;
        } while ( tmp != list->cur );
        
        return ( (  triangle::cross_prod( min, min->next, min->prev ) < 0) ? clockwise : count_clockwise );
    }
    return error;
}

void trianglation::cuttingEar(vector<triangle> & triangles, List * list) {
    triangle t(point(first->getX(), first->getY()),
               point(second->getX(), second->getY()),
               point(third->getX(), third->getY()));
    triangles.insert(triangles.end(), t);
    list->delete_node(second->getX(), second->getY());
}

bool trianglation::earCheck(List * list) {
    return triangle::is_in_triangle(first, second, third, list->cur);
}

void trianglation::vertexCheckNCut(vector<triangle> & triangles, List * list, type cond)
{
    double prod = triangle::cross_prod(first, second, third);
    if ( ( cond == clockwise && prod < 0 ) || ( cond == count_clockwise && prod > 0 ) ) {
        if (!earCheck(list))
            cuttingEar(triangles, list);
        second = third;
        third = third->next;
    }
    else {
        first = second;
        second = third;
        third = third->next;
    }
}

vector <triangle> trianglation::triangulate() {
    vector<triangle> triangles;
    
    type cond = direction();
    
        while (list->size > 3) {
            vertexCheckNCut(triangles, list, cond);
        }
        if (list->size == 3) {
            triangle t(point(first->getX(), first->getY()),
                       point(second->getX(), second->getY()),
                       point(third->getX(), third->getY()));
            triangles.insert(triangles.end(), t);
        }
        return triangles;
}
