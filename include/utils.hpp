#pragma once

#include <vector>

std::vector<int> generate_random_vector(
    size_t size,
    int min_value = std::numeric_limits<int>::min(),
    int max_value = std::numeric_limits<int>::max(),
    unsigned int seed = 42
);
