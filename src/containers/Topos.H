#include "fvCFD.H"

namespace Utopia
{
  class Topos : public PtrList<dimensionedVector>
  {
    public :
      Topos();
      Topos(const PtrList<dimensionedVector>& topos);
  };


}
