#include "moving_average_filter.hpp"

MovingAverageFilter::MovingAverageFilter() {}

void MovingAverageFilter::init(uint16_t number) {
    this->number = number;
}

void  MovingAverageFilter::init(float workFrequency, float cutOffFrequency) {
    init((uint16_t)(workFrequency/cutOffFrequency));
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