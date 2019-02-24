#include "qsmasettingswidget.h"
#include "ui_qsmasettingswidget.h"

QSMASettingsWidget::QSMASettingsWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QSMASettingsWidget)
{
    ui->setupUi(this);
}

QSMASettingsWidget::~QSMASettingsWidget()
{
    delete ui;
}


bool QSMASettingsWidget::useMethod() const
{
    return ui->useMethodCheckBox->isChecked();
}

int QSMASettingsWidget::periodValue() const
{
    return ui->smaPeriodSpinBox->value();
}
