//
//  triangle.cpp
//  m1


#include "triangle.hpp"

bool triangle::is_in_triangle (point * first, point * second, point * third, point * cur) {
    double a, b, c;
    point *tmp = cur;
    do {
        if ( tmp != first && tmp != second && tmp != third ) {
            a = cross_prod(tmp, first, second);
            b = cross_prod(tmp, second, third);
            c = cross_prod(tmp, third, first);
            if ( ( a > 0 && b > 0 && c > 0 ) || ( a < 0 && b < 0 && c < 0 ) )
                return true;
        }
        tmp = tmp->next;
    } while ( tmp != cur );
    return false;
}
double triangle::cross_prod (point * first, point * second, point * third) {
    double  x1 = second->getX() - first->getX(),
    x2 = third->getX() - first->getX(),
    y1 = second->getY() - first->getY(),
    y2 = third->getY() - first->getY();
    return (x1 * y2 - x2 * y1);
    
}
std::string triangle::printPoints() {
    std::string dots = "";
    for (int i = 0; i < points.size(); i++) {
        dots += ("(" + std::to_string(points[i].getX()) + ";" + std::to_string(points[i].getY()) + ")" + " ");
    }
    return dots;
}

