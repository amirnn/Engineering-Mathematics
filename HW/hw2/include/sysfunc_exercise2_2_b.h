#include <vector>
#include <armadillo>
namespace system_function
{
/* The type of container used to hold the state vector */
//typedef std::vector<double> state_type;
typedef arma::mat::fixed<4, 1> state_type;

/* The rhs of x' = f(x) */

auto harmonic_oscillator = [](const state_type &x, state_type &dxdt, const double /* t */) {
    dxdt[0] = x[1];
    dxdt[1] = x[2];
    dxdt[2] = x[3];
    dxdt[3] = 6 * x[0] + 5 * x[1] - 5 * x[2] - 5 * x[3];
};

// void harmonic_oscillator(const state_type &x, state_type &dxdt, const double /* t */)
// {
//     dxdt[0] = x[1];
//     dxdt[1] = x[2];
//     dxdt[2] = x[3];
//     dxdt[3] = 6 * x[0] + 5 * x[1] - 5 * x[2] -5 * x[3];
// }

std::vector<state_type> m_states;
std::vector<double> m_times;

auto push_back_state_and_time = [](const state_type &x, double t) {
    m_states.push_back(x);
    m_times.push_back(t);
};

// struct push_back_state_and_time
// {
//     std::vector<state_type> &m_states;
//     std::vector<double> &m_times;
//     push_back_state_and_time(std::vector<state_type> &states, std::vector<double> &times) : m_states(states), m_times(times) {}
//     void operator()(const state_type &x, double t)
//     {
//         m_states.push_back(x);
//         m_times.push_back(t);
//     }
// };

} // namespace system_function
