#ifndef QLTPSETTINGSWIDGET_H
#define QLTPSETTINGSWIDGET_H

#include <QWidget>

namespace Ui {
class QLTPSettingsWidget;
}

class QLTPSettingsWidget : public QWidget
{
    Q_OBJECT

public:
    explicit QLTPSettingsWidget(QWidget *parent = nullptr);
    ~QLTPSettingsWidget();

    bool useMethod() const;
    int period() const;

private:
    Ui::QLTPSettingsWidget *ui;
};

#endif // QLTPSETTINGSWIDGET_H
