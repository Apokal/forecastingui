#ifndef QTMASETTINGSWIDGET_H
#define QTMASETTINGSWIDGET_H

#include <QWidget>

namespace Ui {
class QTMASettingsWidget;
}

class QTMASettingsWidget : public QWidget
{
    Q_OBJECT

public:
    explicit QTMASettingsWidget(QWidget *parent = nullptr);
    ~QTMASettingsWidget();

    bool useMethod() const;
    int period() const;

private:
    Ui::QTMASettingsWidget *ui;
};

#endif // QTMASETTINGSWIDGET_H
