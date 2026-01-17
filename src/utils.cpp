#include "utils.hpp"

#include <random>

std::vector<int> generate_random_vector(
    size_t size, int min_value, int max_value, unsigned int seed
) {
    std::vector<int> result;
    result.reserve(size);

    std::mt19937 gen(seed);
    std::uniform_int_distribution<int> dist(min_value, max_value);

    for (size_t i = 0; i < size; ++i) {
        result.push_back(dist(gen));
    }

    return result;
}
