#include <string>
#include <cstdint>

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

namespace func {
    std::string add_num_str(std::string &str1, std::string &str2);
    uint64_t first_fibo_num_with_n_digits(uint64_t length);
    /* uint64_t first_fibo_num_with_n_digits(uint64_t n); */
}

#endif