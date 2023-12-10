#include "lowpass_filter.hpp"
#include <cmath>

LowpassFilter::LowpassFilter() {}

void LowpassFilter::init(float ratio) {
    if(ratio < 0){
        ratio = 0;
    } else if(1 < ratio){
        ratio = 1;
    }
    this->ratio = ratio;
}
void LowpassFilter::init(const float work_frequency, float cut_off_frequency) {
    if(work_frequency/2 < cut_off_frequency){
        cut_off_frequency = work_frequency/2;
    }
    float buf = 1 - std::cos(2*M_PI/work_frequency*cut_off_frequency);
    float ratio = (-2*buf + std::sqrt(4*std::pow(buf,2) + 8*buf))/2;
    init(ratio);
}

void LowpassFilter::update(const float value) {
    filtered_value = value*ratio + (1 - ratio)*filtered_value;
}

float LowpassFilter::get() {
    return filtered_value;
}
void LowpassFilter::reset() {
    filtered_value = 0;
}
