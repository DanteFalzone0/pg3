#ifndef TYPES_HPP
#define TYPES_HPP
#include "types.hpp"
#endif // TYPES_HPP

class AirCell {
private:
    CoordPair position;
    WindVector wind;
    float pressure;

public:
    float get_pressure() {
        float *ret = &pressure;
        return *ret; // using pointers like a ***R34L PR0GR4MM3R*** is supposed to
    }

    int set_pressure(float val) {
        pressure = val;
        return (pressure == val ? 0 : 1); // 0 on success, 1 on error
    }

    CoordPair get_position() {
        CoordPair ret = position;
        return ret;
    }

    int set_position(int _x, int _y) {
        position.x = _x;
        position.y = _y;
        int ret;
        if (position.x == _x && position.y == _y) {
            ret = 0;
        } else {
            ret = 1;
        }
        return ret;
    }

    WindVector get_wind() {
        WindVector ret = wind;
        return ret;
    }

    int set_wind(float _x, float _y) {
        wind.x_vel = _x;
        wind.y_vel = _y;
        int ret;
        if (wind.x_vel == _x && wind.y_vel == _y) {
            ret = 0;
        } else {
            ret = 1;
        }
        return ret;
    }

    // Method for determining if a particle is in an AirCell.
    // Each AirCell is 10 x 10 pixels in size.
    bool contains(CoordPair particle) {
        if (particle.x >= position.x
        &&  particle.y >= position.y
        &&  particle.x < (position.x + 10)
        &&  particle.y < (position.y + 10)) {
            return true;
        } else {
            return false;
        }
    }
};
