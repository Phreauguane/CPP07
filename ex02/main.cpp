#include <iostream>
#include "array.h"

struct MyStruct {
    int id;
    std::string name;

    MyStruct() : id(0), name("Unnamed") {}
    MyStruct(int id, std::string name) : id(id), name(name) {}

    // Overloading the << operator to print MyStruct objects
    friend std::ostream& operator<<(std::ostream& os, const MyStruct& obj) {
        os << "[ID: " << obj.id << ", Name: " << obj.name << "]";
        return os;
    }
};

int main() {
    std::cout << CYAN << "Starting Array class tests..." << RESET << std::endl;

    try {
        // Test with int type
        Array<int> array1;
        std::cout << GREEN_BG_BLACK_FG << "Test 1: Default constructor called (int)." << RESET << std::endl;
        std::cout << array1;

        Array<int> array2(5);
        std::cout << GREEN_BG_BLACK_FG << "Test 2: Constructor with size 5 (int)." << RESET << std::endl;
        std::cout << array2;

        std::cout << GREEN_BG_BLACK_FG << "Test 3: Assigning values (int)." << RESET << std::endl;
        array2[0] = 10;
        array2[1] = 20;
        array2[2] = 30;
        array2[3] = 40;
        array2[4] = 50;
        std::cout << array2;

        try {
            std::cout << GREEN_BG_BLACK_FG << "Test 4: Accessing out of bounds (int)..." << RESET << std::endl;
            array2[5] = 100;
        }
        catch (const std::exception& e) {
            std::cout << MAGENTA "Caught exception: " RED << e.what() << RESET << std::endl << std::endl;
        }

        // Test with double type
        Array<double> array3(3);
        std::cout << GREEN_BG_BLACK_FG << "Test 5: Constructor with size 3 (double)." << RESET << std::endl;
        array3[0] = 1.42;
        array3[1] = 2.6515;
        array3[2] = 3.6154;
        std::cout << array3;

        // Test with float type
        Array<float> array4(4);
        std::cout << GREEN_BG_BLACK_FG << "Test 6: Constructor with size 4 (float)." << RESET << std::endl;
        array4[0] = 0.1f;
        array4[1] = 1.2f;
        array4[2] = 2.3f;
        array4[3] = 3.4f;
        std::cout << array4;

        // Test with custom struct MyStruct
        Array<MyStruct> array5(2);
        std::cout << GREEN_BG_BLACK_FG << "Test 7: Constructor with size 2 (MyStruct)." << RESET << std::endl;
        array5[0] = MyStruct(1, "Alice");
        array5[1] = MyStruct(2, "Bob");
        std::cout << array5;

        // Copy constructor test for custom struct
        Array<MyStruct> array6(array5);
        std::cout << GREEN_BG_BLACK_FG << "Test 8: Copy constructor (MyStruct)." << RESET << std::endl;
        std::cout << array6;

        // Assignment operator test for custom struct
        Array<MyStruct> array7;
        array7 = array5;
        std::cout << GREEN_BG_BLACK_FG << "Test 9: Assignment operator (MyStruct)." << RESET << std::endl;
        std::cout << array7;

        // Test array with size 0 (for MyStruct)
        Array<MyStruct> emptyArray(0);
        std::cout << GREEN_BG_BLACK_FG << "Test 10: Array of size 0 (MyStruct)." << RESET << std::endl;
        std::cout << emptyArray;

    } catch (const std::exception& e) {
        std::cout << RED << "\n----------------------------------------" RESET << std::endl;
        std::cout << RED << "An error occurred: " << e.what() << RESET << std::endl;
        std::cout << RED << "Array class tests failed" << RESET << std::endl;
        return 0;
    }

    std::cout << GREEN << "-- Array class tests successful! --" << RESET << std::endl;
    return 0;
}
