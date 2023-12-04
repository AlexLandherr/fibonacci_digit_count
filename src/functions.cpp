#include "include/functions.h"
#include <string>

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

namespace func {
    std::string add_num_str(std::string &str1, std::string &str2) {
        std::string result;
        //Making sure number strings are equally long.
        if (str1.length() > str2.length()) {
            str2.insert(0, (str1.length() - str2.length()), '0');
        } else if (str2.length() > str1.length()) {
            str1.insert(0, (str2.length() - str1.length()), '0');
        }

        //Adding number strings together, one digit at a time from right to left.
        int carry = 0;
        for (int i = static_cast<int>(str1.length()) - 1; i >= 0; i--) {
            std::string digit_1 = str1.substr(i, 1);
            std::string digit_2 = str2.substr(i, 1);
            result.insert(0, std::to_string((std::stoi(digit_1) + std::stoi(digit_2) + carry) % 10));
            //std::cout << "i: " << i << " digit_1: " << digit_1 << " digit_2: " << digit_2 << " temp_sum: " << (std::stoi(digit_1) + std::stoi(digit_2) + carry) << " carry: " << carry << '\n';
            carry = (std::stoi(digit_1) + std::stoi(digit_2) + carry) / 10;
        }

        //Prepend the final carry value to the result std::string.
        //std::cout << "carry after loop exit: " << carry << '\n';
        if (carry > 0) {
            result.insert(0, std::to_string(carry));
        }

        return result;
    }
}