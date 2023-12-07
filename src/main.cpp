#include "include/functions.h"
#include <iostream>
#include <string>
#include <stdexcept>
#include <cstdint>

/*
The Fibonacci sequence is defined by the recurrence relation:

F_n = F_n-1 + F_n-2, where F_1 = 1 and F_2 = 1.

Hence the first 12 terms will be:

F_1 = 1
F_2 = 1
F_3 = 2
F_4 = 3
F_5 = 5
F_6 = 8
F_7 = 13
F_8 = 21
F_9 = 34
F_10 = 55
F_11 = 89
F_12 = 144

The 12th term, F_12, is the first term to contain 3 digits.

What is the index of the first term in the Fibonacci sequence to contain 1000 digits?
*/

int main() {
    /* std::string str1 = "265";
    std::string str2 = "911";
    std::cout << func::add_num_str(str1, str2) << '\n'; */
    /* try {
        for (int i = 1; i <= 12; i++) {
            std::cout << func::nth_fibonacci_num(i) << '\n';
        }
    } catch (const std::invalid_argument& ex) {
        std::cout << ex.what() << '\n';
    } catch (const std::exception& ex) {
        std::cout << ex.what() << '\n';
    } */
    uint64_t digit_count = 1000;
    std::cout << "The index (starting from 1) of the first term in the Fibonacci sequence to contain " << digit_count << " digit(s) is:" << '\n';
    std::cout << func::first_fibo_num_with_n_digits(digit_count) << '\n';

    return 0;
}