#ifndef FINANCIAL_ASSETS_H
#define FINANCIAL_ASSETS_H

#include <string>
#include <unordered_map>
#include <utility>
#include <memory>
#include "../Instrument/instrument.h"

class FinancialAsset { 
private:
    std::string name_; 
    std::unordered_map<std::string, std::unique_ptr<Instrument>> instruments_;
    static std::unique_ptr<FinancialAsset> instance_;

    
    FinancialAsset(const std::string &name);

public:
   
    FinancialAsset(const FinancialAsset& other) = delete; 
    FinancialAsset& operator=(const FinancialAsset& other) = delete;

    static std::pair<bool, std::string> startInstrumentTrading(std::unique_ptr<Instrument>& instrument);
    static std::pair<bool, std::string> removeInstrumentTrading(const std::string& ticker);
    static void initialize(const std::string& name); 
    static FinancialAsset* getInstance(); 
    std::string getName() const;
};

#endif 