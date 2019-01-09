#pragma once

#include <string>

namespace XFinApi
{
	namespace TradeApi
	{
		// API 创建失败错误码
		enum XFinApiCreateError
		{
			// 无错误
			NoError = 0,
			// 头文件与接口版本不匹配
			ErrLoaderVersion = 1,
			// 头文件与实现版本不匹配
			ErrImplVersion = 2,
			// 实现加载失败
			ErrLoadFailed = 3,
			// 实现入口未找到
			ErrEntryNotFound = 4,
			// 创建实例失败
			ErrCreateFailed = 5,
			// 无授权文件
			ErrLicenseNotExist = 6,
			// 授权版本不符
			ErrVersion = 7,
			// 最后一次通信超限
			ErrLastAuthTime = 8,
			// 机器码错误
			ErrMid = 9,
			// 认证文件到期
			ErrExpiredTime = 10,
			// 认证超时
			ErrAuthTimeOut = 11,
		};

		// 事件 
		enum class ActionKind
		{
			// 底层返回
			LowerRet = 0,
			// 关闭
			Close = 1,
			// 连接
			Connect = 2,
			// 授权
			Authorize = 3,
			// 登录
			Login = 4,
			// 打开
			Open = 5,
			// 登出
			Logout = 6,
			// 断开
			Disconnect = 7,
			// 接口清理
			Release = 8,
			// 订阅
			Subscribe = 9,
			// 取消订阅
			UnSubscribe = 10,
			// 委托单动作
			OrderAction = 11,
			// 查询报单
			QueryOrder = 12,
			// 查询成交
			QueryTradeOrder = 13,
			// 查询合约
			QueryInstrument = 14,
			// 查询持仓
			QueryPosition = 15,
			// 查询账户
			QueryAccount = 16,
			// 查询保证金费率
			QueryInstrumentMarginRate = 17,
			// 查询手续费费率
			QueryInstrumentCommissionRate = 18,
		};

		// 事件结果
		enum class ResultKind
		{
			// 成功
			Success = 0,
			// 失败
			Failed = 1,
			// 未定义
			Undefined = 2,
		};

		// 代码
		namespace ErrorCodeKind
		{
#define DEFINE_CODE(_x) static const std::string _x = #_x

