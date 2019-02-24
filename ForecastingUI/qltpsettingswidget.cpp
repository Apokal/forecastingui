#include "qltpsettingswidget.h"
#include "ui_qltpsettingswidget.h"

QLTPSettingsWidget::QLTPSettingsWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QLTPSettingsWidget)
{
    ui->setupUi(this);
}

QLTPSettingsWidget::~QLTPSettingsWidget()
{
    delete ui;
}

bool QLTPSettingsWidget::useMethod() const
{
    return ui->useMethod_ChkBox->isChecked();
}

int QLTPSettingsWidget::period() const
{
    return ui->period_SpnBox->value();
}
