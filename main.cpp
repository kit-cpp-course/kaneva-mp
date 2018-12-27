//
//  main.cpp
//  m1
//

#include <vector>
#include "Lists.hpp"
#include <iostream>
#include "point.hpp"
#include "triangle.hpp"
#include "trianglation.hpp"
#include "consoleParams.hpp"
#include "Triangulations.hpp"
#include "FileEditor.hpp"
#include <string>
#include "File.hpp"

using namespace std;

int main ( int argc, char** argv ) {
    double * coords;
    int size;
    string path;
    params param(argc, argv);
    try {
        if (param.isParamsCorrect()) {
            
            Lists * polygon = new Lists;
            coords = param.getNumberParam();
            size = argc - 1;
            path = param.getStringParam();
            polygon->insert(coords, size); //инициализация многоугольника
            //применение триангуляции
            
            trianglation tring(polygon);
            fileEditor editor(path);
            
            File & file = editor;
            Triangulations & triangulations = tring;
            
            
            file.writing(triangulations);
        }
    } catch (string exeption) {
        cout << exeption << endl;
    }
    return 0;
}

