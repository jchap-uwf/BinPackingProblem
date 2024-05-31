#ifndef ONLINE_ALGORITHM_HPP
#define ONLINE_ALGORITHM_HPP

#include <iostream>
#include <vector> 
#include <algorithm>

class OnlineAlgorithm
{
private:
    int numBinsUsed;
    std::vector<std::vector<double>> packedBins;
public:
    void OnlineFirstFit(std::vector<double>);
    void OnlineNextFit(std::vector<double>);
    void OnlineBestFit(std::vector<double>);

    void setNumBinUsed(int);
    int getNumBinsUsed();
    void setPackedBins(std::vector<std::vector<double>>);
    std::vector<std::vector<double>> getPackedBins();
};



#endif