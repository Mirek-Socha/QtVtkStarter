QtVtkStarter
============

=== QtVtkStarter - Szkielet programu łączącego Qt i VTK w jedną aplikację okienkową (Mirosław Socha, 2014)


Projekt powstał na potrzeby prowadzonych zajęć dla studentów 4 roku kierunku Inżynieria Biomedyczna AGH.

--- Środowisko pracy -------------------

Na komputerach w laboratorium zainstalowany jest system Ubuntu w wersji 10.4 LTS a nie najnowsza wersja.
Wersje LTS (long-term support) mają wieloletnie wsparcie, nie ma w nich najmodniejszych i najnowszych rozwiązać. 
W zamian oferują stabilną, sprawdzoną bazę oprogramowania. 
W naszym przypadku, wersja LTS zapewnia dostęp do stabilnych (niekoniecznie najnowszych), 
dobrze przetestowanych i opisanych wersji bibliotek Qt, VTK i ITK.

System Ubuntu można zainstalować używając programu do wirtualizacji (VirtualBox, VMWare Workstation czy VirtualPC) lub instalując na dysku, obok Windowsów. Po uruchomieniu systemu z płytki, instalacja zazwyczaj przebiega płynnie, instalator podpowiada jak "przesunąć" Windowsy, instaluje program grub umożliwiający wybranie systemu operacyjnego przy starcie... itp.
Po 15-20 minutach system jest gotowy do pracy :)

Projekt powstał w Qt Creator 2.4.1., Qt 4.8.0 i zakłada użycie biblioteki VTK w wersji 5.8, dostępnej w repozytoriach.
Instalacja Qt SDK: sudo apt-get install qt-sdk


--- Niezbędne pakiety ------------------

Do wybrania w Menadżer pakietów Synaptic:
* główne pakiety vtk5: libvtk5.8, libvtk5-dev
* rozszerzenie do Qt vtk5-qt4: libvtk5-qt4, libvtk5-qt4-dev
* wrapery: python-vtk, python-vtkgdcm, vtk-tcl
* dodatki: vtk-doc, vtk-example, vtkdata, libvtkgdcm-tools

Instalacja VTK: sudo apt-get install libvtk5-dev libvtk5.8 libvtk5.8-qt4 libvtk5-qt4-dev vtkdata vtk-examples


--- Tworzenie projektu w Qt Creator ----

Aplikacja stworzona jest w środowisku Qt Creator
Kolejne kroki tworzenia czystej plikacji
* tworzymy projekt „Aplikacja GUI Qt”
* do pliku projektu (*.pro) dodajemy biblioteki:

        LIBS += ­L/usr/lib ­lvtkCommon lvtksys ­lQVTK ­lvtkViews ­lvtkWidgets ­lvtkInfovis ­lvtkRendering ­lvtkGraphics ­lvtkImaging ­lvtkIO ­lvtkFiltering ­lvtkDICOMParser ­lvtkHybrid
  
oraz ścieżkę dostępu:

        INCLUDEPATH += /usr/include/vtk­582

--- Dodatkowe informacje ---------------

W repozytorium znajdują się wszystkie istotne kroki powstawania aplikacji.

