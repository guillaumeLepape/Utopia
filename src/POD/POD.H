#ifndef UTOPIA_POD_H
#define UTOPIA_POD_H

#include "fvCFD.H"

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
      const scalar startTime_;
      const scalar latestTime_;
      const label startTimeIndex_;
      const label latestTimeIndex_;
      const label nModes_;
      const word nameField_;
      const label nSnapshots_;
      const label nBlocks_;
      const word resultFolder_;
      instantList timeDirs_;

      Eigen::MatrixXd covMatrix_;
      T mean_;
      PtrList<T> topos_;
      List<dimensionedScalar> chronos_;

    public :
      POD(const Time& runTime, const fvMesh& mesh, const IOdictionary& UtopiaDict);

      void computeMean();
      void computeCovMatrix();
      void diagonalize();
      void computeTopos();
      void computeChronos();

      void compute();

      void write();

      inline const Eigen::MatrixXd& covMatrix() const { return covMatrix_; }
      inline const PtrList<T>& topos() const { return topos_; }
      inline const List<dimensionedScalar>& chronos() const { return chronos_; }
      inline const T& mean() const { return mean_; }
  };

}

#endif
