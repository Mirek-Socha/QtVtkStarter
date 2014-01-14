#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // przygotowanie widgetu VTK do działania
    vtkSmartPointer<vtkRenderer> renderer =
            vtkSmartPointer<vtkRenderer>::New();

    ui->qvtkWidget->GetRenderWindow()->AddRenderer(renderer);

    // przykładowy kod VTK
    vtkConeSource *cone = vtkConeSource::New();
    cone->SetHeight( 3.0 );
    cone->SetRadius( 1.0 );
    cone->SetResolution( 10 );

    vtkPolyDataMapper *coneMapper = vtkPolyDataMapper::New();
    coneMapper->SetInputConnection( cone->GetOutputPort() );

    vtkActor *coneActor = vtkActor::New();
    coneActor->SetMapper( coneMapper );

    renderer->AddActor(coneActor);
    renderer->SetBackground(0.1, 0.2, 0.4);

    // sprzątanie obiektów VTK
    cone->Delete();
    coneMapper->Delete();
    coneActor->Delete();
}

MainWindow::~MainWindow()
{
    delete ui;
}