			// 未定义错误
			DEFINE_CODE(ErrUndefined);
			// 空回报
			DEFINE_CODE(ErrNullResponce);
			// API 初始化失败
			DEFINE_CODE(ErrApiCreateFailed);
			// API 版本不匹配
			DEFINE_CODE(ErrApiIncompatible);
			// 临时目录创建失败
			DEFINE_CODE(ErrCreateCacheDir);
			// 网络错误
			DEFINE_CODE(ErrNetwork);
			// 过多未处理的请求
			DEFINE_CODE(ErrTooManyUnhandledReqs);
			// 过多请求
			DEFINE_CODE(ErrTooManyRequests);
			// 接口未打开
			DEFINE_CODE(ErrNotOpened);
			// 接口已打开
			DEFINE_CODE(ErrAlreadyOpened);
			// 接口已关闭
			DEFINE_CODE(ErrAlreadyClosed);
			// 登录地址错误
			DEFINE_CODE(ErrLoginAddress);
			// 主机地址错误
			DEFINE_CODE(ErrHostAddress);
			// 查询地址错误
			DEFINE_CODE(ErrQueryAddress);
			// 经济公司错误
			DEFINE_CODE(ErrBrokerID);
			// 用户ID错误
			DEFINE_CODE(ErrUserID);
			// 密码错误
			DEFINE_CODE(ErrPassword);
			// 用户名或者密码错误
			DEFINE_CODE(ErrUserIDOrPassword);
			// 前置机端口
			DEFINE_CODE(ErrHostPort);
			// 登录机端口
			DEFINE_CODE(ErrLoginPort);
			// 认证错误
			DEFINE_CODE(ErrLicense);
			// Appid错误
			DEFINE_CODE(ErrAppID);
			// 参数错误
			DEFINE_CODE(ErrParams);
			// 合约ID错误
			DEFINE_CODE(ErrInstrumentID);
			// 交易所ID错误
			DEFINE_CODE(ErrExchangeID);
			// 品种ID错误
			DEFINE_CODE(ErrProductID);
			// 品种错误
			DEFINE_CODE(ErrProductType);
			// 价格错误
			DEFINE_CODE(ErrPrice);
			// 数量错误
			DEFINE_CODE(ErrVolume);
			// 方向错误
			DEFINE_CODE(ErrDirection);
			// 开平类型错误
			DEFINE_CODE(ErrOpenCloseType);
			// 价格条件错误
			DEFINE_CODE(ErrPriceCond);
			// 时间条件错误
			DEFINE_CODE(ErrTimeCond);
			// 数量条件错误
			DEFINE_CODE(ErrVolumeCond);
			// 套保类型错误
			DEFINE_CODE(ErrHedgeType);
			// 报单引用错误
			DEFINE_CODE(ErrOrderRef);
			// 报单ID错误
			DEFINE_CODE(ErrOrderID);
			// 前置ID错误
			DEFINE_CODE(ErrFrontID);
			// 会话ID错误
			DEFINE_CODE(ErrSessionID);
			// 委托类型错误
			DEFINE_CODE(ErrOrderType);
			// 动作类型错误
			DEFINE_CODE(ErrActionType);
			// 报单状态错误
			DEFINE_CODE(ErrOrderStatus);
			// 报单未成数错误
			DEFINE_CODE(ErrNoTradedVolume);
			// 用户未登出
			DEFINE_CODE(ErrUserNotLogouted);
			// 释放异常
			DEFINE_CODE(ErrRelease);
			// 连接错误
			DEFINE_CODE(ErrConnect);
			// 连接失败
			DEFINE_CODE(ErrConnectFailed);
			// 登入时 UserID 不一致或此 UserID 未登入
			DEFINE_CODE(ErrUserNotLogged);
			// 获取数据不存在或空
			DEFINE_CODE(ErrDataEmpty);
			// DLL 异常
			DEFINE_CODE(ErrDllException);
			// 主动断开
			DEFINE_CODE(ErrCloseInitiative);
			// 被动断开
			DEFINE_CODE(ErrClosePassive);
			// 帐号已登录
			DEFINE_CODE(ErrProviderOnlyOneUser);
			// 每次登陆只允许调用一次
			DEFINE_CODE(ErrCallOneTimeOnly);
			// 资金账号不存在
			DEFINE_CODE(ErrAccount);
			// 下属资金账号不存在
			DEFINE_CODE(ErrSubAccount);
			// Socket Error
			DEFINE_CODE(ErrSocket);
			// WSARecvFrom Error
			DEFINE_CODE(ErrWSARecvFrom);
			// 资金账号状态异常
			DEFINE_CODE(ErrAccountStatus);
			// 合约状态异常
			DEFINE_CODE(ErrInstrumentStatus);
			// 在你登陆前，有其他用户使用该登陆代码登陆
			DEFINE_CODE(ErrLoggedInElsewhere);
			// 投资者代码错误
			DEFINE_CODE(ErrInvestorID);
			// 价格位数错误
			DEFINE_CODE(ErrPricePrecision);
			// licene文件错误
			DEFINE_CODE(ErrLicenseFile);
			// licene密码错误
			DEFINE_CODE(ErrLicensePwd);
			// 发送队列大小错误
			DEFINE_CODE(ErrSendQueueSize);
			// 获取打包器失败
			DEFINE_CODE(ErrNewPacker);
			// 获取解包器失败
			DEFINE_CODE(ErrNewUnPacker);
			// 缓存目录太长
			DEFINE_CODE(ErrCacheFolderTooLong);
			// 报单被交易所拒绝
			DEFINE_CODE(ErrExchangeRejectOrder);
			// 撤单失败,被交易所拒绝
			DEFINE_CODE(ErrExchangeRejectCancelOrder);
			// 开发代码/认证码错误
			DEFINE_CODE(ErrAuthCode);
			// 柜台号错误
			DEFINE_CODE(ErrOrderCounterNo);
			// 接口不支持
			DEFINE_CODE(ErrNotSupport);
#undef DEFINE_CODE
		}

		// 网络类型
		enum class NetworkKind
		{
			TCP = 0,
			UDP = 1
		};

		// 报单状态
		enum class OrderStatusKind
		{
			// 下单错误
			Error = 0,
			// 全成
			AllTraded = 1,
			// 部分成交
			PartTradedQueueing = 2,
			// 部分成交部分未挂单
			PartTradedNotQueueing = 3,
			// 未成已挂单
			NoTradeQueueing = 4,
			// 未成未挂单
			NoTradeNotQueueing = 5,
			// 待撤
			Canceling = 6,
			// 已撤
			Canceled = 7,
			// 未触发
			NotTouched = 8,
			// 已触发
			Touched = 9,
			// 已受理
			Accept = 10,
			// 未知
			Unknown = 11
		};

