#ifndef HCA_LOWPASS_FILTER_HPP
#define HCA_LOWPASS_FILTER_HPP

#include "filter_interface.hpp"

class LowpassFilter : FilterInterface{
private:
    float ratio;
    float filtered_value;
public:
    LowpassFilter();
    void init(float ratio);
    void init(float work_frequency, float cut_off_frequency) override;
    void update(float value)override;
    float get() override;
    void reset();
};
#endif // HCA_LOWPASS_FILTER_HPP
