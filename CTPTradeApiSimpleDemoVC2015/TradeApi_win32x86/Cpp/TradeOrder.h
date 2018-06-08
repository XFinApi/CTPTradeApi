#pragma once

#include "XFinApiCommon.h"
#include "ApiEnum.h"

namespace XFinApi
{
namespace TradeApi
{
    // 成交单信息
    struct TradeOrder
    {
        // 交易所代码
        std::string ExchangeID;
        // 品种代码
        std::string ProductID;
        // 合约代码
        std::string InstrumentID;
        // 成交时间
        std::string TradeTime;
        // 交易日期
        std::string TradingDay;
        // 更新时间
        std::string UpdateTime;

        // 报单代码
        std::string OrderID;
        // 成交代码
        std::string TradeID;

        // 价格
        double Price = DOUBLE_DEFAULT;
        // 数量
        int64_t Volume = INT64_DEFAULT;
        // 未平仓量
        int64_t UnCloseVolume = INT64_DEFAULT;

        // 交易方向
        TradeDirection Direction = TradeDirection::Sell;
        // 开平类型
        OpenCloseKind OpenCloseType = OpenCloseKind::Open;
        // 投机套保类型
        HedgeKind HedgeType = HedgeKind::Speculation;
        // 是否昨单
        Boolean IsYesterdayTrade = Boolean::Default;

        // 平仓盈亏
        double CloseProfit = DOUBLE_DEFAULT;
        // 占用保证金
        double CurrMargin = DOUBLE_DEFAULT;
        // 手续费
        double Commission = DOUBLE_DEFAULT;
    };
}
}
