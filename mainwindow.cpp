#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // przygotowanie widgetu VTK do działania
    renderer = vtkSmartPointer<vtkRenderer>::New();
    renWin = ui->qvtkWidget->GetRenderWindow();
    renWin->AddRenderer(renderer);

    newVtkPipe();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::newVtkPipe()
{
    // przykładowy kod VTK
    source = vtkConeSource::New();
    source->SetHeight( 3.0 );
    source->SetRadius( 1.0 );
    source->SetResolution( 10 );

    mapper = vtkPolyDataMapper::New();
    mapper->SetInputConnection( source->GetOutputPort() );

    actor = vtkActor::New();
    actor->SetMapper( mapper );

    renderer->AddActor(actor);
    renderer->SetBackground(0.1, 0.2, 0.4);

    // sprzątanie obiektów VTK
    source->Delete();
    mapper->Delete();
    actor->Delete();
}
