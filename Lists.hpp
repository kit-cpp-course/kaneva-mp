//
//  Lists.hpp
//  m1
//

#pragma once
#include "point.hpp"

class Lists {
    friend class trianglation;
    /*
     * Указатель на текущий элемент (вершину)
     */
    point * cur = 0;
    /*
     * Все точки
     */
    point ** points = 0;
    
public:
    /*
     * Количество элементов списка (вершин)
     */
    int size;
    /*
     * Конструктор пустого списка
     */
    Lists (int s = 0, point * tmp = 0): size(s), cur(tmp) {}
    /*
     * Создание списка на основе существующего
     */
    Lists (Lists * source);
    /*
     * Вставка элемента в список
     */
    void insert (point ** points, int n);
    /*
     * Деструктор
     */
    ~Lists() { delete [] cur; }
    /*
     * Проверка пуст ли список
     */
    bool is_empty () {
        return ( size == 0 ? true : false );
    }
    /*
     * Добавление вершины с указанными координатами после текущей
     */
    void insert (double a, double b);
    /*
     * Добавление массива координат в пустой список
     */
    void insert (double *a, int n);
    /*
     * Поиск вершины с указанными координатами
     *
     * @returns указатель на вершину
     */
    point * find (double a, double b);
    /*
     * Удаление вершины с указанными координатами
     */
    void delete_node (double a, double b);
    /*
     * Копирование списка
     */
    Lists * copyList();
    
};

