#include "Missile.h"

Missile::Missile(double mass) : mass_(mass) {}

State Missile::computeAcceleration(const State& state) {
    State accel{0.0, 0.0, 0.0, 0.0, 0.0, 0.0};

    accel.u = thrust_ / mass_ - dragCoefficient_ * state.u / mass_;
    accel.v = -dragCoefficient_ * state.v / mass_;
    accel.w = -grav - dragCoefficient_ * state.w / mass_;

    return accel;
}

void Missile::update(double dt) {
    State accel = computeAcceleration(state_);

    // Update velocity
    state_.u += accel.u * dt;
    state_.v += accel.v * dt;
    state_.w += accel.w * dt;

    // Update position
    state_.x += state_.u * dt;
    state_.y += state_.v * dt;
    state_.z += state_.w * dt;
}

void Missile::setState(const State& state) {
    state_ = state;
}

const State& Missile::getState() const {
    return state_;
}

void Missile::setThrust(double thrust) {
    thrust_ = thrust;
}

void Missile::setDrag(double dragCoefficient) {
    dragCoefficient_ = dragCoefficient;
}