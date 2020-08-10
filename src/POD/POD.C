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
    nameField_(UtopiaDict.lookupOrDefault<word>("nameField","")),
    nSnapshots_(latestTimeIndex_ - startTimeIndex_),
    nBlocks_(UtopiaDict.lookupOrDefault<label>("nModes",1)),
    resultFolder_(UtopiaDict.lookupOrDefault<word>("resultFolder","UtopiaDict")),
    covMatrix_(nSnapshots_,nSnapshots_),
    mean_(
      IOobject
      (
        "meanU",
        runTime_.timeName(),
        mesh_,
        IOobject::NO_READ,
        IOobject::AUTO_WRITE
      ),
      mesh_,
      dimensionSet(0,1,0,0,0)
    ),
    topos_(),
    chronos_(nModes_)
  {
    timeDirs_.resize(latestTimeIndex_ - startTimeIndex_ + 1);

    for (label i = 0; i < latestTimeIndex_ + 1 - startTimeIndex_; i++)
    {
      timeDirs_[i] = instant(runTime.times()[i + startTimeIndex_].value(), runTime.times()[i + startTime_].name());
    }

    for (label i = 0; i < nModes_; i++)
    {
      fileName name = (fileName) (resultFolder_ + "/" + name(i));

      topos_.append(volVectorField(
        IOobject
        (
          nameField_,
          name,
          mesh_,
          IOobject::NO_READ,
          IOobject::NO_WRITE
        ),
        mesh_,
        dimensionedVector(dimless, Zero)
      ));
    }

    compute();
  }




  template<class T>
  void POD<T>::computeMean()
  {
    dimensionedScalar one(dimensionSet(0,0,1,0,0),1);

    mean_ = 0*mean_;

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
          IOobject::NO_WRITE
        ),
        mesh_
      );

      mean_ += U*one;
    }

    mean_ = mean_/nSnapshots_;

    // mean_.write();

    fileName fieldname = resultFolder_ + "/mean/" + nameField_;
    OFstream os(fieldname);
    mean_.writeHeader(os);
    os << mean_ << endl;
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
