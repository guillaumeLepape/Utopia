#ifndef UTOPIA_EXPORT_FIELD
#define UTOPIA_EXPORT_FIELD

#include "fvCFD.H"

namespace Utopia
{
  namespace Stream
  {
    template<class T>
    void exportField(const T& field, const fileName& nameFile)
    {
      OFstream os(nameFile);
      field.writeHeader(os);
      os << field << endl;
    }

    template<class T>
    void exportField(const tmp<T>& field, const fileName& nameFile)
    {
      exportField<T>(field(), nameFile);
      field.clear();
    }
  }
}

#endif
