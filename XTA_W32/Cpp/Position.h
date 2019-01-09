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
		virtual ~Position(){};
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
		int64_t PositionToday = 0;
        // 昨仓
		int64_t PositionYesterday = 0;

        // 交易方向
        DirectionKind Direction = DirectionKind::Sell;

        // 净仓 = 今买仓 - 今卖仓 + 昨仓(昨仓根据昨仓买卖方向添正负号)
		int64_t NetPosition = 0;
        // 今买仓
		int64_t BuyPosition = 0;
        // 今卖仓
		int64_t SellPosition = 0;
		// 昨仓买卖方向
		DirectionKind PositionYesDirection = DirectionKind::Buy;
		// 历史持仓 (固定不变)
		int64_t YdPosition = 0;

		// 持仓交易所占用保证金
		double ExchangeMargin = DOUBLE_DEFAULT;

		// 总持仓
		int64_t PositionTotal = 0;
		// 可卖持仓
		int64_t PositionSellable = 0;
		// 持仓成本
		double AvgPrice = 0;
    };
}
}
