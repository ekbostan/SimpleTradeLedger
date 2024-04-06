#include "../../Include/TradeLedger/trade_ledger.h" 

TradeLedger::TradeLedger() = default;

TradeLedger::~TradeLedger() = default;

void TradeLedger::placeOrder(const Order& order) {
    switch (order.type) {
        case AT_MARKET:
            processAtMarketOrder(order);
            break;
        case LIMIT:
            processLimitOrder(order);
            break;
        case STOP:
            processStopOrder(order);
            break;
        case STOP_LIMIT:
            processStopLimitOrder(order);
            break;
        case TRAILING_STOP:
            processTrailingStopOrder(order);
            break;
        default:
            std::cout << "Order type not supported yet.\n";
            break;
    }
    matchOrders();
}

void TradeLedger::cancelOrder(const Order& order) {
}

void TradeLedger::modifyOrder(const Order& oldOrder, const Order& newOrder) {
}

void TradeLedger::processAtMarketOrder(const Order& order) {
    
    std::cout << "Processing At Market Order: Price " << order.price << ", Quantity " << order.quantity << std::endl;
}

void TradeLedger::processLimitOrder(const Order& order) {
   
    std::cout << "Processing Limit Order: Price " << order.price << ", Quantity " << order.quantity << std::endl;
}

void TradeLedger::processStopOrder(const Order& order) {
    
    std::cout << "Processing Stop Order: Price " << order.price << ", Quantity " << order.quantity << std::endl;
}

void TradeLedger::processStopLimitOrder(const Order& order) {
   
    std::cout << "Processing Stop Limit Order: Price " << order.price << ", Quantity " << order.quantity << std::endl;
}

void TradeLedger::processTrailingStopOrder(const Order& order) {
   
    std::cout << "Processing Trailing Stop Order: Price " << order.price << ", Quantity " << order.quantity << std::endl;
}

void TradeLedger::matchOrders() {
   
}

void TradeLedger::executeOrder(const Order& order) {
  
    std::cout << "Executing Order: Price " << order.price << ", Quantity " << order.quantity << std::endl;
}
