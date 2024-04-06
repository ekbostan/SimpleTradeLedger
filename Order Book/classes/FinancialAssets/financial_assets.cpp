#include "../../Include/FinancialAssets/financial_assets.h"

std::unique_ptr<FinancialAsset> FinancialAsset::instance_ = nullptr;

FinancialAsset::FinancialAsset(const std::string &name) : name_(name) {}

std::pair<bool, std::string> FinancialAsset::startInstrumentTrading(std::unique_ptr<Instrument>& instrument) {
    if (!instrument) {
        return {false, "Null instrument"};
    }
    FinancialAsset* financial_asset = FinancialAsset::getInstance();
    const std::string& ticker = instrument->getTicker();
    if (financial_asset->instruments_.find(ticker) != financial_asset->instruments_.end()) {
        return {false, "Instrument with the same ticker already exists"};
    }
    financial_asset->instruments_[ticker] = std::move(instrument);
    return {true, ticker};
}

std::pair<bool, std::string> FinancialAsset::removeInstrumentTrading(const std::string& ticker) {
    FinancialAsset* instance = FinancialAsset::getInstance();
    if (instance->instruments_.find(ticker) == instance->instruments_.end()) {
        return {false, ticker};
    }
    instance->instruments_.erase(ticker);
    return {true, "Ticker: " + ticker + " removed."};
}

void FinancialAsset::initialize(const std::string& name) {
    if (!instance_) {
        instance_ = std::make_unique<FinancialAsset>(name);
    }
}

FinancialAsset* FinancialAsset::getInstance() {
    return instance_.get();
}

std::string FinancialAsset::getName() const {
    return name_;
}
