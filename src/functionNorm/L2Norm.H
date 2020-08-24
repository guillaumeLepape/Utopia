#ifndef UTOPIA_L2NORM_H
#define UTOPIA_L2NORM_H

#include "volFieldsFwd.H"
#include "fvCFD.H"

namespace Utopia
{

namespace functionNorm
{

  template<class T>
  dimensionedScalar L2Norm(const T& field);

  template<class T>
  dimensionedScalar L2Norm(const tmp<T>& field);


}


}

#endif
