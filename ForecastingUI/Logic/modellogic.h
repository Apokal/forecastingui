#ifndef QMODELLOGIC_H
#define QMODELLOGIC_H

#include <map>
#include <string>
#include <chrono>
#include <vector>

namespace Quantitative {
    class QQuantitativeMethodBase;
}

namespace Logic
{
    using QuantativeMethodsExecutionTime = std::map<std::string, std::chrono::milliseconds>;
    using QuantitativeMethodPtr = std::unique_ptr<Quantitative::QQuantitativeMethodBase>;

    class QModelLogic
    {
    public:
        QModelLogic();

        void AddQuantitativeMethod(QuantitativeMethodPtr pmethod);
        void Run();
        QuantativeMethodsExecutionTime execution_time_resutls();

    private:
        std::chrono::milliseconds ExecuteMethod(Quantitative::QQuantitativeMethodBase* pmethod, std::vector<float> initVector);

        std::vector<QuantitativeMethodPtr>  m_quant_methods;
        QuantativeMethodsExecutionTime      m_quant_meths_exec_time;
    };

}

#endif // QMODELLOGIC_H
