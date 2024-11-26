#include "Simulation.h"
#include "FileOutput.h"

void runSimulation(double dt, double totalTime) {
    // Initialize the missile with mass and initial state
    Missile missile(50.0); // 50 kg missile
    State initalState{0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
    missile.setState(initalState);

    // Set missile parameters
    missile.setThrust(200.0); // 200N thrust
    missile.setDrag(0.1); // Drag coefficient

    // Output 
    FileOutput fileOutput("../offline", "simulation_results.csv");
    fileOutput.writeHeader();

    // Run the sim
    double time = 0.0;
    while (time <= totalTime) {
        missile.update(dt);

        State state = missile.getState();
        fileOutput.writeData(time, state);
        std::cout << "Time: " << time
                  << " | Position (x, y, z): (" << state.x << ", " << state.y << ", " << state.z << ")"
                  << " | Velocity (u, v, w): (" << state.u << ", " << state.v << ", " << state.w << ")\n";
        time += dt;
    }
}