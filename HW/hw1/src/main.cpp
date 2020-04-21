#include <iostream>
#include <eigen3/Eigen/Dense>
#include <vector>
#include <cmath>
#include <boost/numeric/odeint.hpp>
#include "gnuplot-iostream.h"
#include "system_function.h"
namespace odeint = boost::numeric::odeint;
int main()
{
	state_type x(2); // a vector with size 2.
	x[0] = 1.0;		 // start at x=1.0, p=0.0
	x[1] = 0.0;
	std::vector<state_type> x_vec;
	std::vector<double> times;

	size_t steps = odeint::integrate(harmonic_oscillator,
									 x, 0.0, 10.0, 0.1,
									 push_back_state_and_time(x_vec, times));

	std::vector<double> position;
	for (size_t i = 0; i <= steps; i++)
	{
		position.push_back(x_vec[i][0]);
	}
	/* output */
	Gnuplot gp;
	gp << "plot '-' using 1:2 with linespoint" << std::endl;
	gp.send1d(std::make_tuple(times, position));

	// for (size_t i = 0; i <= steps; i++)
	// {
	// 	std::cout << times[i] << '\t' << x_vec[i][0] << '\t' << x_vec[i][1] << '\n';
	// }

	return 0;
}
