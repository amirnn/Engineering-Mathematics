#include <vector>
#include <armadillo>
#include <cmath>
namespace system_function
{
/* The type of container used to hold the state vector */
//typedef std::vector<double> state_type;
//typedef arma::mat::fixed<4, 1> state_type;

//double ebs = 0;
constexpr double omega_1 = 1;
constexpr double omega_2 = 2;

auto alpha_thetha_func = [](double ebs /*, double omega_1,double omega_2*/)-> double {
    return ((pow(omega_1,2) + pow(omega_2,2))) * ( 1 + (1 / ebs));
};

auto alpha_thetha_dd_func = [](double ebs/*, double omega_1,double omega_2*/)-> double {
    return ((pow(omega_1,2) + pow(omega_2,2)) / ebs) + 1 + ebs;
};

// double alpa_thetha = alpha_thetha_func();
// double alpa_thetha_dd = alpha_thetha_dd_func();

// /* The rhs of x' = f(x) */
// auto harmonic_oscillator = [](const state_type &x, state_type &dxdt, const double /* t */) {
//     dxdt[0] = x[1];
//     dxdt[1] = x[2];
//     dxdt[2] = x[3];
//     dxdt[3] = -alpa_thetha * x[0] - alpa_thetha_dd * x[2];
// };

// void harmonic_oscillator(const state_type &x, state_type &dxdt, const double /* t */)
// {
//     dxdt[0] = x[1];
//     dxdt[1] = x[2];
//     dxdt[2] = x[3];
//     dxdt[3] = 6 * x[0] + 5 * x[1] - 5 * x[2] -5 * x[3];
// }

// std::vector<state_type> m_states;
// std::vector<double> m_times;

// auto push_back_state_and_time = [](const state_type &x, double t) {
//     m_states.push_back(x);
//     m_times.push_back(t);
// };

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
