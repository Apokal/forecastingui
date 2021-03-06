#ifndef QESSETTINGSWIDGET_H
#define QESSETTINGSWIDGET_H

#include <QWidget>

namespace Ui {
class QESSettingsWidget;
}

class QESSettingsWidget : public QWidget
{
    Q_OBJECT

public:
    explicit QESSettingsWidget(QWidget *parent = nullptr);
    ~QESSettingsWidget();

    bool useMethod() const;
    double smoothConstant() const;

private:
    Ui::QESSettingsWidget *ui;
};

#endif // QESSETTINGSWIDGET_H
