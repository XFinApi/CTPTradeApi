#pragma once

#include "XFinApiCommon.h"
#include "ApiEnum.h"

namespace XFinApi
{
namespace TradeApi
{
    // 委托单信息
    struct Order
    {
		virtual ~Order() {};
        // 投资者代码
        std::string InvestorID;
        // 经纪公司代码
        std::string BrokerID;
        // 交易所代码
        std::string ExchangeID;
        // 品种类别
        ProductKind ProductType = ProductKind::Futures;
        // 品种代码
        std::string ProductID;
        // 合约代码
        std::string InstrumentID;
        // 下单时间
        std::string OrderTime;
        // 撤单时间
        std::string CancelTime;
        // 交易日期
        std::string TradingDay;
        // 更新时间
        std::string UpdateTime;
        // 状态消息
        std::string StatusMsg;

        // 报单引用
        std::string OrderRef;
        // 交易所委托编号
        std::string OrderID;

        // 前置机代码
        int64_t FrontID = INT64_DEFAULT;
        // 会话代码
        int64_t SessionID = INT64_DEFAULT;

		// 本地委托编号
		std::string	OrderLocalNo;
		// 柜台委托编号
		std::string	OrderCounterNo;

        // 价格
        double Price = DOUBLE_DEFAULT;
        // 数量
		int64_t Volume = 0;
        // 未成交量
		int64_t NoTradedVolume = 0;

        // 报单状态
        OrderStatusKind Status = OrderStatusKind::Unknown;
        // 交易方向
        DirectionKind Direction = DirectionKind::Sell;
        // 开平类型
        OpenCloseKind OpenCloseType = OpenCloseKind::Open;
        // 价格条件
        PriceConditionKind PriceCond = PriceConditionKind::LimitPrice ;
        // 有效期条件
        TimeConditionKind TimeCond = TimeConditionKind::GFD;
        // 成交量条件
        VolumeConditionKind VolumeCond = VolumeConditionKind::AnyVolume;
        // 投机套保类型
        HedgeKind HedgeType = HedgeKind::Speculation;
        // 委托类型
        OrderKind OrderType = OrderKind::Order;
        // 动作类型
        OrderActionKind ActionType = OrderActionKind::Insert;
		// 执行结果
		ExecResultKind ExecResult = ExecResultKind::NoExec;
		// 执行条件
		ContingentCondKind ContingentCond = ContingentCondKind::Immediately;

        // 冻结保证金
        double FrozenMargin = 0.0;
        // 冻结手续费
        double FrozenCommission = 0.0;

        // 冰山单显示数量
		int64_t ShowVolume = 0;
		// 最小成交量
		int64_t MinVolume = 0;

        //价格最小变化位数
		int32_t PricePrecision = 0;
    };
}
}
