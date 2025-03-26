#include <iostream>
#include "iter.h"

void print_int(int &n) {
    std::cout << RED << n << RESET << " ";
}

void print_double(double &n) {
    std::cout << GREEN << n << RESET << " ";
}

void print_string(std::string &str) {
    std::cout << BLUE << str << RESET << " ";
}

int main() {
    int intArr[] = {1, 2, 3, 4, 5};
    size_t intLen = sizeof(intArr) / sizeof(intArr[0]);
    std::cout << GREEN << "Int array: " << RESET;
    iter<int>(intArr, intLen, print_int);
    std::cout << std::endl;

    double doubleArr[] = {3.14, 2.71, 1.618};
    size_t doubleLen = sizeof(doubleArr) / sizeof(doubleArr[0]);
    std::cout << CYAN << "Double array: " << RESET;
    iter<double>(doubleArr, doubleLen, print_double);
    std::cout << std::endl;

    std::string strArr[] = {"Hello", "World", "Array", "Iteration"};
    size_t strLen = sizeof(strArr) / sizeof(strArr[0]);
    std::cout << MAGENTA << "String array: " << RESET;
    iter<std::string>(strArr, strLen, print_string);
    std::cout << std::endl;

    return 0;
}