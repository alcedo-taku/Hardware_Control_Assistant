#include "moving_average_filter.hpp"

namespace hca {

MovingAverageFilter::MovingAverageFilter() {}

void MovingAverageFilter::init(uint16_t number) {
    this->number = number;
    average_queue = std::valarray<float> (0.0, number);
}

void  MovingAverageFilter::init(float work_frequency, float cut_off_frequency) {
    init((uint16_t)(work_frequency/cut_off_frequency));
}

void MovingAverageFilter::update(const float value) {
    average_queue = average_queue.shift(-1); // データを右シフト
    average_queue[0] = value;
    filtered_value = average_queue.sum() / number;
}

void MovingAverageFilter::reset() {
    average_queue = std::valarray<float> (0.0, number);
}

} // namespace hca
