#include "Topos.H"

namespace Utopia {

Topos::Topos()
{

}

Topos::Topos(const PtrList<dimensionedVector>& topos)
{
  *this = topos;
}

}
