#ifndef HCA_FILTER_INTERFACE_HPP_
#define HCA_FILTER_INTERFACE_HPP_

class FilterInterface {
	virtual void init(float workFrequency, float cutOffFrequency) = 0;
    virtual void update(float value) = 0;
    virtual float get() = 0;
};
#endif // HCA_FILTER_INTERFACE_HPP_
