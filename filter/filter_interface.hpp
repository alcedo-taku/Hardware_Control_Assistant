#ifndef HCA_FILTER_INTERFACE_HPP_
#define HCA_FILTER_INTERFACE_HPP_

namespace hca {

class FilterInterface {
protected:
    float filtered_value;
public:
	virtual void init(float work_frequency, float cut_off_frequency) = 0;
    virtual void update(float value) = 0;
    float get() { return filtered_value; }
};

} // namespace hca

#endif // HCA_FILTER_INTERFACE_HPP_
