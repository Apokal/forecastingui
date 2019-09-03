#pragma once
#include <iostream>
#include <vector>

#include "quantitativemethodbase.h"

namespace Quantitative
{
    class QLTPQuntitativeMethod : public QQuantitativeMethodBase
    {
    public:

        struct Settings
        {
            unsigned int period = 0;
        };

        QLTPQuntitativeMethod (const Settings& settings)
            : QQuantitativeMethodBase("LTP"),
              m_settings(settings)
        {}
        virtual ~QLTPQuntitativeMethod() {}

        virtual std::vector<float> run(std::vector<float> initVector, size_t history_range, size_t forecast_range)
        {
            std::vector<float> resultVector;

            // Number of previous values taken for one new forecast
            size_t historicalData = history_range;

            // Number of values in future forecast
            size_t numForFutureForecast = forecast_range;

            float xSum = 0;
            float ySum = 0;
            float xySum = 0;
            float xSqrSum = 0;

            std::cout << "Kalkulacja LTP..." << std::endl;

            for (int i = initVector.size() - historicalData; i < initVector.size(); i++) {
                //resultVector.push_back(initVector[i]);

                xSum += i+1;
                ySum += initVector[i];
                xySum += (i + 1) * initVector[i];
                xSqrSum += (i + 1) * (i + 1);
            }

            float intercept = ((xSqrSum * ySum) - (xSum * xySum)) /
                              ((historicalData * xSqrSum) - (xSum * xSum));

            float slope = ((historicalData * xySum) - (xSum * ySum)) /
                          ((historicalData * xSqrSum) - (xSum * xSum));

            for (int i = 1; i < numForFutureForecast + 1; i++) {
                float val = intercept + slope * i;
                resultVector.push_back(val);
            }

            std::cout << "Obliczenia LTP sie skonczyly" << std::endl;
            return resultVector;
        }

    private:
        Settings m_settings;
    };
}
