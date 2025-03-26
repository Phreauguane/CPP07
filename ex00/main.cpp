#include <iostream>
#include "templates.h"

int main() {
    int a = 42, b = 7;
    double x = 3.14, y = 2.71;
    std::string str1 = "Apple", str2 = "Orange";

    const char* color_a = RED;
    const char* color_b = BLUE;
    const char* color_x = MAGENTA;
    const char* color_y = CYAN;
    const char* color_str1 = WHITE;
    const char* color_str2 = YELLOW;

    std::cout << GREEN << "Before swap:" << RESET << std::endl;
    std::cout << color_a << "a = " << a << RESET << ", " << color_b << "b = " << b << RESET << std::endl;
    std::cout << color_x << "x = " << x << RESET << ", " << color_y << "y = " << y << RESET << std::endl;
    std::cout << color_str1 << "str1 = " << str1 << RESET << ", " << color_str2 << "str2 = " << str2 << RESET << std::endl;

    swap(a, b);
    swap(x, y);
    swap(str1, str2);

    swap(color_a, color_b);
    swap(color_x, color_y);
    swap(color_str1, color_str2);

    std::cout << GREEN << "\nAfter swap:" << RESET << std::endl;
    std::cout << color_a << "a = " << a << RESET << ", " << color_b << "b = " << b << RESET << std::endl;
    std::cout << color_x << "x = " << x << RESET << ", " << color_y << "y = " << y << RESET << std::endl;
    std::cout << color_str1 << "str1 = " << str1 << RESET << ", " << color_str2 << "str2 = " << str2 << RESET << std::endl;

    std::cout << GREEN << "\nTesting min and max functions:" << RESET << std::endl;
    std::cout << CYAN << "Min of " << color_a << a << CYAN " and " << color_b << b << CYAN " is: " << color_a << min(a, b) << RESET << std::endl;
    std::cout << CYAN << "Max of " << color_a << a << CYAN " and " << color_b << b << CYAN " is: " << color_b << max(a, b) << RESET << std::endl;

    std::cout << CYAN << "Min of " << color_x << x << CYAN " and " << color_y << y << CYAN " is: " << color_x << min(x, y) << RESET << std::endl;
    std::cout << CYAN << "Max of " << color_x << x << CYAN " and " << color_y << y << CYAN " is: " << color_y << max(x, y) << RESET << std::endl;

    std::cout << CYAN << "Min of \"" << color_str1 << str1 << CYAN "\" and \"" << color_str2 << str2 << CYAN "\" is: " << color_str2 << min(str1, str2) << RESET << std::endl;
    std::cout << CYAN << "Max of \"" << color_str1 << str1 << CYAN "\" and \"" << color_str2 << str2 << CYAN "\" is: " << color_str1 << max(str1, str2) << RESET << std::endl;

    std::cout << "\n" << GREEN << "- All tests completed successfully! -" << RESET << std::endl;
    return 0;
}