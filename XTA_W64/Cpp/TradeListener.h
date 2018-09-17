#pragma once

#include "Order.h"
#include "TradeOrder.h"
#include "Instrument.h"
#include "Account.h"
#include "Position.h"
#include "NotifyParams.h"
#include <vector>

namespace XFinApi
{
namespace TradeApi
{
    // 交易事件监听器
    class TradeListener
    {
    public:
        virtual ~TradeListener() {}

        // 响应通知
        virtual void OnNotify(const NotifyParams &notifyParams) {}
        // 响应委托单更新
        virtual void OnUpdateOrder(const Order &order) {}
        // 响应成交单更新
        virtual void OnUpdateTradeOrder(const TradeOrder &trade) {}
        // 响应查询委托单结果
        virtual void OnQueryOrder(const std::vector<Order> &orders) {}
        // 响应查询成交单结果
        virtual void OnQueryTradeOrder(const std::vector<TradeOrder> &trades) {}
        // 响应查询合约结果
        virtual void OnQueryInstrument(const std::vector<Instrument> &insts) {}
        // 响应查询持仓结果
        virtual void OnQueryPosition(const std::vector<Position> &positions) {}
        // 响应查询资金账户结果
        virtual void OnQueryAccount(const Account &accounts) {}
    };
}
}
