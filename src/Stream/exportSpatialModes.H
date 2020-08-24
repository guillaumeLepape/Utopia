#ifndef EXPORT_SPATIAL_MODES
#define EXPORT_SPATIAL_MODES

#include "fvCFD.H"

namespace Utopia
{
    namespace Stream
    {
      template<class T>
      void exportSpatialModes(const PtrList<T>& spatialModes, const word& folder);

    }
}

#endif
