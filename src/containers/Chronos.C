#include "Chronos.H"

namespace Utopia {

template<class T>
Chronos<T>::Chronos()
{

}

template<class T>
Chronos<T>::Chronos(const PtrList<GeometricField<T,fvPatchField, volMesh>>& chronos)
{
  *this = chronos;
}

}
