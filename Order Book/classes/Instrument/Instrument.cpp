#include "../../Include/Instrument/instrument.h"

Instrument::Instrument(const std::string &asset_, const EquityType &instrumentType, const std::string &ticker): asset_(asset_),instrumentType(instrumentType),ticker(ticker),trade_ledger(std::make_unique<TradeLedger>()){};

Instrument::Instrument(const Instrument &other){
    this->asset = other.asset;
    this->instrumentType = other.instrumentType;
    this->ticker = other.ticker;
    this-trade_ledger = std::make_unique<TradeLedger>(*other.trade_ledger);
};

TradeLedger *Instrument::getTradeLedger()const{
    return this->tradeLedger.get();
};

std::string Instrument::getAsset() const{
    return this->asset;
};

EquityType Instrument::getInstrumentType()const{
    return this->instrumentType;
};

std::string Instrument::getTicker()const{
    return this->ticker;
};