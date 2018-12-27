
#pragma once
#include "triangle.hpp"
#include "Triangulations.hpp"
#include <vector>
#include <fstream>
#include "File.hpp"
/*
 * Класс, создающий файл и записывающий в него данные
 */
class fileEditor: public File {
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
    void writing(Triangulations & triangles);
    
    ~fileEditor();
};
