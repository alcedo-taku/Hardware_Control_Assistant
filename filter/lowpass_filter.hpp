
#ifndef LOWPASS_FILTER_HPP
#define LOWPASS_FILTER_HPP
#include "filter_interface.hpp"

class LowpassFilter : FilterInterface{
private:
    float ratio;
    float filteredValue;
public:
    LowpassFilter();
    void init(float ratio);
    void init(float workFrequency, float cutOffFrequency) override;
    void update(float value)override;
    float get() override;
    void reset();
};
#endif //LOWPASS_FILTER_HPP
