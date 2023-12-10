#include "moving_average_filter.hpp"

MovingAverageFilter::MovingAverageFilter() {}

void MovingAverageFilter::init(uint16_t number) {
    this->number = number;
}

void  MovingAverageFilter::init(float work_frequency, float cut_off_frequency) {
    init((uint16_t)(work_frequency/cut_off_frequency));
}

void MovingAverageFilter::update(float value) {
    if(number < averageQueue.size()){
        averageQueue.pop();
    }
    averageQueue.push(value);

    filteredValue = averageQueue.getAverage();
}

float MovingAverageFilter::get() {
    return  filteredValue;
}

void MovingAverageFilter::reset() {
    averageQueue.reset();
}