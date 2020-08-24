#ifndef UTOPIA_H1NORM_H
#define UTOPIA_H1NORM_H

#include "volFieldsFwd.H"
#include "fvCFD.H"

namespace Utopia
{

namespace functionNorm
{

  template <class T>
  dimensionedScalar H1Seminorm(const GeometricField<T, fvPatchField, volMesh>& field);

  template <class T>
  dimensionedScalar H1Seminorm(const tmp<GeometricField<T, fvPatchField, volMesh>>& field);

}


}

#endif
