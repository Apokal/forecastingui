#include "qlwmasettingswidget.h"
#include "ui_qlwmasettingswidget.h"

QLWMASettingsWidget::QLWMASettingsWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QLWMASettingsWidget)
{
    ui->setupUi(this);
}

QLWMASettingsWidget::~QLWMASettingsWidget()
{
    delete ui;
}


bool QLWMASettingsWidget::useMethod() const
{
    return ui->useMethod_ChkBox->isChecked();
}

int QLWMASettingsWidget::period() const
{
    return ui->period_SpnBox->value();
}
