#include "pcapviewer.h"
//#include <QApplication>
//#include <QMainWindow>
#include "MyIO.h"
#include  <iostream> 

int main(int argc, char *argv[])
{
/*
  QApplication a (argc, argv);
  pcapViewer w;
  w.show ();
  return a.exec ();
*/

	MyIO testPointCloud =MyIO();
	testPointCloud.readPLYFile("C:\\Users\\USER\\Desktop\\PCLtesting\\test\\sphere2x2.ply");

	return 0;
}
