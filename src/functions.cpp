#include "include/functions.h"
#include <string>
#include <vector>
#include <stdexcept>
#include <cstdint>
#include <iostream>

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

    std::string nth_fibonacci_num(int nth_num) {
        if (nth_num < 1) {
            throw std::invalid_argument("Argument 'nth_num' is less than 1; must be greater than 1!");
        } else if (nth_num >= 1 && nth_num <= 2) {
            return "1";
        } else {
            std::vector<std::string> all_fibo = {"1", "1"};
            int loop_count = 2;

            while (loop_count < nth_num) {
                std::string F_n = add_num_str(all_fibo[loop_count - 1], all_fibo[loop_count - 2]);
                all_fibo.push_back(F_n);
                loop_count++;
            }

            return all_fibo.back();
        }
    }

    uint64_t first_fibo_num_with_n_digits(uint64_t n) {
        uint64_t counter = 1;
        while (true) {
            //std::string temp_result = nth_fibonacci_num(counter);
            uint64_t str_length = static_cast<uint64_t>(nth_fibonacci_num(counter).length());
            if (str_length == n) {
                break;
            }
            std::cout << "counter: " << counter << " length: " << str_length << '\n';
            counter++;
        }

        return counter;
    }
}