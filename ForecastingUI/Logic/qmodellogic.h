#ifndef QMODELLOGIC_H
#define QMODELLOGIC_H

#include <functional>
#include <map>
#include <string>
#include <chrono>

namespace Logic
{
    using QuantativeMethodsExecutionTime = std::map<std::string, std::chrono::milliseconds>;

    class QModelLogic
    {
    public:
        QModelLogic();

        void Run();
        QuantativeMethodsExecutionTime execution_time_resutls();

    private:
        //std::chrono::milliseconds RunEntry(std::vector<float> initVector, std::string quant_method_name, QuantativeMethod quant_method);

        QuantativeMethodsExecutionTime m_quant_meths_exec_time;
    };

}

#endif // QMODELLOGIC_H
