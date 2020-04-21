#include <vector>
#include <eigen3/Eigen/Dense>

namespace system_function
{
/* The type of container used to hold the state vector */
typedef std::vector<double> state_type;
//typedef Eigen::Vector3d state_type;

/* The rhs of x' = f(x) */
void harmonic_oscillator(const state_type &x, state_type &dxdt, const double /* t */)
{
    dxdt[0] = x[1];
    dxdt[1] = x[2];
    dxdt[2] = 2 * x[0] + x[1] - 2 * x[2];
}

struct push_back_state_and_time
{
    std::vector<state_type> &m_states;
    std::vector<double> &m_times;
    push_back_state_and_time(std::vector<state_type> &states, std::vector<double> &times) : m_states(states), m_times(times) {}
    void operator()(const state_type &x, double t)
    {
        m_states.push_back(x);
        m_times.push_back(t);
    }
};

} // namespace system_function
