//
//  File.hpp
//  m1

#pragma once
#include "Triangulations.hpp"
/*
 * Абстрактный класс, записывающий результат триангуляции в файл
 */
class File {
public:
    virtual void writing(Triangulations & triangles) = 0;
};
