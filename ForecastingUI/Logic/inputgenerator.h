#pragma once
#include <vector>

namespace Logic
{
    class QInputGenerator
    {
    public:
        std::vector<float> generate(size_t size)
        {
            int random_number;

            std::vector<float> randomVector;
            randomVector.reserve(size);
            size_t a = 0;
            while (a < size)
            {
                a++;
                random_number = rand() % (20 - 10) + 10;
                randomVector.push_back(random_number);
            }

            return randomVector;
        }
    };
}
