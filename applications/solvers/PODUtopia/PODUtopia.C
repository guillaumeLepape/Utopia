#include "fvCFD.H"
#include "POD.C"
// using namespace Utopia;

int main(int argc, char *argv[])
{
  #include "setRootCaseLists.H"
  #include "createTime.H"
  #include "createMesh.H"

  IOdictionary POD_U
  (
    IOobject
    (
      "POD_U",
      runTime.system(),
      mesh,
      IOobject::MUST_READ,
      IOobject::NO_WRITE
    )
  );

  Utopia::POD<volVectorField> pod(runTime, mesh, POD_U);


  return 0;
}
