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
            result.insert(0, std::to_string(((str1[i] - 48) + (str2[i] - 48) + carry) % 10));
            carry = ((str1[i] - 48) + (str2[i] - 48) + carry) / 10;
        }

        //Prepend the final carry value to the result std::string.
        if (carry > 0) {
            result.insert(0, std::to_string(carry));
        }

        return result;
    }

    uint64_t first_fibo_num_with_n_digits(uint64_t length) {
        if (length < 1) {
            throw std::invalid_argument("Argument 'length' is less than 1; must be greater than 1!");
        } else {
            std::vector<std::string> nums = {"1", "1"};
            
            uint64_t counter = 3;
            while (true) {
                std::string sum = add_num_str(nums[0], nums[1]);
                if (static_cast<uint64_t>(sum.length()) >= length) {
                    break;
                }
                nums[0] = nums[1];
                nums[1] = sum;
                counter++;
            }

            return counter;
        }
    }
}