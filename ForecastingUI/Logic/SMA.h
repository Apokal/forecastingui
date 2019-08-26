#pragma once
#include <iostream>
#include <vector>

#include "quantitativemethodbase.h"

namespace Quantitative
{
    class QSMAQuntitativeMethod : public QQuantitativeMethodBase
    {
    public:

        struct Settings
        {
            unsigned int period = 0;
        };

        QSMAQuntitativeMethod (const Settings& settings)
            : QQuantitativeMethodBase("SMA"),
              m_settings(settings)
        {}
        virtual ~QSMAQuntitativeMethod() {}

        virtual std::vector<float> run(std::vector<float> initVector, size_t forecast_range)
        {
            std::vector<float> resultVector;

            // Number of previous values taken for one new forecast
            // int historicalData = m_settings.period;
            int historicalData = 60;

            // Number of values in future forecast
            // int numForFutureForecast = m_settings.numForFutureForecast;
            int numForFutureForecast = 30;

            std::cout << "Kalkulacja SMA..." << std::endl;

            for (int i = 0; i < numForFutureForecast; i++)
            {
                float sum = 0;
                int x = 0;

                for (int j = initVector.size() - historicalData + i; j < initVector.size() + i; j++) {
                    sum += initVector[initVector.size() - historicalData + x];
                    x++;
                }

                auto avg = sum / historicalData;
                resultVector.push_back(avg);
                initVector.push_back(avg);

            }

            std::cout << "Obliczenia SMA sie skonczyly" << std::endl;

            return resultVector;
        }

    private:
        Settings m_settings;
    };
}
