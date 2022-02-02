#include "dimensiondialog.h"
#include "ui_dimensiondialog.h"

DimensionDialog::DimensionDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DimensionDialog)
{
    ui->setupUi(this);
}

DimensionDialog::~DimensionDialog()
{
    delete ui;
}
