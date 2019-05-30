#pragma once

#include "XFinApiCommon.h"
#include "ApiEnum.h"

#define PRICE_TIERS	20
#define OUT_OF_PRICE_TIERS(_idx)	(_idx < 0 || _idx >= PRICE_TIERS)
//////////////////////////////////////////////////////////////////////////
namespace XFinApi
{
namespace TradeApi
{
    // 行情信息
    class Tick
    {
    public:
        Tick()
        {
            for (auto &elem : BidPrice)
                elem = DOUBLE_DEFAULT;
            for (auto &elem : AskPrice)
                elem = DOUBLE_DEFAULT;
            for (auto &elem : BidVolume)
                elem = INT64_DEFAULT;
            for (auto &elem : AskVolume)
                elem = INT64_DEFAULT;
        }

		virtual ~Tick() {};

        // 合约代码
        std::string InstrumentID;
        // 交易所代码
        std::string ExchangeID;
        // 合约在交易所的代码
        std::string ExchangeInstID;
		// 产品代码
		std::string ProductID;
        // 交易日
        std::string TradingDay;
        // 行情时间
        std::string TradingTime;
        // 本地日期时间
        std::string LocalTime;
        // 交易状态
        int TradingState = INT32_DEFAULT;
        // 趋势
        int Trend = INT32_DEFAULT;
        // 昨收盘
        double PreClosePrice = DOUBLE_DEFAULT;
        // 上次结算价
        double PreSettlementPrice = DOUBLE_DEFAULT;
        // 昨持仓量
        double PreOpenInterest = DOUBLE_DEFAULT;

        // 涨停板价
        double UpperLimitPrice = DOUBLE_DEFAULT;
        // 跌停板价
        double LowerLimitPrice = DOUBLE_DEFAULT;
        // 昨虚实度
        double PreDelta = DOUBLE_DEFAULT;
        // 今虚实度
        double CurrDelta = DOUBLE_DEFAULT;
        // 最新价
        double LastPrice = DOUBLE_DEFAULT;
        // 最新量
        int64_t LastVolume = INT64_DEFAULT;
        // 买价20档
        double BidPrice[PRICE_TIERS] = {};
        // 买量20档
        int64_t BidVolume[PRICE_TIERS] = {};
        // 卖价20档
        double AskPrice[PRICE_TIERS] = {};
        // 卖量20档
        int64_t AskVolume[PRICE_TIERS] = {};
        // 当日均价
        double AveragePrice = DOUBLE_DEFAULT;
        // 今开盘
        double OpenPrice = DOUBLE_DEFAULT;
        // 最高价
        double HighestPrice = DOUBLE_DEFAULT;
        // 最低价
        double LowestPrice = DOUBLE_DEFAULT;
        // 成交金额
        double TotalTurnover = DOUBLE_DEFAULT;
        // 成交量
        int64_t TotalVolume = INT64_DEFAULT;
        // 持仓量
        double OpenInterest = DOUBLE_DEFAULT;
        // 今收盘
        double ClosePrice = DOUBLE_DEFAULT;
        // 本次结算价
        double SettlementPrice = DOUBLE_DEFAULT;

        // 隐含买价
        double ImpliedBidPrice = DOUBLE_DEFAULT;
        // 隐含买量
        int64_t ImpliedBidVolume = INT64_DEFAULT;
        // 隐含卖价
        double ImpliedAskPrice = DOUBLE_DEFAULT;
        // 隐含卖量
        int64_t ImpliedAskVolume = INT64_DEFAULT;

        // 内盘量
        int64_t InsideVolume = INT64_DEFAULT;
        // 外盘量
        int64_t OutsideVolume = INT64_DEFAULT;
        // 换手率
        double TurnoverRate = DOUBLE_DEFAULT;
        // 市盈率
        double PERatio = DOUBLE_DEFAULT;
        // 总市值
        double TotalValue = DOUBLE_DEFAULT;
        // 流通市值
        double NegotiableValue = DOUBLE_DEFAULT;
        // 涨速
        double ChangeSpeed = DOUBLE_DEFAULT;
        // 涨幅
        double ChangeRate = DOUBLE_DEFAULT;
        // 涨跌值
        double ChangeValue = DOUBLE_DEFAULT;
        // 振幅
        double Swing = DOUBLE_DEFAULT;
        // 委买总量
        int64_t TotalBidVolume = INT64_DEFAULT;
        // 委卖总量
        int64_t TotalAskVolume = INT64_DEFAULT;

        // 开仓限制
        int OpenRestriction = INT32_DEFAULT;
		// 业务日期
		std::string ActionDay;
		// 交易状态
		InstrumentStatusKind InstrumentStatus = InstrumentStatusKind::Unknown;

    public:
        double GetBidPrice(int idx)
        {
            if (OUT_OF_PRICE_TIERS(idx))
                return DOUBLE_DEFAULT;
            return BidPrice[idx];
        }
        void SetBidPrice(int idx, double val)
        {
            if (OUT_OF_PRICE_TIERS(idx))
                return;
            BidPrice[idx] = val;
        }

        int64_t GetBidVolume(int idx)
        {
            if (OUT_OF_PRICE_TIERS(idx))
                return INT64_DEFAULT;
            return BidVolume[idx];
        }
        void SetBidVolume(int idx, int64_t val)
        {
            if (OUT_OF_PRICE_TIERS(idx))
                return;
            BidVolume[idx] = val;
        }

        double GetAskPrice(int idx)
        {
            if (OUT_OF_PRICE_TIERS(idx))
                return DOUBLE_DEFAULT;
            return AskPrice[idx];
        }
        void SetAskPrice(int idx, double val)
        {
            if (OUT_OF_PRICE_TIERS(idx))
                return;
            AskPrice[idx] = val;
        }

        int64_t GetAskVolume(int idx)
        {
            if (OUT_OF_PRICE_TIERS(idx))
                return INT64_DEFAULT;
            return AskVolume[idx];
        }
        void SetAskVolume(int idx, int64_t val)
        {
            if (OUT_OF_PRICE_TIERS(idx))
                return;
            AskVolume[idx] = val;
        }
    };
}
}
