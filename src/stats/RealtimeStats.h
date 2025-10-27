#ifndef REALTIME_STATS_H
#define REALTIME_STATS_H

#include <iostream>
#include <cmath>

namespace statistics {

    template <typename T>
    class stats_computer1 {
    public:
        void new_val(T x) {
            if (n == 0)
                K = x;
            n++;
            T tmp = x - K;
            Ex += tmp;
            Ex2 += static_cast<double>(tmp) * tmp;
        }

        double mean() const {
            if (n == 0) return 0;
            return K + Ex / n;
        }

        double variance() const {
            if (n < 2) return 0;
            return (Ex2 - (Ex * Ex) / n) / (n - 1);
        }

        double std() const {
            return std::sqrt(this->variance());
        }

        friend std::istream &operator>>(std::istream &input, stats_computer1 &stat) {
            T val;
            input >> val;
            if (!input.fail()) {
                stat.new_val(val);
            }
            return input;
        }

    private:
        unsigned int n = 0;
        double Ex = 0, Ex2 = 0;
        T K{};
    };

    template <typename T>
    class stats_computer2 {
    public:
        void new_val(T x) {
            n++;
            double delta = x - mu;
            mu += delta / n;
            double delta2 = x - mu;
            M += delta * delta2;
        }

        double mean() const {
            return mu;
        }

        double variance() const {
            if (n == 0) return 0;
            return M / n;
        }

        double std() const {
            return std::sqrt(this->variance());
        }

        friend std::istream &operator>>(std::istream &input, stats_computer2 &stat) {
            T val;
            input >> val;
            if (!input.fail()) {
                stat.new_val(val);
            }
            return input;
        }

    private:
        unsigned int n = 0;
        double mu = 0, M = 0;
    };
} // namespace statistics

#endif // REALTIME_STATS_H
