#include "qtmasettingswidget.h"
#include "ui_qtmasettingswidget.h"

QTMASettingsWidget::QTMASettingsWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QTMASettingsWidget)
{
    ui->setupUi(this);
}

QTMASettingsWidget::~QTMASettingsWidget()
{
    delete ui;
}

bool QTMASettingsWidget::useMethod() const
{
    return ui->useMethod_ChkBox->isChecked();
}

int QTMASettingsWidget::period() const
{
    return ui->period_SpnBox->value();
}
