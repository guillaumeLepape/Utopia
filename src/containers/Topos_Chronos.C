#include "Topos_Chronos.H"

namespace Utopia
{
  template<class T>
  Topos_Chronos<T>::Topos_Chronos()
  {

  }

  template<class T>
  Topos_Chronos<T>::Topos_Chronos(const PtrList<dimensionedVector>& topos,
    const PtrList<GeometricField<T, fvPatchField, volMesh>>& chronos) :
    topos_(topos), chronos_(chronos)
    {}

}
