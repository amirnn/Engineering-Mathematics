#include "sysfunc_exercise2_3.h"
#include <iostream>
#include "gnuplot-iostream.h"

typedef arma::mat::fixed<4, 4> SystemMatrix;
int main(int argc, char const *argv[])
{
    arma::cx_vec eigval;
    arma::cx_mat eigvec;
    SystemMatrix sysMatrix{
    {0,1,0,0},
    {0,0,1,0},
    {0,0,0,1},
    {0,0,0,0}
    };
    auto ebsVec = arma::linspace(0, .05, 100);
    for (const auto& ebs: ebsVec){
        sysMatrix(3,0) = -system_function::alpha_thetha_func(ebs);
        sysMatrix(3,2) = -system_function::alpha_thetha_dd_func(ebs);
        arma::eig_gen( eigval, eigvec, sysMatrix, "balance");
        std::cout << "Here are the eigvalues for the ebs: " << ebs << std::endl << eigval << std::endl;
        std::cout << "Here are the eigvectors: " << std::endl << eigvec << std::endl;
    }

    return 0;
}
