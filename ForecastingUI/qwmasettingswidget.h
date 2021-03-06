#ifndef QWMASETTINGSWIDGET_H
#define QWMASETTINGSWIDGET_H

#include <QWidget>

namespace Ui {
class QWMASettingsWidget;
}

class QWMASettingsWidget : public QWidget
{
    Q_OBJECT

public:
    explicit QWMASettingsWidget(QWidget *parent = nullptr);
    ~QWMASettingsWidget();

    bool useMethod() const;
    std::vector<float> weights() const;

private:
    Ui::QWMASettingsWidget *ui;
};

#endif // QWMASETTINGSWIDGET_H
