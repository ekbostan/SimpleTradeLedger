#ifndef TRADELEDGER
#define TRADELEDGER_H

#include <map>
#include <unordered_map>
#include <deque>
#include <memory>
#include <iostream>
#include <algorithm>


enum OrderType{
    AT_MARKET,
    LIMIT,
    STOP,
    STOP_LIMIT,
    TRAILING_STOP,
};

struct Order{
    long double price;
    int quantity;
    OrderType type;
    Order(long double price, int quantity, OrderType type);

};

class TradeLedger{
    public:
        TradeLedger(){}
        ~TradeLedger(){}

        void placeOrder(const Order& order);
        void cancelOrder(const Order& order);
        void modifyOrder(const Order& oldOrder ,const Order& newOrder);

    private:
        std::deque<Order>orders;
        void processAtMarketOrder(const Order& order);
        void processLimitOrder(const Order& order);
        void processStopOrder(const Order& order);
        void processStopLimitOrder(const Order& order);
        void processTrailingStopOrder(const Order& order);


        void matchOrders();
        void executeOrder(const Order& order);

};

void TradeLedger::placeOrder(const Order& order){
    switch(order.type){
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
            std::cout<<"Order type not supported yet.\n";
            break;
    }
    matchOrders();
}



#endif