#include "vtkSmartPointer.h"
#include <vtkBMPReader.h>
#include "vtkRenderWindow.h"
#include "vtkRenderer.h"
#include "vtkRenderWindowInteractor.h"
#include "vtkInteractorStyleTrackballCamera.h"
#include "vtkCylinderSource.h"
#include "vtkPolyDataMapper.h"
#include "vtkActor.h"

int main()
{
    vtkSmartPointer<vtkBMPReader>bmpReader = vtkSmartPointer<vtkBMPReader>::New();
    bmpReader->SetFileName("logo.bmp");

    vtkSmartPointer<vtkTexture>texture = vtkSmartPointer<vtkTexture>::New();
    texture->SetInputConnection(bmpReader->GetOutputPort());
    texture->InterpolateOn();

    vtkSmartPointer<vtkCylinderSource> cylinder =
            vtkSmartPointer<vtkCylinderSource>::New();
    cylinder->SetHeight( 3.0 );
    cylinder->SetRadius( 1.0 );
    cylinder->SetResolution( 10 );

    vtkSmartPointer<vtkPolyDataMapper> cylinderMapper =
            vtkSmartPointer<vtkPolyDataMapper>::New();
    cylinderMapper->SetInputConnection( cylinder->GetOutputPort() );

    vtkSmartPointer<vtkActor> cylinderActor =
            vtkSmartPointer<vtkActor>::New();
    cylinderActor->SetMapper( cylinderMapper );

    vtkSmartPointer<vtkRenderer> renderer =
            vtkSmartPointer<vtkRenderer>::New();
    renderer->AddActor( cylinderActor );
    renderer->SetBackground( 0.1, 0.2, 0.4 );

    vtkSmartPointer<vtkRenderWindow> renWin =
            vtkSmartPointer<vtkRenderWindow>::New();
    renWin->AddRenderer( renderer );
    renWin->SetSize( 300, 300 );

    vtkSmartPointer<vtkRenderWindowInteractor> iren =
            vtkSmartPointer<vtkRenderWindowInteractor>::New();
    iren->SetRenderWindow(renWin);

    vtkSmartPointer<vtkInteractorStyleTrackballCamera> style =
            vtkSmartPointer<vtkInteractorStyleTrackballCamera>::New();
    iren->SetInteractorStyle(style);

    iren->Initialize();

    cylinderActor->SetTexture(texture);
    iren->Start();

    return 0;
}