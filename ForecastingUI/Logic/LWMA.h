#pragma once
#include <iostream>
#include <vector>

#include "quantitativemethodbase.h"

namespace Quantitative
{
    class QLWMAQuntitativeMethod : public QQuantitativeMethodBase
    {
    public:

        struct Settings
        {
            float period = 0.0f;
        };

        QLWMAQuntitativeMethod (const Settings& settings)
            : QQuantitativeMethodBase("LWMA"),
              m_settings(settings)
        {}
        virtual ~QLWMAQuntitativeMethod() {}

        virtual std::vector<float> run(std::vector<float> initVector)
        {
            std::vector<float> resultVector;
            int period = m_settings.period;
            float sum = 0;
            int weightSum = 0;

            std::cout << "Kalkulacja LWMA..." << std::endl;
            for (int j = 1; j <= period; j++)
            {
                weightSum += j;
                resultVector.push_back(initVector[j - 1]);
            }

            for (int i = 0; i < initVector.size(); i++)
            {
                for (int j = 0; j < period; j++)
                {
                    sum += resultVector[i + j] * (j + 1);
                }
                resultVector.push_back(sum / weightSum);
                sum = 0;
            }

            std::cout << "Obliczenia LWMA sie skonczyly" << std::endl;
            return resultVector;
        }

    private:
        Settings m_settings;
    };
}

