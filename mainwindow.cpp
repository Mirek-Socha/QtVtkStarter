#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    vtkSmartPointer<vtkRenderer> renderer =
            vtkSmartPointer<vtkRenderer>::New();

    ui->qvtkWidget->GetRenderWindow()->AddRenderer(renderer);

}

MainWindow::~MainWindow()
{
    delete ui;
}
