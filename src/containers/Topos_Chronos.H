#include "Topos.H"
#include "Chronos.H"

namespace Utopia {

template<class T>
struct Topos_Chronos
{
  Topos_Chronos();
  Topos_Chronos(const PtrList<dimensionedVector>& topos,
    const PtrList<GeometricField<T, fvPatchField, volMesh>>& chronos);
  Topos topos_;
  Chronos<T> chronos_;
};

}
