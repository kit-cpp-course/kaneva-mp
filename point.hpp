//
//  point.hpp
//  m1
//

#pragma once

/*
 * Класс, описывающий точку
 */
class point {
    /*
     * Координаты точки
     */
    double x, y;
public:
    /*
     * Указатели на предыдущую и следующую точку
     */
    point * prev, * next;
    /*
     * Конструктор по умолчанию. Создает точку в центре координат
     */
    point (double a = 0.0, double b = 0.0) : x(a), y(b), prev(0), next(0) {}
    /*
     * Возвращает координату x
     */
    double getX() const { return x; }
    /*
     * Возвращает координату y
     */
    double getY() const { return y; }
    /*
     * Задает координаты x, y точки
     */
    void setCoordinates (double xs, double ys) { x = xs; y = ys; }
    
};

