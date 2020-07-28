/*---------------------------------------------------------------------------*\
     ██╗████████╗██╗  ██╗ █████╗  ██████╗ █████╗       ███████╗██╗   ██╗
     ██║╚══██╔══╝██║  ██║██╔══██╗██╔════╝██╔══██╗      ██╔════╝██║   ██║
     ██║   ██║   ███████║███████║██║     ███████║█████╗█████╗  ██║   ██║
     ██║   ██║   ██╔══██║██╔══██║██║     ██╔══██║╚════╝██╔══╝  ╚██╗ ██╔╝
     ██║   ██║   ██║  ██║██║  ██║╚██████╗██║  ██║      ██║      ╚████╔╝
     ╚═╝   ╚═╝   ╚═╝  ╚═╝╚═╝  ╚═╝ ╚═════╝╚═╝  ╚═╝      ╚═╝       ╚═══╝

 * In real Time Highly Advanced Computational Applications for Finite Volumes
 * Copyright (C) 2017 by the ITHACA-FV authors
-------------------------------------------------------------------------------

License
    This file is part of ITHACA-FV

    ITHACA-FV is free software: you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    ITHACA-FV is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
    GNU Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public License
    along with ITHACA-FV. If not, see <http://www.gnu.org/licenses/>.
\*---------------------------------------------------------------------------*/

#include "L2Norm.H"

// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

namespace Utopia
{

namespace functionNorm
{

template<>
dimensionedScalar L2Norm(const GeometricField<scalar,fvPatchField, volMesh>& field)
{
    return ( Foam::sqrt(fvc::domainIntegrate(field * field).value()) );
}

template<>
dimensionedScalar L2Norm(const GeometricField<vector, fvPatchField, volMesh>& field)
{
    return ( Foam::sqrt(fvc::domainIntegrate(field & field).value()) );
}

template<class T>
dimensionedScalar L2Norm(const tmp<GeometricField<T, fvPatchField, volMesh>>& field)
{
  dimensionedScalar norm(functionNorm::L2Norm<T>(field));
  field.clear();
  return norm;
}


// template<class T>
// double frobNorm(const GeometricField<T, fvPatchField, volMesh>& field)
// {
//     double norm(0);
//     Eigen::VectorXd vF = Foam2Eigen::field2Eigen(field);
//     norm = vF.norm();
//     return norm;
// }
//
// // template<class T>
// // double frobNorm(const tmp<GeometricField<T, fvPatchField, volMesh>>& field)
// // {
// //     double norm(0);
// //     Eigen::VectorXd vF = Foam2Eigen::field2Eigen(field);
// //     norm = vF.norm();
// //     return norm;
// // }
//
//
// template double frobNorm(GeometricField<scalar, fvPatchField, volMesh>& field);
// template double frobNorm(GeometricField<vector, fvPatchField, volMesh>& field);

// template<Field_type>
// void corMatrix(PtrList<Field_type>& snapshots)
// {
//
// }


}

}
