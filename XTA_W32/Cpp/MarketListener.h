#pragma once

#include "Instrument.h"
#include "NotifyParams.h"
#include "QueryParams.h"

namespace XFinApi
{
namespace TradeApi
{
    // 行情事件监听器
    class MarketListener
    {
    public:
        virtual ~MarketListener() {}

        // 响应通知
        virtual void OnNotify(const NotifyParams &notifyParams) {}
        // 响应合约订阅
        virtual void OnSubscribed(const QueryParams &instInfo) {}
        // 响应合约退订
        virtual void OnUnsubscribed(const QueryParams &instInfo) {}
        // 响应行情数据
        virtual void OnTick(const Tick &tick) {}
    };
}
}
