#pragma once

#include "XFinApiCommon.h"
#include "ApiEnum.h"

namespace XFinApi
{
namespace TradeApi
{
    // 持仓信息
    struct Position
    {
        // 投资者代码
        std::string InvestorID;
        // 经纪公司代码
        std::string BrokerID;
        // 交易所代码
        std::string ExchangeID;
        // 品种代码
        std::string ProductID;
        // 合约代码
        std::string InstrumentID;

        // 上次结算价
        double PreSettlementPrice = DOUBLE_DEFAULT;

        // 今仓
        int32_t PositionToday = 0;
        // 昨仓
		int32_t PositionYesterday = 0;

        // 交易方向
        TradeDirection Direction = TradeDirection::Sell;

        // 净仓 = 今买仓 - 今卖仓 + 昨仓(昨仓根据昨仓买卖方向添正负号)
		int32_t NetPosition = 0;
        // 今买仓
		int32_t BuyPosition = 0;
        // 今卖仓
		int32_t SellPosition = 0;
		// 昨仓买卖方向
		TradeDirection PositionYesDirection = TradeDirection::Buy;
    };
}
}
