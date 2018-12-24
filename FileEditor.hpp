

#pragma once
#include "triangle.hpp"
#include "ClassTriangulation.hpp"
#include <vector>
#include <fstream>
#include "ClassFile.hpp"
/*
 * Класс, создающий файл и записывающий в него данные
 */
class fileEditor: public ClassFile {
    /*
     * Файл записи
     */
    std::ofstream writeFile;
public:
    /*
     * Конструктор
     * @params path - путь файла
     */
    fileEditor(const std::string & path);
    /*
     * Запись в файл разбиения
     */
    void writing(ClassTriangulation & triangles);

};


