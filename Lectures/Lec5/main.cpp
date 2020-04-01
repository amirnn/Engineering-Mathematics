#include <iostream>
#include <Eigen/Dense>
#include "matplotlibcpp.h"
#include <boost/numeric/odeint.hpp>

using namespace boost::numeric::odeint;

// Define a abbreviation for state type
typedef std::vector< double > state_type;

namespace plt = matplotlibcpp;

const double sigma = 10.0;
const double R = 28.0;
const double b = 8.0 / 3.0;

// the system function can be a classical functions
void lorenz( state_type &x , state_type &dxdt , double t )
{                                                         
    dxdt[0] = sigma * ( x[1] - x[0] );
    dxdt[1] = R * x[0] - x[1] - x[0] * x[2];
    dxdt[2] = x[0]*x[1] - b * x[2];
}

int main(int argc, char const *argv[])
{
    state_type x( 3 );
    x[0] = x[1] = x[2] = 10.0;
    const double dt = 0.01;
    integrate_const( runge_kutta4< state_type >() , lorenz , x , 0.0 , 10.0 , dt );
    
    return 0;
}
