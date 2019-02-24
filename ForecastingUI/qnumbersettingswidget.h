#ifndef QNUMBERSETTINGSWIDGET_H
#define QNUMBERSETTINGSWIDGET_H

#include <QWidget>

namespace Ui {
class QNumberSettingsWidget;
}

class QNumberSettingsWidget : public QWidget
{
    Q_OBJECT

public:
    explicit QNumberSettingsWidget(QWidget *parent = nullptr);
    ~QNumberSettingsWidget();

    int precision() const;
    float min_value() const;
    float max_value() const;

private:
    Ui::QNumberSettingsWidget *ui;
};

#endif // QNUMBERSETTINGSWIDGET_H
