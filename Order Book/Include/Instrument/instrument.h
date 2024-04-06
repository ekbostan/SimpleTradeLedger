#ifndef INSTRUMENT_H
#define INSTRUMENT_H

#include <string>
#include <map>
#include <stdio.h>
#include <memory>

#include "../TradeLedger/trade_ledger.h"


enum EquityType {
    FUTURES,
    STOCK,
    OPTIONS,
    ETF,
    BONDS,
    WARRANTS,
    PREFERRED_STOCK,
    CONVERTIBLE_BONDS,
    ADR,
    REIT,
    DERIVATIVES,
    CLOSED_END_FUNDS,
    INDEX_FUNDS,
    EXCHANGE_TRADED_NOTES,
};

class Instrument{
    private:
    std::string asset_;
    EquityType instrumentType;
    std::string ticker;
    std::unique_ptr<TradeLedger> trade_ledger;

    public:
    Instrument(const std::string &asset, const EquityType& instrumentType, const std::string& ticker);
    Instrument(const Instrument& other);

    std::string getAsset() const;
    EquityType getInstrumentType() const;
    std::string getTicker() const;
    TradeLedger* getTradeLedger() const;

};

#endif