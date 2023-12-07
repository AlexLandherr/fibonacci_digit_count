#include <string>
#include <cstdint>

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

namespace func {
    std::string add_num_str(std::string &str1, std::string &str2);
    std::string nth_fibonacci_num(int nth_num);
    uint64_t first_fibo_num_with_n_digits(uint64_t n);
}

#endif