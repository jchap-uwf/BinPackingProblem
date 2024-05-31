#ifndef OFFLINE_ALGORITHM_HPP
#define OFFLINE_ALGORITHM_HPP

#include "online_algorithm.hpp"

#include <iostream>
#include <vector>
#include <algorithm>

class OfflineAlgorithm
{
private:
    int numBinsUsed;
    std::vector<std::vector<double>> packedBins;
public:
    void OfflineFirstFit(std::vector<double>);
    void OfflineBestFit(std::vector<double>);
    void SetNumBinsUsed(int);
    int GetNumBinsUsed();
    void setPackedBins(std::vector<std::vector<double>>);
    std::vector<std::vector<double>> getPackedBins();
};


#endif