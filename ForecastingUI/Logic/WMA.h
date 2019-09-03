#pragma once
#include <iostream>

#include "quantitativemethodbase.h"

namespace Quantitative
{
    class QWMAQuntitativeMethod : public QQuantitativeMethodBase
    {
    public:

        struct Settings
        {
             std::vector<float> weights;
        };

        QWMAQuntitativeMethod (const Settings& settings)
            : QQuantitativeMethodBase("WMA"),
              m_settings(settings)
        {}
        virtual ~QWMAQuntitativeMethod() {}

        virtual std::vector<float> run(std::vector<float> initVector, size_t history_range, size_t forecast_range)
        {
            std::vector<float> resultVector;
            std::vector<float> weights = m_settings.weights;

            // Number of previous values taken for one new forecast
            unsigned int historicalData = static_cast<unsigned int>(weights.size());

            // Number of values in future forecast
            size_t numForFutureForecast = forecast_range;

            std::cout << "Kalkulacja WMA..." << std::endl;

            for (unsigned int i = 0; i < numForFutureForecast; i++) {
                float sum = 0;
                int x = 0;

                for (int j = initVector.size() - historicalData + i; j < initVector.size() + i; j++) {
                    sum += initVector[initVector.size() - historicalData + x] * weights[x];
                    x++;
                }

                resultVector.push_back(sum);
                initVector.push_back(sum);
            }

            std::cout << "Obliczenia WMA sie skonczyly" << std::endl;
            return resultVector;
        }

    private:
        Settings m_settings;
    };
}
