#ifndef HCA_UTIL_FUNCTION_MAP_HPP_
#define HCA_UTIL_FUNCTION_MAP_HPP_

namespace hca {

template <typename T> T map(T x, T in_min, T in_max, T out_min, T out_max){
    return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

} // namespace hca

#endif /* HCA_UTIL_FUNCTION_MAP_HPP_ */
