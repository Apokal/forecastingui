#ifndef QMETHODSRESULTS_H
#define QMETHODSRESULTS_H

#include <QDialog>

namespace Ui {
class QMethodsResults;
}

class QMethodsResultsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit QMethodsResultsDialog(QWidget *parent = nullptr);
    ~QMethodsResultsDialog();

    void set_method_results(const std::map<std::string, std::vector<float>>& method_results);

private:
    void build_chart();

    Ui::QMethodsResults *ui;
    std::map<std::string, std::vector<float>> m_method_results;
};

#endif // QMETHODSRESULTS_H
