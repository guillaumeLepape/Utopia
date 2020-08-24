Foam::Info<< "Create time for POD\n" << Foam::endl;

label startTimei = Time::findClosestTimeIndex(runTime.times(),startTime);
label latestTimei = Time::findClosestTimeIndex(runTime.times(),latestTime);

Foam::instantList timeDirs;

for (label i = startTimei; i < latestTimei + 1; i++)
{
  timeDirs.append( instant(runTime.times()[i].value(), runTime.times()[i].name()) );
}
