#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vtkSmartPointer.h>
#include <vtkRenderWindow.h>
#include <vtkRenderer.h>

#include <vtkConeSource.h>
#include <vtkPolyDataMapper.h>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void newVtkPipe();             // inicjalizacja strumienia VTK
    
private:
    Ui::MainWindow *ui;

    // wskaźniki na obiekty VTK
    vtkConeSource* source;
    vtkPolyDataMapper* mapper;
    vtkActor* actor;
    vtkRenderWindow* renWin;

    // przykład bezpiecznego tworzenia wskaźnika do obiektu VTK
    vtkSmartPointer<vtkRenderer> renderer;

};

#endif // MAINWINDOW_H
