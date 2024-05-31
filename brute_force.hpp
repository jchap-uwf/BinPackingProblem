#ifndef BRUTE_FORCE_HPP
#define BRUTE_FORCE_HPP

#include "online_algorithm.hpp"
#include "offline_algorithm.hpp"

class BruteForce{
    private:
    std::vector<std::vector<double>> b;
    int o;
    public:
    void BF(std::vector<double>);
    void setBins(std::vector<std::vector<double>>);
    std::vector<std::vector<double>> getBins();
    void setOptimal(int);
    int getOptimal();
};

#endif