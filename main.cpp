//
//  main.cpp
//  m1
//

#include <vector>
#include "List.hpp"
#include <iostream>
#include "point.hpp"
#include "triangle.hpp"
#include "trianglation.hpp"
#include "consoleParams.hpp"
#include "ClassTriangulation.hpp"
#include "FileEditor.hpp"
#include <string>
#include "ClassFile.hpp"

using namespace std;

int main ( int argc, char** argv ) {
    double * coords;
    int size;
    string path;
    params param(argc, argv);
    
    if (param.isParamsCorrect()) {
    
        List * polygon = new List;
        coords = param.getNumberParam();
        size = argc - 1;
        path = param.getStringParam();
        polygon->insert(coords, size); //инициализация многоугольника
        //применение триангуляции
        trianglation tring(polygon);
        fileEditor editor(path);
        
        ClassFile & file = editor;
        ClassTriangulation & triangulations = tring;
        
        
        file.writing(triangulations);
    }
    return 0;
}
