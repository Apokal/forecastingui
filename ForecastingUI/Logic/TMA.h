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

        virtual std::vector<float> run(std::vector<float> initVector)
        {
            std::vector<float> resultSMAVector;
            std::vector<float> resultTMAVector;
            int period = m_settings.period;
            double sum = 0;

            std::cout << "Kalkulacja TMA..." << std::endl;
            // first call SMA on initVector to fill resultVector
            for (int i = 0; i < initVector.size(); i++) {
                if (i < period) {
                    resultSMAVector.push_back(initVector[i]);
                }
                else {
                    resultSMAVector.push_back(sum / period);
                    sum -= initVector[i - period];
                }

                sum += initVector[i];
            }

            // then call SMA again but now on resultVector
            sum = 0;
            for (int i = 0; i < resultSMAVector.size(); i++) {
                if (i < period) {
                    resultTMAVector.push_back(resultSMAVector[i]);
                }
                else {
                    resultTMAVector.push_back(sum / period);
                    sum -= resultSMAVector[i - period];
                }

                sum += resultSMAVector[i];
            }

            std::cout << "Obliczenia TMA sie skonczyly" << std::endl;
            return resultTMAVector;
        }

    private:
        Settings m_settings;
    };
}
