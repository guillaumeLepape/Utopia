#include "fvCFD.H"
#include "POD.C"
// using namespace Utopia;

int main(int argc, char *argv[])
{
  // #include "PODdict.H"
  #include "setRootCaseLists.H"

  // scalar startTime = 1.5;
  // scalar latestTime = 3.5;

  #include "createTime.H"
  // #include "createTimePOD.H"
  #include "createMesh.H"


  // Info << timeDirs << endl;


  // instant startTimei = runTime.findClosestTime(startTime);
  // instant latestTimei = runTime.findClosestTime(latestTime);



// Info << startTimei.value() << endl;
// Info << latestTimei.value() << endl;

  // const instantList& timeDirs = runTime.times();

  // forAll(timeDirs,timei)
  // {
  //   Info << timeDirs[timei] << endl;
  //   // runTime++;
  // }


  // for (label timei = startTimei; timei < latestTimei + 1; timei++)
  // {
  //   runTime.setTime(timeDirs[timei], timei);
  //
  //   Info << runTime.timeName() << endl;

  IOdictionary POD_U
    (
        IOobject
        (
            "POD_U",
            runTime.system(),
            mesh,
            IOobject::MUST_READ,
            IOobject::NO_WRITE
        )
    );

  Utopia::POD<volVectorField> pod(runTime, mesh, POD_U);

  // forAll(timeDirs, timei)
  // {
  //     Info << timeDirs[timei].value() << " " << timeDirs[timei].name() << endl;

      // runTime.setTime(timeDirs[timei], timei);

      // Info << runTime.timeName() << endl;
  // }


  // while (runTime.run())
  // {
  //   Info << runTime.timeName() << endl;
  //   // Info << runTime
  //   runTime++;
  // }

  // Foam::instantList timeDirs = Foam::timeSelector::select0(runTime, args);

  // Foam::instantList timeDirs = runTime.times();

  // timeDirs.subList();

  // forAll(timeDirs, timei)
  // {
    // runTime.setTime(timeDirs[timei], timei);


  // }


  return 0;
}
