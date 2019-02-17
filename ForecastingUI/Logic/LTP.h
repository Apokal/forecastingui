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

        };

        QLTPQuntitativeMethod (const Settings& settings)
            : QQuantitativeMethodBase("LTP"),
              m_settings(settings)
        {}
        virtual ~QLTPQuntitativeMethod() {}

        virtual std::vector<float> Run(std::vector<float> initVector)
        {
            std::vector<float> results;
            unsigned int limit = 10;
            float xSum = 0;
            float ySum = 0;
            float xySum = 0;
            float xSqrSum = 0;

            std::cout << "Kalkulacja LTP..." << std::endl;

            for (unsigned int i = 0; i < limit; i++) {
                xSum += i+1;
                ySum += initVector[i];
                xySum += (i + 1) * initVector[i];
                xSqrSum += (i + 1) * (i + 1);
            }

            float intercept = ((xSqrSum * ySum) - (xSum * xySum)) /
                              ((limit * xSqrSum) - (xSum * xSum));

            float slope = ((limit * xySum) - (xSum * ySum)) /
                          ((limit * xSqrSum) - (xSum * xSum));

            for (unsigned int i = 0; i < initVector.size(); i++) {
                if (i < limit) {
                    results.push_back(initVector[i]);
                }
                else {
                    float val = intercept + slope * i;
                    results.push_back(val);
                }
            }

            return results;
        }

    private:
        Settings m_settings;
    };
}
