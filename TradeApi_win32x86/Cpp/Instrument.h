#pragma once

#include "XFinApiCommon.h"
#include "Tick.h"
#include "ApiEnum.h"

//////////////////////////////////////////////////////////////////////////
namespace XFinApi
{
namespace TradeApi
{
	// 合约信息
    class Instrument
    {
    public:
        // 合约代码
        std::string InstrumentID;
        // 交易所代码
        std::string ExchangeID;
        // 合约名称
        std::string InstrumentName;
        // 合约在交易所的代码
        std::string ExchangeInstID;
        // 产品代码
        std::string ProductID;
        // 品种类别
        ProductKind ProductType = ProductKind::Futures;
        // 交割年份
        std::string DeliveryYear;
        // 交割月
        std::string DeliveryMonth;
        // 创建日
        std::string CreateDate;
        // 上市日
        std::string OpenDate;
        // 到期日
        std::string ExpireDate;
        // 开始交割日
        std::string StartDelivDate;
        // 结束交割日
        std::string EndDelivDate;

        // 当前行情
        Tick LastTick;

        // 市价单最大下单量
        int64_t MaxMarketOrderVolume = INT64_DEFAULT;
        // 市价单最小下单量
        int64_t MinMarketOrderVolume = INT64_DEFAULT;
        // 限价单最大下单量
        int64_t MaxLimitOrderVolume = INT64_DEFAULT;
        // 限价单最小下单量
        int64_t MinLimitOrderVolume = INT64_DEFAULT;
        // 合约数量乘数
        double VolumeMultiple = DOUBLE_DEFAULT;
        // 最小变动价位
        double PriceTick = DOUBLE_DEFAULT;
        //价格最小变化位数
        int PricePrecision = 0;

        // 当前是否交易
        bool IsTrading = false;
        // 是否使用大额单边保证金算法
        bool MaxMarginSideAlgorithm = false;
        // 合约状态
        InstrumentStatus Status = InstrumentStatus::NoTrading;

        // 执行价
        double StrikePrice = DOUBLE_DEFAULT;
        // 期权类型
        int OptionsType = INT32_DEFAULT;
        // 合约基础商品乘数
        double UnderlyingMultiple = DOUBLE_DEFAULT;
        // 组合类型
        int CombinationType = INT32_DEFAULT;
        // 期权执行方式
        int StrikeModeType = INT32_DEFAULT;

        // 持仓
        // 多今仓
        int PositionBuyToday = INT32_DEFAULT;
        // 多昨仓
        int PositionBuyYesterday = INT32_DEFAULT;
        // 多总持仓
        int PositionBuy = INT32_DEFAULT;
        // 空今仓
        int PositionSellToday = INT32_DEFAULT;
        // 空昨仓
        int PositionSellYesterday = INT32_DEFAULT;
        // 空总持仓
        int PositionSell = INT32_DEFAULT;
        // 总持仓
        int PositionTotal = INT32_DEFAULT;
        // 撤单数
        int CanceledOrderCount = INT32_DEFAULT;
        // 报单总数
        int AddOrderCount = INT32_DEFAULT;
        // 成交总数
        int SumTradeVolume = INT32_DEFAULT;

        // 买开总数
        int BuyOpenSum = INT32_DEFAULT;
        // 卖开总数
        int SellOpenSum = INT32_DEFAULT;

        // 报单未成交数
        // 开仓未成交数
        int UntradeOpen = INT32_DEFAULT;
        // 买开未成交数
        int UntradeBuyOpen = INT32_DEFAULT;
        // 卖开未成交数
        int UntradeSellOpen = INT32_DEFAULT;
        // 平仓未成交数
        int UntradeClose = INT32_DEFAULT;
        // 买平未成交数
        int UntradeBuyClose = INT32_DEFAULT;
        // 卖平未成交数
        int UntradeSellClose = INT32_DEFAULT;

        // 手续费率
        // 开仓手续费率
        double OpenRatioByMoney = DOUBLE_DEFAULT;
        // 平仓手续费率
        double CloseRatioByMoney = DOUBLE_DEFAULT;
        // 平今手续费率
        double CloseTodayRatioByMoney = DOUBLE_DEFAULT;
        // 开仓手续费
        double OpenRatioByVolume = DOUBLE_DEFAULT;
        // 平仓手续费
        double CloseRatioByVolume = DOUBLE_DEFAULT;
        // 平今手续费
        double CloseTodayRatioByVolume = DOUBLE_DEFAULT;

