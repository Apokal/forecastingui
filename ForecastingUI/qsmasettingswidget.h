#ifndef QSMASETTINGSWIDGET_H
#define QSMASETTINGSWIDGET_H

#include <QWidget>

namespace Ui {
class QSMASettingsWidget;
}

class QSMASettingsWidget : public QWidget
{
    Q_OBJECT

public:
    explicit QSMASettingsWidget(QWidget *parent = nullptr);
    ~QSMASettingsWidget();

    bool useMethod() const;
    int periodValue() const;

private:
    Ui::QSMASettingsWidget *ui;
};

#endif // QSMASETTINGSWIDGET_H
