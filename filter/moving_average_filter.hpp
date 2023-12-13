#ifndef HCA_MOVING_AVERAGE_FILTER_HPP_
#define HCA_MOVING_AVERAGE_FILTER_HPP_

#include <cstdint>
#include <valarray>
#include "filter_interface.hpp"

namespace hca {

class MovingAverageFilter : public FilterInterface{
private:
    uint16_t number;
    std::valarray<float> average_queue;
public:
    MovingAverageFilter();
    void init(uint16_t number);
    void init(float work_frequency, float cut_off_frequency) override;
    void update(float value) override;
    void reset();
};

} // namespace hca

#endif // HCA_MOVING_AVERAGE_FILTER_HPP_
