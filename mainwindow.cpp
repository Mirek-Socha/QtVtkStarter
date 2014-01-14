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

    // utworzenie strumienia VTK
    newVtkPipe();

    // łączenie sygnałów i slotów
    connect(ui->actionQt,SIGNAL(triggered()),
            qApp,SLOT(aboutQt()));

    // przesłanie informacji z Qt do VTK
    connect(ui->horizontalSlider,SIGNAL(valueChanged(int)),
            this,SLOT(setConeResolution(int)));

    // Zestawienie połączeń VTK->Gt:
    connections = vtkSmartPointer<vtkEventQtSlotConnect>::New();

    // przechwycenie zdarzeń VTK:
    connections->Connect(ui->qvtkWidget->GetInteractor(),
                         vtkCommand::LeftButtonPressEvent,
                         this,
                         SLOT(updateCamCoords(vtkObject*, unsigned long, void*, void*)));


    // debug poprawności połączeń VTK->Qt na konsolę:
    connections->PrintSelf(cout, vtkIndent());      // tak można sprawdzać dowolne obiekty VTK

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

void MainWindow::setConeResolution(int res)
{
    // zmiana nastaw obiektu VTK
    source->SetResolution(res);

    // wymuszenie rysowania widgetu Qt ze sceną VTK
    ui->qvtkWidget->repaint();
}

// przykład pobrania wsp. kamery
void MainWindow::updateCamCoords(vtkObject*, unsigned long, void*, void*)
{
    double camPosition[3];
    renderer->GetActiveCamera()->GetPosition(camPosition);

    QString str = QString("camera position: x=%1 : ty=%2 : z=%3")
                  .arg(camPosition[0], 0, 'f', 4)
                  .arg(camPosition[1], 0, 'f', 4)
                  .arg(camPosition[2], 0, 'f', 4);

    qDebug() << str;

    ui->statusBar->showMessage(str);
}
