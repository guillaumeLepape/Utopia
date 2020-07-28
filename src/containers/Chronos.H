#include "fvCFD.H"


namespace Utopia
{

template<class T>
class Chronos : public PtrList<GeometricField<T, fvPatchField, volMesh>>
{
  private :

  public :
    Chronos();
    Chronos(const PtrList<GeometricField<T,fvPatchField, volMesh>>& chronos);
};

}
