#include <iostream>
#include <Eigen/Dense>
#include "gnuplot-iostream.h"
#include <boost/numeric/odeint.hpp>
#include "system_function.h"

using Eigen::Matrix3cd;
using Eigen::Matrix3d;
namespace odeint = boost::numeric::odeint;

int main(int argc, char const *argv[])
{
    Matrix3d A;
    A << 0, 1, 0,
        0, 0, 1,
        2, 1, -2;
    std::cout << "Here is the matrix A:\n"
              << A << std::endl;

    Eigen::EigenSolver<Matrix3d> eigenSolver(A);
    if (eigenSolver.info() != Eigen::Success)
        abort();
    std::cout << "The eigenvalues of A are:\n"
              << eigenSolver.eigenvalues() << std::endl;
    std::cout << "Here's a matrix whose columns are eigenvectors of A \n"
              << "corresponding to these eigenvalues:\n"
              << eigenSolver.eigenvectors() << std::endl;

    Matrix3cd T = eigenSolver.eigenvectors();
    Matrix3cd T_inverse = T.inverse();
    Matrix3cd D = T_inverse * A * T;

    std::cout << "The diagonlized Matrix D is:\n"
              << D << std::endl;

    // Odient Code ...
    std::vector<system_function::state_type> x_vec;
    std::vector<double> times;
    std::vector<double> position;
    {
        system_function::state_type x(3); // a vector with size 3. [x; x_dot; x_dot_dot]
        x = {1, 1, 1};                    // start at x=1, 1, 1;

        size_t steps = odeint::integrate(system_function::harmonic_oscillator,
                                         x, 0.0, 10.0, 0.1,
                                         system_function::push_back_state_and_time(x_vec, times));

        for (size_t i = 0; i < steps; i++)
        {
            position.push_back(x_vec[i][0]);
        }
    }

    // GNU Plot
    {
        /* output */
        Gnuplot gp;
        gp << "plot '-' using 1:2 with linespoint" << std::endl;
        gp.send1d(std::make_tuple(times, position));
    }

    return 0;
}
