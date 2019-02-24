#pragma once
#include <vector>

namespace Logic
{
    class QInputGenerator
    {
    public:
        std::vector<float> generate(size_t size, float min, float max, int precision = 2)
        {
            float random_number;

            std::vector<float> randomVector;
            randomVector.reserve(size);
            size_t a = 0;
            while (a < size)
            {
                a++;
                random_number = random_float(min, max);
                random_number = round(random_number, precision);
                randomVector.push_back(random_number);
            }

            return randomVector;
        }

        std::vector<float> generate_old(size_t size)
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

    private:
        float random_float(float a, float b)
        {
            float random = (static_cast<float>(rand())) / static_cast<float>(RAND_MAX);
            float diff = b - a;
            float r = random * diff;
            return a + r;
        }

        float round(float num, int precision)
        {
            float multiplicator = static_cast<float>(std::pow(10, precision));
            float rounded = (int)(num * multiplicator)/multiplicator;
            return rounded;
        }
    };
}
