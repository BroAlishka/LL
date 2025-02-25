#include "llo.hpp"
#include <iostream>
#include <string>


LongNumber computePiBBP(int precision) {
    LongNumber pi("0.0", precision); 
    LongNumber two("2.0", precision); 
    LongNumber one("1.0", precision); 
    LongNumber four("4.0", precision); 
    LongNumber five("5.0", precision); 
    LongNumber six("6.0", precision); 
    LongNumber eight("8.0", precision); 
    //LongNumber ans = four * four * four  * four * four;
    //std::cout << ans.toString() << std::endl;
    int iterations = 100;
        LongNumber denominator1 = one;
        LongNumber denominator2 = four;
        LongNumber denominator3 = five;
        LongNumber denominator4 = six;
         LongNumber term = (four / denominator1) - (two / denominator2) - (one / denominator3) - (one / denominator4);

        
        pi = pi + term;

        
        std::cout << "Iteration " << 1 << ", pi = " << pi.toString() << std::endl;
    for (int k = 1; k < iterations; ++k) {
        LongNumber k_term = LongNumber(std::to_string(k) + ".0", precision); 
                LongNumber denominator1 = eight * k_term + one;
        LongNumber denominator2 = eight * k_term + four;
        LongNumber denominator3 = eight * k_term + five;
        LongNumber denominator4 = eight * k_term + six;

        
        LongNumber term = (four / denominator1);
        term = term -(two / denominator2);
        term = term - (one / denominator3);
        term = term -(one / denominator4);
        
        LongNumber power = two.pow(4 * k); 
        term = term / power;

        
        pi = pi + term;

        
        std::cout << "Iteration " << k << ", pi = " << pi.toString() << std::endl;
    }

    return pi;
}
int main() {
        LongNumber pi = computePiBBP(100);

        // Выводим результат в десятичном виде
        std::cout << "Pi: " << pi.toDecimalString() << std::endl;

    return 0;
}