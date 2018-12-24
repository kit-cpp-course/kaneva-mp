
#pragma once
#include <string>

/*
 * Класс отвечает за обработку аргументов командной строки
 */
class params {
    int count;
    char ** args;
    double * numbs;
    std::string newPath;
    /*
     * Проверка корректности введеного числа
     * @params i - номер аргумента
     */
    bool isRightNumber(int i) const;
    /*
     * Проверка корректности всех введенных чисел
     */
    bool validateNumbers();
    /*
     * Получение пути для создания файла
     */
    void getNewPath();
public:
    /*
     * Конструктор
     */
    params(int count, char ** args) : count(count), args(args) {
        numbs = new double[count];
    }
    /*
     * Деструктор
     */
    ~params() { delete [] numbs; }
    /*
     * Проверяет правильность введенных параметров (нечетное число)
     */
    bool isParamsCorrect();
    /*
     * Возвращает строку из параметров
     */
    std::string getStringParam() { getNewPath(); return newPath; };
    /*
     * Возвращает число из параметров
     */
    double * getNumberParam();
};


