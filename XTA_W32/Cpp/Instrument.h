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
			Instrument() {};
			virtual ~Instrument() {};

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
			double VolumeMultiple = 0.0;
			// 最小变动价位
			double PriceTick = 0.0;
			//价格最小变化位数
			int64_t PricePrecision = 0;

			// 当前是否交易
			bool IsTrading = false;
			// 是否使用大额单边保证金算法
			bool MaxMarginSideAlgorithm = false;
			// 合约状态
			InstrumentStatusKind Status = InstrumentStatusKind::NoTrading;

			// 执行价
			double StrikePrice = DOUBLE_DEFAULT;
			// 期权类型
			int32_t OptionsType = INT32_DEFAULT;
			// 合约基础商品乘数
			double UnderlyingMultiple = DOUBLE_DEFAULT;
			// 组合类型
			int32_t CombinationType = INT32_DEFAULT;
			// 期权执行方式
			int32_t StrikeModeType = INT32_DEFAULT;

			// 持仓
			// 多今仓
			int64_t PositionBuyToday = 0;
			// 多昨仓
			int64_t PositionBuyYesterday = 0;
			// 多总持仓
			int64_t PositionBuy = 0;
			// 空今仓
			int64_t PositionSellToday = 0;
			// 空昨仓
			int64_t PositionSellYesterday = 0;
			// 空总持仓
			int64_t PositionSell = 0;
			// 总持仓
			int64_t PositionTotal = 0;
			// 撤单数
			int64_t CanceledOrderCount = 0;
			// 报单总数
			int64_t AddOrderCount = 0;
			// 成交总数
			int64_t SumTradeVolume = 0;

			// 买开总数
			int64_t BuyOpenSum = 0;
			// 卖开总数
			int64_t SellOpenSum = 0;

			// 报单未成交数
			// 开仓未成交数
			int64_t UntradeOpen = 0;
			// 买开未成交数
			int64_t UntradeBuyOpen = 0;
			// 卖开未成交数
			int64_t UntradeSellOpen = 0;
			// 平仓未成交数
			int64_t UntradeClose = 0;
			// 买平未成交数
			int64_t UntradeBuyClose = 0;
			// 卖平未成交数
			int64_t UntradeSellClose = 0;

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
			double LongAvgPrice = 0.0;
			// 空持仓均价
			double ShortAvgPrice = 0.0;

			// 冻结保证金
			double FrozenMargin = 0.0;
			// 多冻结保证金
			double LongFrozenMargin = 0.0;
			// 空冻结保证金
			double ShortFrozenMargin = 0.0;

			// 冻结手续费
			double FrozenCommission = 0.0;
			// 开仓冻结手续费
			double OpenFrozenCommission = 0.0;
			// 平仓冻结手续费
			double CloseFrozenCommission = 0.0;
			// 平今冻结手续费
			double CloseTodayFrozenCommission = 0.0;

			// 平仓盈亏
			double CloseProfit = 0.0;
			// 多平仓盈亏
			double LongCloseProfit = 0.0;
			// 空平仓盈亏
			double ShortCloseProfit = 0.0;

			// 占用保证金
			double CurrMargin = 0.0;
			// 多头占用保证金
			double LongCurrMargin = 0.0;
			// 空头占用保证金
			double ShortCurrMargin = 0.0;

			// 手续费
			double Commission = 0.0;
			// 开仓手续费
			double OpenCommission = 0.0;
			// 平仓手续费
			double CloseCommission = 0.0;
			// 平今手续费
			double CloseTodayCommission = 0.0;

			// 持仓盈亏
			double PositionProfit = 0.0;
			// 多仓持仓盈亏
			double LongPositionProfit = 0.0;
			// 空仓持仓盈亏
			double ShortPositionProfit = 0.0;

			// 卖开仓手续费率
			double SellOpenRatioByMoney = DOUBLE_DEFAULT;
			// 卖平仓手续费率
			double SellCloseRatioByMoney = DOUBLE_DEFAULT;
			// 卖平今手续费率
			double SellCloseTodayRatioByMoney = DOUBLE_DEFAULT;
			// 卖开仓手续费
			double SellOpenRatioByVolume = DOUBLE_DEFAULT;
			// 卖平仓手续费
			double SellCloseRatioByVolume = DOUBLE_DEFAULT;
			// 卖平今手续费
			double SellCloseTodayRatioByVolume = DOUBLE_DEFAULT;
			// 标的物昨结算价或昨收盘价
			double ObjectPrice = DOUBLE_DEFAULT;
			// 标的物保证金费率
			double ObjectMarginRatioByMoney = DOUBLE_DEFAULT;
			// 标的物保证金费费
			double ObjectMarginRatioByVolume = DOUBLE_DEFAULT;
			// 50ETF保障系数1
			double EnsureRatio1 = DOUBLE_DEFAULT;
			// 50ETF保障系数2
			double EnsureRatio2 = DOUBLE_DEFAULT;
			// 平仓方式
			CloseStyleTypeKind CloseStyleType = CloseStyleTypeKind::Close;
			// 区分今昨
			bool IsCloseToday = true;
			// 今仓保证金价格
			UserRightTypeKind TodayUserRightType = UserRightTypeKind::OpenPrice;
			// 昨仓保证金价格
			UserRightTypeKind YesterdayUserRightType = UserRightTypeKind::PreSettlementPrice;

		};
	}
}
