#include "online_algorithm.hpp"

void OnlineAlgorithm::OnlineFirstFit(std::vector<double> theData)
{
    std::vector<std::vector<double>> bins(theData.size());

    double binSize{1};

    // i is the bin, j is the position within the bin

    for (int i{}; i < 4; i++)
    { // outer loop controls which bin we are on
        for (int j{}; j < theData.size(); j++)
        {

            bins.at(i).push_back(theData.at(j)); // place item into bin

            if (bins.at(i).size() == 1) // if bin has one item in it, move to the next number to place in it
            {
                continue;
            }
            else if (theData.size() == 1)
            {
                break;
            }
            else
            {
                double sum{};
                for (float k{}; k < bins.at(i).size(); k++) // add up each value in the bin
                {
                    sum += bins.at(i).at(k);
                }
                if (sum > binSize) // if sum greater or equal to 1, perform reomval functions, break and start the next bin
                {
                    bins.at(i).pop_back(); // remove recently placed item
                }
                else
                { // erase the values that were added to the bin from the original array
                    theData.erase(theData.begin() + j);
                    theData.erase(theData.begin());
                    continue;
                }
            }
        }
        setNumBinUsed(i + 1);
    }
    setPackedBins(bins);
}

void OnlineAlgorithm::OnlineNextFit(std::vector<double> theData)
{
    std::vector<std::vector<double>> bins(theData.size());

    double binSize{1};

    // i is the bin, j is the position within the bin

    for (int i{}; i < 5; i++)
    { // outer loop controls which bin we are on
        for (int j{}; j < theData.size(); j++)
        {

            bins.at(i).push_back(theData.at(j)); // place item into bin

            if (bins.at(i).size() == 1) // if bin has one item in it, move to the next number to place in it
            {
                continue;
            }
            else if (theData.size() == 1)
            {
                break;
            }
            else
            {
                double sum{};
                for (float k{}; k < bins.at(i).size(); k++) // add up each value in the bin
                {
                    sum += bins.at(i).at(k);
                }
                if (sum >= binSize) // if sum greater or equal to 1, perform reomval functions, break and start the next bin
                {
                    theData.erase(theData.begin(), theData.begin() + j); // remove the value(s) already added to the bin from the initial vector
                    bins.at(i).pop_back();                               // remove the value from the bin                    
                    break; // begin new bin
                }
                else // otherwise, continue to add to the bin
                {
                    continue;
                }
            }
        }
        setNumBinUsed(i + 1);
    }
    setPackedBins(bins);
}

void OnlineAlgorithm::OnlineBestFit(std::vector<double> theData)
{
    std::vector<std::vector<double>> bins(theData.size());

    double binSize{1};

    double result{};

    std::vector<double> binResults;

    int binCount{};

    for (int i{}; i < theData.size(); i++)
    {

        for (size_t v = 0; v < bins.size(); v++) // adds the value to each bin, where v is the bin
        {
            bins.at(v).push_back(theData.at(i)); // place the current value in each bin
        }

        for (size_t h = 0; h < bins.size(); h++) // creates the array of results to be compared, where h is the bin
        {
            double sum{};
            if (bins.at(h).size() == 1)
            {
                sum += bins.at(h).at(0);
            }
            else
            {
                for (size_t m = 0; m < bins.at(h).size(); m++)
                {
                    sum += bins.at(h).at(m); // add up the values within the current bin
                }
            }

            result = binSize - sum; // difference represents space left over in bin
            // std::cout << result << std::endl;
            if (result >= 0)
            {
                binResults.push_back(result);
            }
            else
            {
                result *= -10;
                // bins.at(h).erase(bins.at(h).begin() + bins.at(h).size() - 1);
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
                
                
                  binCount++;
                                        
                setNumBinUsed(binCount);
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
    }
    setPackedBins(bins);
}

void OnlineAlgorithm::setNumBinUsed(int n)
{
    numBinsUsed = n;
}

int OnlineAlgorithm::getNumBinsUsed()
{
    return numBinsUsed;
}

void OnlineAlgorithm::setPackedBins(std::vector<std::vector<double>> b){
    packedBins = b;
}

std::vector<std::vector<double>> OnlineAlgorithm::getPackedBins(){
    return packedBins;
}