#include "sysfunc_exercise2_3.h"
#include <iostream>
#include "gnuplot-iostream.h"

typedef arma::mat::fixed<4, 4> SystemMatrix;
int main(int argc, char const *argv[])
{
    try
    {
        arma::cx_vec eigval;
        arma::cx_mat eigvec;
        SystemMatrix sysMatrix{
            {0, 1, 0, 0},
            {0, 0, 1, 0},
            {0, 0, 0, 1},
            {0, 0, 0, 0}};
        auto ebsVec = arma::linspace(0, .05, 100);
        std::cout.precision(5);
        std::cout << std::fixed;
        for (const auto &ebs : ebsVec)
        {
            sysMatrix(3, 0) = -system_function::alpha_thetha_func(ebs);
            sysMatrix(3, 2) = -system_function::alpha_thetha_dd_func(ebs);
            arma::eig_gen(eigval, eigvec, sysMatrix, "balance");
            std::cout << "Here are the eigvalues for the ebs: " << ebs << std::endl
                      << eigval << std::endl;
            std::cout << "Here are the eigvectors: " << std::endl
                      << eigvec << std::endl;
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
