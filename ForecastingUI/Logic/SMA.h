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
            int period = m_settings.period; // How much of InitVector values should be taken as historical data for future forecast
            double sum = 0;

            std::cout << "Kalkulacja SMA..." << std::endl;

            for (int i = 0; i < period; i++) {
                resultVector.push_back(initVector[i]);
            }

            for (int i = 0; i < initVector.size(); i++) {
                for (int j = 0; j < period; j++) {
                    sum += resultVector[i + j];
                }
                resultVector.push_back(sum / period);
                sum = 0;
            }

            std::cout << "Obliczenia SMA sie skonczyly" << std::endl;
            return resultVector;
        }

    private:
        Settings m_settings;
    };
}
