#include <iostream>
#include <boost/numeric/odeint.hpp>
#include "gnuplot-iostream.h"
#include "sysfunc_exercise2_2_b.h"


namespace odeint = boost::numeric::odeint;

int main(int argc, char const *argv[])
{
    // Odeint
    std::vector<double> position;
    {
        system_function::state_type x; // a vector with size 3. [x; x_dot; x_dot_dot]
        //x = {1,1,1, 1};                    // start at x=1, 1, 1, 1;
        x = {1, -1, 1, -1};
        size_t steps = odeint::integrate(system_function::harmonic_oscillator,
                                         x, 0.0, 10.0, 0.1,
                                         system_function::push_back_state_and_time);

        for (size_t i = 0; i <= steps; i++)
        {
            position.push_back(system_function::m_states[i][0]);
        }
    }

    // GNU Plot
    {
        /* output */
        Gnuplot gp;
        gp << "plot '-' using 1:2 with linespoint" << std::endl;
        gp.send1d(std::make_tuple(system_function::m_times, position));
    }
    return 0;
}
