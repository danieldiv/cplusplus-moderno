#ifndef WEIGHT_H__
#define WEIGHT_H__

class Weight {
public:
    Weight(double g): grams_(g) { }
    double get() const { return grams_; }
private:
    double grams_;
};
Weight operator"" _g(long double value) {
    return Weight(value);
}
Weight operator"" _Kg(long double value) {
    return Weight(1000.0 * value);
}
#endif