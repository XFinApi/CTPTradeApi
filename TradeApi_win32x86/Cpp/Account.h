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
			// 上次结算准备金
			double PreBalance = DOUBLE_DEFAULT;
			// 上次信用额度
			double PreCredit = DOUBLE_DEFAULT;
			// 上次质押金额
			double PreMortgage = DOUBLE_DEFAULT;
			// 质押金额
			double Mortgage = DOUBLE_DEFAULT;
			// 出金金额
			double Withdraw = DOUBLE_DEFAULT;
			// 入金金额
			double Deposit = DOUBLE_DEFAULT;
			// 投资者交割保证金
			double DeliveryMargin = DOUBLE_DEFAULT;
			//冻结保证金
			double FrozenMargin = DOUBLE_DEFAULT;
			//冻结的手续费	
			double FrozenCommission = DOUBLE_DEFAULT;
			//冻结的资金	
			double FrozenCash = DOUBLE_DEFAULT;
			//当前占用保证金总额	
			double CurrMargin = DOUBLE_DEFAULT;
			//手续费	
			double Commission = DOUBLE_DEFAULT;
			//平仓盈亏	
			double CloseProfit = DOUBLE_DEFAULT;
			//持仓盈亏	
			double PositionProfit = DOUBLE_DEFAULT;
			//可用资金, 购买力(=信贷限额+现金结余+商品盈亏-基本保証金)
			double Available = DOUBLE_DEFAULT;
			//期货结算准备金	
			double Balance = DOUBLE_DEFAULT;

			//SP
			//资产净值（=现金结余+商品盈亏）
			double NetAssetValue = DOUBLE_DEFAULT;
			//信贷限额
			double CreditLimit = DOUBLE_DEFAULT;
			//现金结余
			double CashBal = DOUBLE_DEFAULT;
			//基本保証金
			double IMargin = DOUBLE_DEFAULT;
			//維持保証金
			double MMargin = DOUBLE_DEFAULT;
			//商品盈亏
			double CommodityPL = DOUBLE_DEFAULT;

		};
	}
}
