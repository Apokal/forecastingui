#include "qnumbersettingswidget.h"
#include "ui_qnumbersettingswidget.h"

QNumberSettingsWidget::QNumberSettingsWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QNumberSettingsWidget)
{
    ui->setupUi(this);
}

QNumberSettingsWidget::~QNumberSettingsWidget()
{
    delete ui;
}


int QNumberSettingsWidget::precision() const
{
    return ui->precision_SpnBox->value();
}

float QNumberSettingsWidget::min_value() const
{
    return ui->minVal_SpnBox->value();
}

float QNumberSettingsWidget::max_value() const
{
    return ui->maxVal_SpnBox->value();
}
