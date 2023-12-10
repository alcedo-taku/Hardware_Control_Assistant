#ifndef HCA_LOWPASS_FILTER_HPP
#define HCA_LOWPASS_FILTER_HPP

#include "filter_interface.hpp"

namespace hca {

class LowpassFilter : FilterInterface{
private:
    float ratio;
    float filtered_value;
public:
    LowpassFilter();
    void init(float ratio);
    void init(const float work_frequency, float cut_off_frequency) override;
    void update(const float value) override;
    float get() override;
    void reset();
};

} // namespace hca

#endif // HCA_LOWPASS_FILTER_HPP
