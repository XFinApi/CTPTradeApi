#pragma once

#include "XFinApiCommon.h"

namespace XFinApi
{
	namespace TradeApi
	{
		// 账户信息
		struct Account
		{
			// 资金账号
			std::string AccountID;
			// 上次结算准备金,ESI上日结存
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
			// 投资者交割保证金
			double DeliveryMargin = 0.0;
			//冻结保证金
			double FrozenMargin = 0.0;
			//冻结的手续费	
			double FrozenCommission = 0.0;
			//冻结的资金	
			double FrozenCash = 0.0;
			//当前占用保证金总额	
			double CurrMargin = 0.0;
			//手续费	
			double Commission = 0.0;
			//平仓盈亏	
			double CloseProfit = 0.0;
			//持仓盈亏	
			double PositionProfit = 0.0;
			//可用资金, SP购买力(=信贷限额+现金结余+商品盈亏-基本保証金)，ESI当日可用
			double Available = 0.0;
			//期货结算准备金，ESI当日结存
			double Balance = 0.0;
			//静态权益
			double StaticRights = 0;
			//动态权益
			double ChangingRights = 0;

			//SP
			//资产净值（=现金结余+商品盈亏）
			double NetAssetValue = 0.0;
			//信贷限额
			double CreditLimit = 0.0;
			//现金结余
			double CashBal = 0.0;
			//基本保証金
			double IMargin = 0.0;
			//維持保証金
			double MMargin = 0.0;
			//商品盈亏
			double CommodityPL = 0.0;

			//ESI
			// 上日权益
			double PreEquity;
			// 上日可用
			double PreAvailable;
			// 上日市值权益
			double PreMarketEquity;
			// 客户初始保证金
			double AccountIntialMargin;
			// 客户维持保证金
			double AccountMaintenanceMargin;
			// 当日权益
			double Equity;
			// 可提取
			double CanDraw;
			// 账户市值
			double MarketEquity;
		};
	}
}
