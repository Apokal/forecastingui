#include "qessettingswidget.h"
#include "ui_qessettingswidget.h"

QESSettingsWidget::QESSettingsWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QESSettingsWidget)
{
    ui->setupUi(this);
}

QESSettingsWidget::~QESSettingsWidget()
{
    delete ui;
}


bool QESSettingsWidget::useMethod() const
{
    return ui->useMethod->isChecked();
}

double QESSettingsWidget::smoothConstant() const
{
    return ui->smoothConstantSpinBox->value();
}
