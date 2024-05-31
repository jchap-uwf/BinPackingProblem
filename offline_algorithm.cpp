#include "offline_algorithm.hpp"

void OfflineAlgorithm::OfflineFirstFit(std::vector<double> theData)
{
    std::sort(theData.begin(), theData.end());
    std::reverse(theData.begin(), theData.end());

    std::vector<std::vector<double>> bins(theData.size());

    double binSize{1};
    int binCount{};

    // i is the bin, j is the position within the bin

    for (int i{}; i < bins.size(); i++)    
    { // outer loop controls which bin we are on
        for (int j{}; j < theData.size(); j++)
        {

            double sum{0};

            bins.at(i).push_back(theData.at(j));
            for (int k{}; k < bins.at(i).size(); k++) // add up each value in the bin
            {
                sum += bins.at(i).at(k);
            }

            if (sum > binSize)
            {                                
                bins.at(i).pop_back();
                break;
            }
            else if (sum <= binSize)
            {
                theData.erase(theData.begin());
                j = 0;
                i = 0;
            }
        }
        SetNumBinsUsed(binCount);
    }
    setPackedBins(bins);
}

void OfflineAlgorithm::OfflineBestFit(std::vector<double> theData){

    std::sort(theData.begin(), theData.end());
    std::reverse(theData.begin(), theData.end());

    std::vector<std::vector<double>> bins(theData.size());

    double binSize{1};

    double result{};   

    std::vector<double> binResults;

     for (int i{}; i < theData.size(); i++) // i represents the data being read
    {
        for (size_t v = 0; v < bins.size(); v++) // adds the value to each bin, where v is the bin
        {
            bins.at(v).push_back(theData.at(i));
        }

        for (size_t h = 0; h < bins.size(); h++) // creates the array of results to be compared, where h is the bin
        {
            double sum{};
            for (size_t m = 0; m < bins.at(h).size(); m++)
            {
                sum += bins.at(h).at(m); // add up the values within the current bin
            }

            result = binSize - sum; // difference represents space left over in bin

             if (result >= 0)
            {
                binResults.push_back(result);
            }
            else
            {
                result *= -10;            
                binResults.push_back(result);
            }

        }

         auto min = min_element(binResults.begin(), binResults.end()); // find smallest result

         std::vector<double>::iterator it; // used for find()

          int index{}; // the bin to retain

           for (size_t n = 0; n < binResults.size(); n++) // determine the bin to retain
        {
            double resNum{binResults.at(n)};
            if (resNum == *min) // find the first occurence
            {
                index = n;
                break;
            }
        }

         for (size_t x = 0; x < bins.size(); x++) // delete item from every other bin besides the one it fits best in, where x is the bin
        {
            if (x == index)
            {
                continue;
            }
            else
            {
                if (bins.at(x).size() == 1)
                {
                    bins.at(x).pop_back();
                }
                else
                {
                    bins.at(x).erase(bins.at(x).begin() + bins.at(x).size() - 1);
                }
            }
        }
        binResults.clear();
        SetNumBinsUsed(i);
    }
    setPackedBins(bins);
}

void OfflineAlgorithm::SetNumBinsUsed(int n){
    numBinsUsed = n;
}

int OfflineAlgorithm::GetNumBinsUsed(){
    return numBinsUsed;
}

void OfflineAlgorithm::setPackedBins(std::vector<std::vector<double>> b){
    packedBins = b;
}

std::vector<std::vector<double>> OfflineAlgorithm::getPackedBins(){
    return packedBins;
}