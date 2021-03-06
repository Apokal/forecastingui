#ifndef QQUANTITATIVEMETHODBASE_H
#define QQUANTITATIVEMETHODBASE_H

#include <string>
#include <vector>

namespace Quantitative
{
    class QQuantitativeMethodBase
    {
        public:
            QQuantitativeMethodBase(const std::string& name)
                : m_name(name)
            { }

            virtual ~QQuantitativeMethodBase() { }

            virtual std::vector<float> run(std::vector<float> initVector, size_t history_range, size_t forecast_range) = 0;

            const std::string& name() { return m_name; }

        private:
            std::string m_name;
    };
}

#endif // QQUANTITATIVEMETHODBASE_H
