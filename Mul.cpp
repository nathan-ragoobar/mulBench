#include <iostream>
#include <chrono>
#include "./fixed_point.hpp"


void floatMul(){

    float num1 = 1.5;
    float num2 = 2.5;

    for(int j=1; j<=1000;j = j*10){

    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < 1000*j; ++i) {
        float result = num1 * num2;
        //std::cout << "Multiplication of " << num1 << " and " << num2 << " is: " << result << std::endl;
        num1 += 1.0; // Increment num1 by 1.0
        num2 += 1.0; // Increment num2 by 1.0
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;

    std::cout << "Time taken " << 1000*j << " loops: " << elapsed.count() << " seconds" << std::endl;

    }

}

void intMul(){
    
    int num1 = 1;
    int num2 = 2;

    for(int j=1; j<=1000; j = j*10){

    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < 1000*j; ++i) {
        int result = num1 * num2;
        //std::cout << "Multiplication of " << num1 << " and " << num2 << " is: " << result << std::endl;
        num1 += 1; // Increment num1 by 1
        num2 += 1; // Increment num2 by 1
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;

    std::cout << "Time taken " << 1000*j << " loops: " << elapsed.count() << " seconds" << std::endl;

    }
}

void fixedMul(){

    FixedPointQ5_10 num1(1.5);
    FixedPointQ5_10 num2(2.5);

    for(int j=1; j<=1000; j = j*10){

    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < 1000*j; ++i) {
        FixedPointQ5_10 result = num1 * num2;
        //std::cout << "Multiplication of " << num1 << " and " << num2 << " is: " << result << std::endl;
        num1 += 1.0; // Increment num1 by 1.0
        num2 += 1.0; // Increment num2 by 1.0
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;

    std::cout << "Time taken " << 1000*j << " loops: " << elapsed.count() << " seconds" << std::endl;

    }
}

int main() {

    std::cout << "Float Multiplication" << std::endl;
    floatMul();

    std::cout << "Fixed Point Multiplication" << std::endl;
    fixedMul();

    std::cout << "Int Multiplication" << std::endl;
    intMul();
    
    return 0;
}