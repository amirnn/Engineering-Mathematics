#include <iostream>
#include <Eigen/Dense>
#include "gnuplot-iostream.h"

using Eigen::Matrix3d;
using Eigen::Matrix3cd;
int main(int argc, char const *argv[])
{
    Matrix3d A;
    A <<    0,1,0,
            0,0,1,
            2,1,-2;
    std::cout << "Here is the matrix A:\n" << A << std::endl;

    Eigen::EigenSolver<Matrix3d> eigenSolver(A);
    if(eigenSolver.info() != Eigen::Success) abort();
    std::cout << "The eigenvalues of A are:\n" << eigenSolver.eigenvalues() << std::endl;
    std::cout << "Here's a matrix whose columns are eigenvectors of A \n"
        << "corresponding to these eigenvalues:\n"
        << eigenSolver.eigenvectors() << std::endl;

    Matrix3cd T = eigenSolver.eigenvectors();
    Matrix3cd T_inverse = T.inverse();
    Matrix3cd D = T_inverse * A * T;

    std::cout << "The diagonlized Matrix D is:\n" << D << std::endl;


    return 0;
}
