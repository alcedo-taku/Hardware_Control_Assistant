#include <lowpass_filter.hpp>
#include <cmath>
LowpassFilter::LowpassFilter() {}

void LowpassFilter::init(float ratio) {
    if(ratio < 0){
        ratio = 0;
    }
    if(1 < ratio){
        ratio = 1;
    }

    this->ratio = ratio;
}
void LowpassFilter::init(float workFrequency, float cutOffFrequency) {
    if(workFrequency/2 < cutOffFrequency){
        cutOffFrequency = workFrequency/2;
    }
    float buf = 1 - std::cos(2*M_PI/workFrequency*cutOffFrequency);
    float ratio = (-2*buf + std::sqrt(4*std::pow(buf,2) + 8*buf))/2;
    init(ratio);
}

void LowpassFilter::update(float value) {
    filteredValue = value*ratio + (1 - ratio)*filteredValue;
}

float LowpassFilter::get() {
    return filteredValue;
}
void LowpassFilter::reset() {
    filteredValue = 0;
}
