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

        virtual std::vector<float> run(std::vector<float> initVector)
        {
            std::vector<float> resultVector;
            // Number of forecasted values
            int numForFutureForecast = 3;
            // Number of previous values taken for one new forecast
            int period = m_settings.period;

            double sum = 0;

            std::cout << "Kalkulacja SMA..." << std::endl;

            for (int i = initVector.size() - period; i < initVector.size(); i++) {
                resultVector.push_back(initVector[i]);
            }

            for (int i = 0; i < numForFutureForecast; i++) {
                for (int j = 0; j < period ; j++) {
                    sum += resultVector[i + j];
                }
                auto avg = sum / period;
                resultVector.push_back(avg);
                sum = 0;
            }

            std::cout << "Obliczenia SMA sie skonczyly" << std::endl;
            return resultVector;
        }

    private:
        Settings m_settings;
    };
}
