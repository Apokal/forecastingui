#pragma once
#include <iostream>
#include <vector>

#include "quantitativemethodbase.h"

namespace Quantitative
{
    class QTMAQuntitativeMethod : public QQuantitativeMethodBase
    {
    public:

        struct Settings
        {
            int period = 0;
        };

        QTMAQuntitativeMethod (const Settings& settings)
            : QQuantitativeMethodBase("TMA"),
              m_settings(settings)
        {}
        virtual ~QTMAQuntitativeMethod() {}

        virtual std::vector<float> run(std::vector<float> initVector, size_t forecast_range)
        {
            std::vector<float> resultSMAVector;
            std::vector<float> resultTMAVector;

            // Number of previous values taken for one new forecast
            // int historicalData = m_settings.period;
            int historicalData = 60;

            // Number of values in future forecast
            // int numForFutureForecast = m_settings.numForFutureForecast;
            int numForFutureForecast = 30;

            std::cout << "Kalkulacja TMA..." << std::endl;

            for (int i = 0; i < numForFutureForecast; i++) {
                float sum = 0;
                int x = 0;

                for (int j = initVector.size() - historicalData + i; j < initVector.size() + i; j++) {
                    sum += initVector[initVector.size() - historicalData + x];
                    x++;
                }

                auto avg = sum / historicalData;
                resultSMAVector.push_back(avg);
                initVector.push_back(avg);
            }

            int x = 0;
            for (int i = 0; i < numForFutureForecast; i++) {
                float sum = 0;

                for(int i = 0 + x; i < resultSMAVector.size(); i++) {
                    sum += resultSMAVector[i];
                }

                sum = sum / (resultSMAVector.size() - x);
                x++;

                resultTMAVector.push_back(sum);
                resultSMAVector.push_back(sum);

            }

            std::cout << "Obliczenia TMA sie skonczyly" << std::endl;
            return resultTMAVector;
        }

    private:
        Settings m_settings;
    };
}
