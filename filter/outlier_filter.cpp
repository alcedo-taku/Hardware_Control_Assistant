#include <filter/outlier_filter.hpp>

namespace hca {

OutlierFilter::OutlierFilter() {}

void OutlierFilter::init(const float diff_of_outlier) {
    this->diff_of_outlier = diff_of_outlier;
    is_reseted = true;
}

void OutlierFilter::update(float value, float base_value) {
    if ( std::abs(value - base_value) < diff_of_outlier || is_reseted == true ) {
        filtered_value = value;
        if (std::abs(value) > std::numeric_limits<float>::epsilon()) {
            is_reseted = false;
        }
    } else {
        filtered_value = last_value;
    }
    last_value = filtered_value;
}

void OutlierFilter::update(float value) {
    update(value, last_value);
}

void OutlierFilter::reset() {
    is_reseted = true;
}

} /* namespace hca */
