#ifndef UTIL_FUNCTION_MATH_SI_HPP_
#define UTIL_FUNCTION_MATH_SI_HPP_

namespace hca {

constexpr float deg2rad(float deg) {
    return deg * 2.0F * M_PI / 360.0F;
}

constexpr float rad2deg(float rad) {
    return rad / 2.0F / M_PI * 360.0F;
}

} // namespace hca

#endif /* UTIL_FUNCTION_MATH_SI_HPP_ */
