#ifndef HCA_MOVING_AVERAGE_FILTER_HPP_
#define HCA_MOVING_AVERAGE_FILTER_HPP_

#include <cstdint>
#include <valarray>
#include "filter_interface.hpp"

class MovingAverageFilter : FilterInterface{
private:
    uint16_t number;
    std::valarray<float> average_queue;
    float filtered_value;
public:
    MovingAverageFilter();
    void init(uint16_t number);
    void init(float work_frequency, float cut_off_frequency) override;
    void update(float value) override;
    float get() override;
    void reset();
};

#endif // HCA_MOVING_AVERAGE_FILTER_HPP_
