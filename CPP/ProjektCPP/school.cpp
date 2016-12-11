#include "school.h"
#include "ui_school.h"




School::School(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::School)
{
    ui->setupUi(this);
    Connect();
}

School::~School()
{
    delete ui;
}
