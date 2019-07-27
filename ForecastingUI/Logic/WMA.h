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

        virtual std::vector<float> run(std::vector<float> initVector, size_t forecast_range)
        {
            std::vector<float> resultVector;
            std::vector<float> weights = m_settings.weights;
            float sum = 0;
            unsigned int period = static_cast<unsigned int>(weights.size());

            std::cout << "Kalkulacja WMA..." << std::endl;

            for (unsigned int i = 0; i < initVector.size(); i++)
            {
                resultVector.push_back(initVector[i]);
            }

            for (unsigned int i = 0; i < initVector.size(); i++)
            {
                for (unsigned int j = 0; j < period; j++)
                {
                    sum += resultVector[i + j] * weights[j];
                }

                resultVector.push_back(sum);
                sum = 0;
            }

            return resultVector;
        }

    private:
        Settings m_settings;
    };
}
