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
            int period = 0;
        };

        QLWMAQuntitativeMethod (const Settings& settings)
            : QQuantitativeMethodBase("LWMA"),
              m_settings(settings)
        {}
        virtual ~QLWMAQuntitativeMethod() {}

        virtual std::vector<float> run(std::vector<float> initVector, size_t forecast_range)
        {
            std::vector<float> resultVector;
            // Number of previous values taken for one new forecast
            // int historicalData = m_settings.period;
            int historicalData = 60;

            // Number of values in future forecast
            // int numForFutureForecast = m_settings.numForFutureForecast;
            int numForFutureForecast = 30;

            std::cout << "Kalkulacja LWMA..." << std::endl;

            for (int i = 0; i < numForFutureForecast; i++) {
                float sum = 0;
                int weightSum = 0;
                int x = 0;

                for (int j = initVector.size() - historicalData + i; j < initVector.size() + i; j++)
                {
                    weightSum += x + 1;
                    sum += initVector[initVector.size() - historicalData + x] * (x + 1);
                    x++;
                }

                resultVector.push_back(sum / weightSum);
                initVector.push_back(sum / weightSum);
            }

            std::cout << "Obliczenia LWMA sie skonczyly" << std::endl;
            return resultVector;
        }

    private:
        Settings m_settings;
    };
}

