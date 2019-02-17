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

        };

        QSMAQuntitativeMethod (const Settings& settings)
            : QQuantitativeMethodBase("SMA"),
              m_settings(settings)
        {}
        virtual ~QSMAQuntitativeMethod() {}

        virtual std::vector<float> Run(std::vector<float> initVector)
        {
            std::vector<float> resultVector;
            unsigned int length = 5; // Liczba okresow
            float sum = 0;
            unsigned int counter = 0;

            std::cout << "Kalkulacja SMA..." << std::endl;

            for (unsigned int i = 0; i < initVector.size(); i++) {
                sum += initVector[i];
                counter++;
                if (counter >= length) {
                    resultVector.push_back(sum / length);
                    sum -= initVector[counter - length];
                }
            }

            std::cout << "Obliczenia SMA sie skonczyly" << std::endl;
            return resultVector;
        }

    private:
        Settings m_settings;
    };
}
