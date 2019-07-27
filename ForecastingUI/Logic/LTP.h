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

        virtual std::vector<float> run(std::vector<float> initVector, size_t forecast_range)
        {
            std::vector<float> resultVector;
            int period = m_settings.period;;
            float xSum = 0;
            float ySum = 0;
            float xySum = 0;
            float xSqrSum = 0;

            std::cout << "Kalkulacja LTP..." << std::endl;

            for (int i = 0; i < period; i++) {
                xSum += i+1;
                ySum += initVector[i];
                xySum += (i + 1) * initVector[i];
                xSqrSum += (i + 1) * (i + 1);
            }

            float intercept = ((xSqrSum * ySum) - (xSum * xySum)) /
                              ((period * xSqrSum) - (xSum * xSum));

            float slope = ((period * xySum) - (xSum * ySum)) /
                          ((period * xSqrSum) - (xSum * xSum));

            for (int i = 0; i < initVector.size(); i++) {
                float val = intercept + slope * (i + 1);
                resultVector.push_back(val);
            }

            std::cout << "Obliczenia LTP sie skonczyly" << std::endl;
            return resultVector;
        }

    private:
        Settings m_settings;
    };
}
