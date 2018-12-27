
#include "consoleParams.hpp"
#include <iostream>
#include <string>

using namespace std;

bool params::isParamsCorrect() {
    if (((count - 1) % 2)) { //На mac os первый аргумент путь к программе, а директория в которой он лежит
        //и бует путем для файла с результатами
        throw string("Incorrect number of arguments");
    } else if (!validateNumbers()) {
        throw string("Incorrect arguments");
    }
    return true;
}

bool params::validateNumbers() {
    for (int i = 1; i < count; i++) {
        if (!isRightNumber(i)) return false;
    }
    return true;
}

bool params::isRightNumber(int i) const {
    try {
        double result = std::stod(args[i]);
        numbs[i - 1] = result;
    } catch (exception ex) {
        return false;
    }
    return true;
}

double * params::getNumberParam() {
    return numbs;
}

void params::getNewPath() {
    string newstr = args[0];
    int p = newstr.length() - 1;
    
    while (newstr[p--] != '/') {}
    newPath = newstr.erase(p + 2);
}




    while (newstr[p--] != '/') {}
    newPath = newstr.erase(p + 2);
}


