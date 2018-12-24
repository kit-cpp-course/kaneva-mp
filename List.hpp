//
//  List.hpp
//  m1
//

#pragma once
#include <vector>
#include "point.hpp"

using namespace std;
/*
 * Класс, описывающий кольцевой двухсвязный список
 */
class List {

public:
    /*
     * Количество элементов списка (вершин)
     */
    int size;
    /*
     * Указатель на текущий элемент (вершину)
     */
    point * cur;
    
    /*
     * Конструктор пустого списка
     */
    List (int s = 0, point * tmp = 0): size(s), cur(tmp) {}
    /*
     * Деструктор
     */
    ~List() { delete [] cur; }
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
    
};

