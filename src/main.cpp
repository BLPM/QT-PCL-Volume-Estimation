#include "pcapviewer.h"
#include <QApplication>
#include <QMainWindow>

int main(int argc, char *argv[])
{
  QApplication a (argc, argv);
  pcapViewer w;
  w.show ();
  return a.exec ();
}
