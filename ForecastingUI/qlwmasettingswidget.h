#ifndef QLWMASETTINGSWIDGET_H
#define QLWMASETTINGSWIDGET_H

#include <QWidget>

namespace Ui {
class QLWMASettingsWidget;
}

class QLWMASettingsWidget : public QWidget
{
    Q_OBJECT

public:
    explicit QLWMASettingsWidget(QWidget *parent = nullptr);
    ~QLWMASettingsWidget();

    bool useMethod() const;
    int period() const;

private:
    Ui::QLWMASettingsWidget *ui;
};

#endif // QLWMASETTINGSWIDGET_H
