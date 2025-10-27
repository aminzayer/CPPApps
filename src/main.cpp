#include <iostream>
#include <vector>
#include <cassert>
#include "ciphers/CaesarCipher.h"
#include "string_utils/StringUtils.h"
#include "stats/RealtimeStats.h"

using namespace statistics;

void test_function(const float *test_data, const int number_of_samples) {
    float mean = 0.f, variance = 0.f;

    stats_computer1<float> stats01;
    stats_computer2<float> stats02;

    for (int i = 0; i < number_of_samples; i++) {
        stats01.new_val(test_data[i]);
        stats02.new_val(test_data[i]);
        mean += test_data[i];
    }

    mean /= number_of_samples;

    for (int i = 0; i < number_of_samples; i++) {
        float temp = test_data[i] - mean;
        variance += temp * temp;
    }
    variance /= number_of_samples;

    std::cout << "<<<<<<<< Test Function >>>>>>>>" << std::endl
              << "Expected: Mean: " << mean << "\t Variance: " << variance
              << std::endl;
    std::cout << "\tMethod 1:"
              << "\tMean: " << stats01.mean()
              << "\t Variance: " << stats01.variance()
              << "\t Std: " << stats01.std() << std::endl;
    std::cout << "\tMethod 2:"
              << "\tMean: " << stats02.mean()
              << "\t Variance: " << stats02.variance()
              << "\t Std: " << stats02.std() << std::endl;

    assert(std::abs(stats01.mean() - mean) < 0.01);
    assert(std::abs(stats02.mean() - mean) < 0.01);
    assert(std::abs(stats02.variance() - variance) < 0.01);

    std::cout << "(Tests passed)" << std::endl;
}

int main() {
    // Demonstrate CaesarCipher
    CaesarCipher cipher("Vjg Cki");
    std::cout << "Decrypted text: " << cipher.decrypt() << std::endl;

    // Demonstrate StringUtils
    std::string text = "Hello, world!";
    std::string sub = "world";
    std::cout << "Position of '" << sub << "' in '" << text << "': "
              << StringUtils::findstr(text, sub) << std::endl;

    // Demonstrate RealtimeStats
    const float test_data1[] = {3, 4, 5, -1.4, -3.6, 1.9, 1.};
    test_function(test_data1, sizeof(test_data1) / sizeof(test_data1[0]));

    return 0;
}
