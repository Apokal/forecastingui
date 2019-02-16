#ifndef QMODELLOGIC_H
#define QMODELLOGIC_H

#include <vector>
#include <functional>
#include <map>
#include <string>
#include <chrono>

namespace Logic
{
    class QModelLogic
    {
    public:
        QModelLogic();

        void Run();
        std::map<std::string, std::chrono::milliseconds> last_exec_time();

    private:
        std::chrono::milliseconds RunEntry(std::vector<float> initVector, std::map<std::string, std::function<std::vector<float>(std::vector<float>)>> forecastMap, std::string forecastType);

        std::map<std::string, std::chrono::milliseconds> m_last_exec_time;
    };

}

#endif // QMODELLOGIC_H
