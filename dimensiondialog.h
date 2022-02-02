#ifndef DIMENSIONDIALOG_H
#define DIMENSIONDIALOG_H

#include <QDialog>

namespace Ui {
class DimensionDialog;
}

class DimensionDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DimensionDialog(QWidget *parent = nullptr);
    ~DimensionDialog();

private:
    Ui::DimensionDialog *ui;
};

#endif // DIMENSIONDIALOG_H
