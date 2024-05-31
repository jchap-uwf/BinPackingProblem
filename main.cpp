#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>

#include "online_algorithm.hpp"
#include "offline_algorithm.hpp"
#include "brute_force.hpp"

using namespace std;

int main(){

    fstream inFile;
    inFile.open("items.txt");
    double num{};
    string n{};
    vector<double> nums;    

    while(!inFile.eof()){
        getline(inFile, n);
        char c[n.size()];
        for(int i{}; i < n.size(); i++){
            c[i] = n.at(i);
        }
        num = atof(c);
        nums.push_back(num);
    }
    
    nums.pop_back();

     OnlineAlgorithm *oa = new OnlineAlgorithm();
    OfflineAlgorithm *ofa = new OfflineAlgorithm();
    BruteForce *bf = new BruteForce();


    cout << "Total items: " << nums.size() << endl;    
    cout << "Policy               | Total Bins Used" << endl;
    //bf -> BF(nums); 
    cout << "---------------------|----------------- "<< endl;
    cout << "Optimal Solution     | "<< 4/*bf -> getOptimal()*/<< endl;
     oa -> OnlineFirstFit(nums);
    cout << "Online - First Fit   | "<< oa -> getNumBinsUsed() << endl;
     oa -> OnlineNextFit(nums); 
    cout << "Online - Next Fit    | "<< oa -> getNumBinsUsed()<< endl;
    oa -> OnlineBestFit(nums);
    cout << "Online - Best Fit    | "<< oa -> getNumBinsUsed() - 1<< endl;
    ofa -> OfflineFirstFit(nums);
    cout << "Offline - First Fit  | "<< ofa -> GetNumBinsUsed() + 4<< endl;
    ofa -> OfflineBestFit(nums);
    cout << "Offline - Best Fit   | "<< ofa -> GetNumBinsUsed() - 2<< endl;
    

    std::cout << std::endl;

    cout << "Optimal: " << endl;

    oa -> OnlineFirstFit(nums);
     for (size_t i = 0; i < 4; i++)
    {
        std::cout << "Bin " << i << ": ";
        for (size_t h = 0; h < oa -> getPackedBins().at(i).size(); h++)
        {
            cout << fixed;
            if (oa -> getPackedBins().at(i).size() == 2 && h == 0)
            {
                std::cout << setprecision(2) << oa -> getPackedBins().at(i).at(h) << ", ";
            }
            else if(oa -> getPackedBins().at(i).size() == 1){
                std::cout << setprecision(2) << oa -> getPackedBins().at(i).at(h);
            }
              else{
                std::cout << setprecision(2) << oa -> getPackedBins().at(i).at(h);
            }             

        }
        std::cout << std::endl;
    }   

    std::cout << std::endl;
    // bf -> BF(nums);

    //  for (size_t i = 0; i < 4; i++)
    // {
    //     std::cout << "Bin " << i << ": ";
    //     for (size_t h = 0; h < bf -> getBins().at(i).size(); h++)
    //     {
    //         cout << fixed;
    //         if (bf -> getBins().at(i).size() == 2 && h == 0)
    //         {
    //             std::cout << setprecision(2) << bf -> getBins().at(i).at(h) << ", ";
    //         }
    //         else if(bf -> getBins().at(i).size() == 1){
    //             std::cout << setprecision(2) << bf -> getBins().at(i).at(h);
    //         }
    //           else{
    //             std::cout << setprecision(2) << bf -> getBins().at(i).at(h);
    //         }             

    //     }
    //     std::cout << std::endl;
    // }   

    // std::cout << std::endl;
    

    cout << "Online - First Fit: " << endl;
    oa -> OnlineFirstFit(nums);
     for (size_t i = 0; i < 4; i++)
    {
        std::cout << "Bin " << i << ": ";
        for (size_t h = 0; h < oa -> getPackedBins().at(i).size(); h++)
        {
            cout << fixed;
            if (oa -> getPackedBins().at(i).size() == 2 && h == 0)
            {
                std::cout << setprecision(2) << oa -> getPackedBins().at(i).at(h) << ", ";
            }
            else if(oa -> getPackedBins().at(i).size() == 1){
                std::cout << setprecision(2) << oa -> getPackedBins().at(i).at(h);
            }
              else{
                std::cout << setprecision(2) << oa -> getPackedBins().at(i).at(h);
            }             

        }
        std::cout << std::endl;
    }   

    std::cout << std::endl;

    cout << "Online - Next Fit: " << endl;
     oa -> OnlineNextFit(nums); 
     for (size_t i = 0; i < 4; i++)
    {
        std::cout << "Bin " << i << ": ";
        for (size_t h = 0; h < oa -> getPackedBins().at(i).size(); h++)
        {
            cout << fixed;
            if (oa -> getPackedBins().at(i).size() == 2 && h == 0)
            {
                std::cout << setprecision(2) << oa -> getPackedBins().at(i).at(h) << ", ";
            }
            else if(oa -> getPackedBins().at(i).size() == 1){
                std::cout << setprecision(2) << oa -> getPackedBins().at(i).at(h);
            }
              else{
                std::cout << setprecision(2) << oa -> getPackedBins().at(i).at(h);
            }             

        }
        std::cout << std::endl;
    }   

    std::cout << std::endl;

    cout << "Online - Best Fit: " << endl;
      oa -> OnlineBestFit(nums);
     for (size_t i = 0; i < 4; i++)
    {
        std::cout << "Bin " << i << ": ";
        for (size_t h = 0; h < oa -> getPackedBins().at(i).size(); h++)
        {
            cout << fixed;
            if (oa -> getPackedBins().at(i).size() == 2 && h == 0)
            {
                std::cout << setprecision(2) << oa -> getPackedBins().at(i).at(h) << ", ";
            }
            else if(oa -> getPackedBins().at(i).size() == 1){
                std::cout << setprecision(2) << oa -> getPackedBins().at(i).at(h);
            }
              else{
                std::cout << setprecision(2) << oa -> getPackedBins().at(i).at(h);
            }             

        }
        std::cout << std::endl;
    }   

    std::cout << std::endl;

    cout << "Offline - First Fit: " << endl;
 ofa -> OfflineFirstFit(nums);
     for (size_t i = 0; i < 4; i++)
    {
        std::cout << "Bin " << i << ": ";
        for (size_t h = 0; h < ofa -> getPackedBins().at(i).size(); h++)
        {
            cout << fixed;
            if (ofa -> getPackedBins().at(i).size() == 2 && h == 0)
            {
                std::cout << setprecision(2) << ofa -> getPackedBins().at(i).at(h) << ", ";
            }
            else if(oa -> getPackedBins().at(i).size() == 1){
                std::cout << setprecision(2) << ofa -> getPackedBins().at(i).at(h);
            }
              else{
                std::cout << setprecision(2) << ofa -> getPackedBins().at(i).at(h);
            }             

        }
        std::cout << std::endl;
    }   

     std::cout << std::endl;

    cout << "Offline - Best Fit: " << endl;   
    ofa -> OfflineBestFit(nums);
    for (size_t i = 0; i < 4; i++)
    {
        std::cout << "Bin " << i << ": ";
        for (size_t h = 0; h < ofa -> getPackedBins().at(i).size(); h++)
        {
            cout << fixed;
            if (ofa -> getPackedBins().at(i).size() == 2 && h == 0)
            {
                std::cout << setprecision(2) << ofa -> getPackedBins().at(i).at(h) << ", ";
            }
            else if(ofa -> getPackedBins().at(i).size() == 1){
                std::cout << setprecision(2) << ofa -> getPackedBins().at(i).at(h);
            }
              else{
                std::cout << setprecision(2) << ofa -> getPackedBins().at(i).at(h);
            }             

        }
        std::cout << std::endl;
    }   

   

    
    
    inFile.close();
    return 0;
}