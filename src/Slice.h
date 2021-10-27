#include <Eigen/Dense>
#include <pcl/point_types.h>
#include <vtkActor.h>
#include <vtkCamera.h>
#include <vtkConeSource.h>
#include <vtkNamedColors.h>
#include <vtkNew.h>
#include <vtkPolyDataMapper.h>
#include <vtkProperty.h>
#include <vtkRenderWindow.h>
#include <vtkRenderer.h>
class Slice
{
	private:
		double minX, minY;
		double maxX, maxY;
		Eigen::Matrix2Xf A;
		Eigen::Vector2d X;
		Eigen::Vector2d Y;
		

	public:
		double Calculate_Area();

};

