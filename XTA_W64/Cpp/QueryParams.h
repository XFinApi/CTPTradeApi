#pragma once

#include "XFinApiCommon.h"
#include "ApiEnum.h"

namespace XFinApi
{
namespace TradeApi
{
    // 查询参数
	struct QueryParams
    {
		virtual ~QueryParams() {};
        // 投资者代码
        std::string InvestorID;
        // 经纪公司代码
        std::string BrokerID;
        // 交易所代码
        std::string ExchangeID;
        std::string ExchangeInstID;
        // 合约代码
        std::string InstrumentID;

        // 产品类别
        ProductKind ProductType = ProductKind::Futures;
        // 产品代码
		std::string ProductID;
        // 报单代码
		std::string OrderID;
        // 成交代码
		std::string TradeID;

        // 报单开始时间
		std::string InsertTimeStart;
        // 报单结束时间
        std::string InsertTimeEnd;
        // 成交开始时间
        std::string TradeTimeStart;
        // 成交结束时间
		std::string TradeTimeEnd;

        // 货币代码
        std::string CurrencyID;

	    // 投机套保类型
        HedgeKind HedgeType = HedgeKind::Speculation;
	};
}
}