        // 印花税率
        double StampTaxRateByMoney = DOUBLE_DEFAULT;
        // 印花税率(按手数)
        double StampTaxRateByVolume = DOUBLE_DEFAULT;
        // 过户费率
        double TransferFeeRateByMoney = DOUBLE_DEFAULT;
        // 过户费率(按手数)
        double TransferFeeRateByVolume = DOUBLE_DEFAULT;
        // 交易费
        double TradeFeeByMoney = DOUBLE_DEFAULT;
        // 交易费(按手数)
        double TradeFeeByVolume = DOUBLE_DEFAULT;
        // 交易附加费率
        double MarginByMoney = DOUBLE_DEFAULT;
        // 最小交易费
        double MinTradeFee = DOUBLE_DEFAULT;
        // 最小过户费
        double MinTransferFee = DOUBLE_DEFAULT;

        // 保证金费率
        // 投机 Speculation
        // 多头保证金率
        double SpLongMarginRatioByMoney = DOUBLE_DEFAULT;
        // 多头保证金额
        double SpLongMarginRatioByVolume = DOUBLE_DEFAULT;
        double SpShortMarginRatioByMoney = DOUBLE_DEFAULT;
        double SpShortMarginRatioByVolume = DOUBLE_DEFAULT;
        // 套利 Arbitrage
        double ArLongMarginRatioByMoney = DOUBLE_DEFAULT;
        double ArLongMarginRatioByVolume = DOUBLE_DEFAULT;
        double ArShortMarginRatioByMoney = DOUBLE_DEFAULT;
        double ArShortMarginRatioByVolume = DOUBLE_DEFAULT;
        // 套保 Hedge
        double HeLongMarginRatioByMoney = DOUBLE_DEFAULT;
        double HeLongMarginRatioByVolume = DOUBLE_DEFAULT;
        double HeShortMarginRatioByMoney = DOUBLE_DEFAULT;
        double HeShortMarginRatioByVolume = DOUBLE_DEFAULT;

        // 资金相关
        // 多持仓均价
        double LongAvgPrice = DOUBLE_DEFAULT;
        // 空持仓均价
        double ShortAvgPrice = DOUBLE_DEFAULT;

        // 冻结保证金
        double FrozenMargin = DOUBLE_DEFAULT;
        // 多冻结保证金
        double LongFrozenMargin = DOUBLE_DEFAULT;
        // 空冻结保证金
        double ShortFrozenMargin = DOUBLE_DEFAULT;

        // 冻结手续费
        double FrozenCommission = DOUBLE_DEFAULT;
        // 开仓冻结手续费
        double OpenFrozenCommission = DOUBLE_DEFAULT;
        // 平仓冻结手续费
        double CloseFrozenCommission = DOUBLE_DEFAULT;
        // 平今冻结手续费
        double CloseTodayFrozenCommission = DOUBLE_DEFAULT;

        // 平仓盈亏
        double CloseProfit = DOUBLE_DEFAULT;
        // 多平仓盈亏
        double LongCloseProfit = DOUBLE_DEFAULT;
        // 空平仓盈亏
        double ShortCloseProfit = DOUBLE_DEFAULT;

        // 占用保证金
        double CurrMargin = DOUBLE_DEFAULT;
        // 多头占用保证金
        double LongCurrMargin = DOUBLE_DEFAULT;
        // 空头占用保证金
        double ShortCurrMargin = DOUBLE_DEFAULT;

        // 手续费
        double Commission = DOUBLE_DEFAULT;
        // 开仓手续费
        double OpenCommission = DOUBLE_DEFAULT;
        // 平仓手续费
        double CloseCommission = DOUBLE_DEFAULT;
        // 平今手续费
        double CloseTodayCommission = DOUBLE_DEFAULT;

        // 持仓盈亏
        double PositionProfit = DOUBLE_DEFAULT;
        // 多仓持仓盈亏
        double LongPositionProfit = DOUBLE_DEFAULT;
        // 空仓持仓盈亏
        double ShortPositionProfit = DOUBLE_DEFAULT;
    };
}
}
