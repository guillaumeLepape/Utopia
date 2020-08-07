#include "fvCFD.H"
#include "Topos_Chronos.H"

namespace Utopia {

  template<class T>
  class POD
  {
    private :
      const Time& runTime_;
      const fvMesh& mesh_;
      const IOdictionary& UtopiaDict_;
      const label nModes_;

      List<T> topos_;
      List<dimensionedVector> chronos_;
    public :
      POD(const Time& runTime, const fvMesh& mesh, const IOdictionary& UtopiaDict);

      void compute();

      const List<T>& topos() const { return topos_;}
      const List<dimensionedVector>& chronos() const { return chronos_; }
  };

}
