#include "fvCFD.H"
// #include "Topos_Chronos.H"

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wold-style-cast"
#include <Eigen/Eigen>
#pragma GCC diagnostic pop

namespace Utopia {

  template<class T>
  class POD
  {
    private :
      const Time& runTime_;
      const fvMesh& mesh_;
      const IOdictionary& UtopiaDict_;
      const label nModes_;
      const label nSnapshots_;

      Eigen::MatrixXd covMatrix_;

      List<T> topos_;
      List<dimensionedVector> chronos_;
      T mean_;
    public :
      POD(const Time& runTime, const fvMesh& mesh, const IOdictionary& UtopiaDict);

      void computeMean();
      void computeCovMatrix();
      void diagonalize();
      void computeTopos();
      void computeChronos();

      void compute();

      const List<T>& topos() const { return topos_;}
      const List<dimensionedVector>& chronos() const { return chronos_; }
      const T& mean() const { return mean_; }
  };

}
