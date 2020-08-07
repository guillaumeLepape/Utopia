#include "POD.H"

namespace Utopia {

  template<class T>
  POD<T>::POD(const Time& runTime, const fvMesh& mesh, const IOdictionary& UtopiaDict) :
    runTime_(runTime),
    mesh_(mesh),
    UtopiaDict_(UtopiaDict),
    nModes_(UtopiaDict.lookupOrDefault<label>("nModes",1)),
    topos_(nModes_),
    chronos_(nModes_)
  {
    compute();
  }

  template<class T>
  void POD<T>::compute()
  {
    
  }

}
