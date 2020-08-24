#include "exportSpatialModes.H"
#include "exportField.H"

namespace Utopia
{

namespace Stream
{

template<class T>
void exportSpatialModes(const PtrList<T>& spatialModes, const word& folder)
{
  const label& nModes = spatialModes.size();
  const word& nameField = spatialModes[0].name();

  for ( label i = 0; i < nModes; i++ )
  {
    exportField( spatialModes[i], folder + "/" + name(i) + "/" + nameField);
  }
}

}

}
