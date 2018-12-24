//
//  ClassFile.hpp
//  m1

#pragma once
#include "ClassTriangulation.hpp"
/*
 * Абстрактный класс, записывающий результат триангуляции в файл
 */
class ClassFile {
public:
    virtual void writing(ClassTriangulation & triangles) = 0;
};


