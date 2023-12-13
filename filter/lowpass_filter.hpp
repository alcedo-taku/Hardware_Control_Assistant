#ifndef HCA_LOWPASS_FILTER_HPP
#define HCA_LOWPASS_FILTER_HPP

#include "filter_interface.hpp"

namespace hca {

class LowpassFilter : public FilterInterface{
private:
    float ratio;
public:
    LowpassFilter();
    void init(float ratio);
    void init(const float work_frequency, float cut_off_frequency) override;
    void update(const float value) override;
    void reset();
};

} // namespace hca

#endif // HCA_LOWPASS_FILTER_HPP
