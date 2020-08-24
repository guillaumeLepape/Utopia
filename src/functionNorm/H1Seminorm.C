#include "H1Seminorm.H"

// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

namespace Utopia
{

namespace functionNorm
{

template<>
dimensionedScalar H1Seminorm(const GeometricField<scalar, fvPatchField, volMesh>& field)
{
    return ( Foam::sqrt(fvc::domainIntegrate(fvc::grad(field) & fvc::grad(field)).value()) );
}

template<>
dimensionedScalar H1Seminorm(const GeometricField<vector, fvPatchField, volMesh>& field)
{
    return ( Foam::sqrt(fvc::domainIntegrate(fvc::grad(field) && fvc::grad(field)).value()) );
}

template<class T>
dimensionedScalar H1Seminorm(const tmp<GeometricField<T, fvPatchField, volMesh>>& field)
{
    dimensionedScalar norm(functionNorm::H1Seminorm<T>(field()));
    field.clear();
    return norm;
}


}

}
