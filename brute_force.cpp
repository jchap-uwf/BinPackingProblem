#include "brute_force.hpp"


void BruteForce::BF(std::vector<double> theData){

    OnlineAlgorithm *oa;= new OnlineAlgorithm();
    OfflineAlgorithm *ofa = new OfflineAlgorithm();

    std::vector<vector<double>> bins;
    std::vector<int> binsUsed;

    oa -> OnlineFirstFit(theData);
    binsUsed.push_back(getNumBinsUsed());
    bins.push_back(oa -> getPackedBins());

    oa -> OnlineNextFit(theData);
    binsUsed.push_back(getNumBinsUsed());
    bins.push_back(oa -> getPackedBins());

    oa -> OnlineBestFit(theData);
    binsUsed.push_back(getNumBinsUsed() - 1);
    bins.push_back(ofa -> getPackedBins());

    ofa -> OfflineFirstFit(theData);
    binsUsed.push_back(GetNumBinsUsed() + 4);
    bins.push_back(ofa -> getPackedBins());

    ofa -> OfflineBestFit(theData);
    binsUsed.push_back(GetNumBinsUsed() - 2);
    bins.push_back(ofa -> getPackedBins());

    setBins(bins);

    auto min = min_element(binsUsed.begin(), binsUsed.end());

    return *min;
}

void BruteForce::setBins(std::vector<std::vector<double>> v){
    b = v;
}

std::vector<std::vector<double>> BruteForce::getBins(){
    return b;
}

void BruteForce::setOptimal(int i){
    o = i;
}

int BruteForce::getOptimal(){
    return o;
}