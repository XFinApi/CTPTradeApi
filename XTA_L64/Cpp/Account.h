#pragma once

#include "XFinApiCommon.h"

namespace XFinApi
{
	namespace TradeApi
	{
		// 账户信息
		struct Account
		{
			virtual ~Account() {};

			// 资金账号
			std::string AccountID;
			// 上次结算准备金,ESI上日结存，ZDCTP昨结存
			double PreBalance = 0.0;
			// 上次信用额度
			double PreCredit = 0.0;
			// 上次质押金额
			double PreMortgage = 0.0;
			// 质押金额
			double Mortgage = 0.0;
			// 出金金额
			double Withdraw = 0.0;
			// 入金金额
			double Deposit = 0.0;
			//静态权益,UFX期初客户权益,SP现金结余（CashBal）
			double StaticBalance = 0;
			
			//平仓盈亏，UFX平仓盯市盈亏，SP商品盈亏（CommodityPL）,XTP(累计卖出成交证券所得资金-累计买入成交证券占用资金),
			double CloseProfit = 0.0;
			//持仓盈亏,UFX持仓浮动盈亏，
			double PositionProfit = 0.0;
			//手续费,UFX成交手续费金额,XTP(累计卖出成交交易费用+累计买入成交交易费用)
			double Commission = 0.0;
			//动态权益，期货结算准备金，ESI当日结存，ZDCTP今结存,UFX客户权益,SP资产净值（NetAssetValue=现金结余+商品盈亏）,XTP总资产
			double Balance = 0.0;
			
			//当前占用保证金总额,UFX持仓保证金,SP基本保証金，ESI客户初始保证金AccountIntialMargin
			double CurrMargin = 0.0;
			// 维持保证金，ESI客户维持保证金AccountMaintenanceMargin，SP維持保証金，ZDCTP维持保证金
			double MaintenanceMargin = 0.0;
			// 投资者交割保证金
			double DeliveryMargin = 0.0;
			//冻结保证金
			double FrozenMargin = 0.0;
			//冻结的手续费，UFX委托费用
			double FrozenCommission = 0.0;
			//冻结的资金,UFX当日开仓预冻结金额	
			double FrozenCash = 0.0;
			//信用额度
			double CreditLimit = 0.0;
			//可用资金，ESI当日可用CanDraw,ZDCTP今可用,UFX可用资金,购买力 (BuyingPower=信贷限额+现金结余+商品盈亏-基本保証金)
			double Available = 0.0;
			
			//ZDCTP
			//ZDCTP币种,UFX货币类别
			std::string CurrencyNo;
		};
	}
}
