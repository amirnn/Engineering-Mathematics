#include <eigen3/Eigen/Dense>
#include <iostream>


int main(int argc, char const *argv[])
{    
    unsigned numberOfDays{20};
    Eigen::Matrix3f model;
    model << .5, .5, .25,
            .25, 0, .25,
            .25, .5, .5;
    std::cout << "The model matrix is:\n" << model << std::endl;

    Eigen::Vector3f today;
    Eigen::Vector3f tommorow;
    today << 1, 0 ,0;

    for (unsigned i=0; i<numberOfDays ;i++){
        std::cout << std::endl << "Day "<< i << std::endl << "Today's Weather: " << std::endl << today << std::endl;
                tommorow = model * today;
                today = tommorow;
    }

    return 0;
}
