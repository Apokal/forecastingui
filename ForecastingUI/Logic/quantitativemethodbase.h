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

            virtual std::vector<float> Run(std::vector<float> initVector) = 0;

            const std::string& name() { return m_name; }

        private:
            std::string m_name;
    };
}

#endif // QQUANTITATIVEMETHODBASE_H
