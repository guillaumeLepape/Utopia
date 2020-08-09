#include "POD.H"

namespace Utopia {

  template<class T>
  POD<T>::POD(const Time& runTime, const fvMesh& mesh, const IOdictionary& UtopiaDict) :
    runTime_(runTime),
    mesh_(mesh),
    UtopiaDict_(UtopiaDict),
    startTime_(UtopiaDict.lookupOrDefault<label>("startTime",1)),
    latestTime_(UtopiaDict.lookupOrDefault<label>("endTime",1)),
    startTimeIndex_(Time::findClosestTimeIndex(runTime.times(),startTime_)),
    latestTimeIndex_(Time::findClosestTimeIndex(runTime.times(),latestTime_)),
    nModes_(UtopiaDict.lookupOrDefault<label>("nModes",1)),
    nSnapshots_(latestTimeIndex_ - startTimeIndex_),
    nBlocks_(UtopiaDict.lookupOrDefault<label>("nModes",1)),
    covMatrix_(nSnapshots_,nSnapshots_),
    mean_(
      IOobject
      (
        "meanU",
        "mean",
        mesh_,
        IOobject::NO_READ,
        IOobject::AUTO_WRITE
      ),
      mesh_
    ),
    topos_(nModes_),
    chronos_(nModes_)
  {
    for (label i = startTimeIndex_; i < latestTime_ + 1; i++)
    {
      timeDirs_.append( instant(runTime.times()[i].value(), runTime.times()[i].name()) );
    }

    compute();
  }

  template<class T>
  void POD<T>::computeMean()
  {
    forAll(timeDirs_,i)
    {
      volVectorField U
      (
        IOobject
        (
          "U",
          timeDirs_[i].name(),
          mesh_,
          IOobject::MUST_READ,
          IOobject::AUTO_WRITE
        ),
        mesh_
      );

      mean_ += U;
    }
  }

  template<class T>
  void POD<T>::computeCovMatrix()
  {

  }

  template<class T>
  void POD<T>::diagonalize()
  {

  }

  template<class T>
  void POD<T>::computeTopos()
  {

  }

  template<class T>
  void POD<T>::computeChronos()
  {

  }


  template<class T>
  void POD<T>::compute()
  {
    computeMean();
    computeCovMatrix();
    diagonalize();
    computeTopos();
    computeChronos();
  }


}
