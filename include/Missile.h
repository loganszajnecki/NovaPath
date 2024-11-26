#ifndef MISSILE_H
#define MISSILE_H

#include <iostream>

const double grav = 9.81; // m/s^2

struct State {
    double x; // Position in x (m)
    double y; // Position in y (m)
    double z; // Position in z (m)
    double u; // Velocity in x (m/s)
    double v; // Velocity in y (m/s)
    double w; // Velocity in z (m/s)
};

// Missile class
class Missile {
    public:
        Missile(double mass);
        State computeAcceleration(const State& state);
        void update(double dt);
        void setState(const State& state);
        const State& getState() const;
        void setThrust(double thrust);
        void setDrag(double dragCoefficient);
    
    private:
        double mass_;                // Missile mass (kg)
        double thrust_ = 0;          // Thrust (N)
        double dragCoefficient_ = 0; // Drag coefficient
        State state_;                // Current missile state
};

#endif // MISSILE_H