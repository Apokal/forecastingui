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

        virtual std::vector<float> Run(std::vector<float> initVector)
        {
            std::vector<float> resultVector;
            unsigned int period = 3;

            float calcValue = 0; // weightened, calculated value
            unsigned int j_inc = 0; // calc loop helpers for calcValue
            unsigned int period_inc = period;
            unsigned int w_inc = 0;

            std::cout << "Kalkulacja WMA..." << std::endl;

            for (unsigned int i = 0; i < period; i++)
            {
                resultVector.push_back(initVector[i]);
            }

            auto weights = m_settings.weights;
            for (unsigned int i = period; i < initVector.size(); i++) {
                for (unsigned int j = j_inc; j < period_inc; j++) {
                    if (w_inc % period == 0)
                        w_inc = 0;
                    calcValue += initVector[j] * weights[w_inc];
                    j_inc++;
                    period_inc++;
                    w_inc++;
                    if (w_inc % period == 0) {
                        initVector[j_inc] = calcValue;
                        break;
                    }
                }
                resultVector.push_back(calcValue);
                calcValue = 0;
                j_inc = j_inc - period + 1;
                period_inc = period_inc - period;
                if (j_inc % period_inc == 0)
                    period_inc++;
                    w_inc = 0;
            }

            std::cout << "Obliczenia WMA sie skonczyly" << std::endl;
            return resultVector;
        }

    private:
        Settings m_settings;
    };
}