		//行权结果
		enum class ExecResultKind
		{
			// 没有执行
			NoExec = 0,
			// 已经取消
			Canceled = 1,
			// 执行成功
			OK = 2,
			// 期权持仓不够
			NoPosition = 3,
			// 资金不够
			NoDeposit = 4,
			// 会员不存在
			NoParticipant = 5,
			// 客户不存在
			NoClient = 6,
			// 合约不存在
			NoInstrument = 7,
			// 没有执行权限
			NoRight = 8,
			// 不合理的数量
			InvalidVolume = 9,
			// 没有足够的历史成交
			NoEnoughHistoryTrade = 10,
			// 未知
			Unknown = 11
		};

		// 交易方向
		enum class DirectionKind
		{
			// 买
			Buy = 0,
			// 卖
			Sell = 1
		};

		// 开平类型
		enum class OpenCloseKind
		{
			// 开仓
			Open = 0,
			// 平仓
			Close = 1,
			// 强平
			ForceClose = 2,
			// 平今
			CloseToday = 3,
			// 平昨
			CloseYesterday = 4,
			// 本地强平
			LocalForceClose = 5,
			// 强减
			ForceOff = 6,
			// 不分开平
			None = 7,
			//强平今
			ForceCloseToday = 8
		};

		// 价格条件
		enum class PriceConditionKind
		{
			// 任意价/市价
			AnyPrice = 0,
			// 限价
			LimitPrice = 1
		};

		// 时间条件
		enum class TimeConditionKind
		{
			// 立即成交，否则撤单
			IOC = 0,
			// 成交或取消
			FOK = 1,
			// 成交并取消
			FAK = 2,
			// 当日有效
			GFD = 3,
			// 本节有效
			GFS = 4,
			// 指定日期前有效
			GTD = 5,
			// 撤销前有效/永久有效
			GTC = 6,
			// 集合竞价有效
			GFA = 7
		};

		// 数量条件
		enum class VolumeConditionKind
		{
			// 任意量
			AnyVolume = 0,
			// 最小量
			MinVolume = 1,
			// 全部量
			CompleteVolume = 2
		};

		// 执行条件
		enum class ContingentCondKind
		{
			// 立即
			Immediately = 0
		};

		// 委托类型
		enum class OrderKind
		{
			// 标准单
			Order = 0,
			// 冰山单
			Iceberg = 1,
			// 影子单
			Ghost = 2,
			// 竞价单
			Auction = 3,
			// 未知
			UnKnown = 4
		};

		// 投机套保类型
		enum class HedgeKind
		{
			// 投机
			Speculation = 0,
			// 套利
			Arbitrage = 1,
			// 套保
			Hedge = 2,
			// 做市商
			MarketMaker = 3,
			// 所有值
			AllValue = 4
		};

		// 品种类型
		enum class ProductKind
		{
			// 期货
			Futures = 0,
			// 期权
			Options = 1,
			// 股票
			Stock = 2
		};

		// 动作
		enum class OrderActionKind
		{
			// 下单
			Insert = 0,
			// 改单
			Modify = 1,
			// 撤单
			Cancel = 2,
			// 激活
			Active = 3,
			// 挂起
			Suspend = 4
		};

		// 合约状态
		enum class InstrumentStatusKind
		{
			// 开盘前
			BeforeTrading = 0,
			// 非交易
			NoTrading = 1,
			// 连续交易
			Continous = 2,
			// 集合竞价报单
			AuctionOrdering = 3,
			// 集合竞价价格平衡
			AuctionBalance = 4,
			// 集合竞价撮合
			AuctionMatch = 5,
			// 休市
			Pause = 6,
			// 收盘
			Closed = 7,
			// 收盘集合竞价
			ClosingCallAuction = 8,
			// 波动性中断
			Fusing = 9,
			// 临时停牌
			Halt = 10,
			// 全天停牌
			HaltAllDay = 11,
			// 熔断(盘中集合竞价)
			FuseToCallAuction = 12,
			// 熔断(暂停交易至闭市)
			FuseToClose = 13,
			// 未知
			Unknown = 14
		};

		// 平仓方式，
		enum class CloseStyleTypeKind
		{
			// 先开先平
			Close = 0,
			// 先平今再平昨
			CloseToday = 1,
			// 先平昨再平今
			CloseYesteryDay = 2
		};

		// 保证金价格类型
		enum class UserRightTypeKind
		{
			// 昨结价
			PreSettlementPrice = 1,
			// 最新价
			LastPrice = 2,
			// 成交均价
			AveragePrice = 3,
			// 开仓价
			OpenPrice = 4,
		};
	}
}
