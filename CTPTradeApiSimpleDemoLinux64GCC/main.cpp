/*******************************************************
* CTPTradeApiSimpleDemoLinux64GCC
* www.xfinapi.com
*******************************************************/

#include <iostream>
#include <algorithm>
#include <thread>

#include "XFinApi.h"

//////////////////////////////////////////////////////////////////////////////////
//配置信息
class Config
{
public:
	//地址
	std::string MarketAddress;
	std::string TradeAddress;

	//账户
	std::string BrokerID;
	std::string UserName;
	std::string Password;

	//合约
	std::string InstrumentID;

	//行情
	double SellPrice1 = -1;
	double BuyPrice1 = -1;

	Config()
	{
		//注册CTP仿真交易账号，www.simnow.com.cn
		MarketAddress = "180.168.146.187:10010";
		TradeAddress = "180.168.146.187:10000";

		BrokerID = "9999";
		UserName = "119486";//公用测试账户。为了测试准确，请注册使用您自己的账户。
		Password = "a123456";

		InstrumentID = "IH1912";
	}

	void SetNonTradeTime()
	{
		//非交易时间
		//下午收盘后，或放假时间
		MarketAddress = "180.168.146.187:10031";
		TradeAddress = "180.168.146.187:10030";
	}
};

class ConfigSE
{
public:
	//地址
	std::string MarketAddress;
	std::string TradeAddress;

	//账户
	std::string BrokerID;
	std::string UserName;
	std::string Password;

	////合约
	//std::string InstrumentID;

	////行情
	//double SellPrice1 = -1;
	//double BuyPrice1 = -1;

	//看穿式监管认证信息
	std::string AppID;
	std::string AuthCode;

	ConfigSE()
	{
		//注册CTP仿真交易账号，www.simnow.com.cn
		MarketAddress = "";
		TradeAddress = "";

		BrokerID = "";
		UserName = "";
		Password = "";
		AppID = "";
		AuthCode = "";

		//InstrumentID = "IH1912";
	}
};

class MarketEvent;
class TradeEvent;

//////////////////////////////////////////////////////////////////////////////////
static Config Cfg;
static ConfigSE CfgSE;
static XFinApi::TradeApi::IMarket *market = nullptr;
static XFinApi::TradeApi::ITrade *trade = nullptr;
static MarketEvent *marketEvent = nullptr;
static TradeEvent *tradeEvent = nullptr;

//////////////////////////////////////////////////////////////////////////////////
//辅助方法
#define DEFAULT_FILTER(_x)  ( XFinApi::TradeApi::IsDefaultValue(_x) ? -1 : _x)

static void PrintNotifyInfo(const XFinApi::TradeApi::NotifyParams &param)
{
	std::string strs;
	for (const XFinApi::TradeApi::CodeInfo &info : param.CodeInfos)
	{
		strs += "(Code=" + info.Code +
			";LowerCode=" + info.LowerCode +
			";LowerMessage=" + info.LowerMessage + ")";
	}
	printf(" OnNotify: Action=%d, Result=%d%s\n",
		param.ActionType,
		param.ResultType,
		strs.c_str());
}

static void PrintSubscribedInfo(const XFinApi::TradeApi::QueryParams &instInfo)
{
	printf("- OnSubscribed: %s\n", instInfo.InstrumentID.c_str());
}

static void PrintUnsubscribedInfo(const XFinApi::TradeApi::QueryParams &instInfo)
{
	printf("- OnUnsubscribed: %s\n", instInfo.InstrumentID.c_str());
}

static void PrintTickInfo(const XFinApi::TradeApi::Tick &tick)
{
	printf("  Tick,%s %s, HighestPrice=%g, LowestPrice=%g, BidPrice0=%g, BidVolume0=%ld, AskPrice0=%g, AskVolume0=%ld, LastPrice=%g, LastVolume=%ld, TradingDay=%s, TradingTime=%s\n",
		tick.ExchangeID.c_str(),
		tick.InstrumentID.c_str(),
		tick.HighestPrice,
		tick.LowestPrice,
		tick.BidPrice[0],
		tick.BidVolume[0],
		tick.AskPrice[0],
		tick.AskVolume[0],
		tick.LastPrice,
		tick.LastVolume,
		tick.TradingDay.c_str(),
		tick.TradingTime.c_str());
}

static void  PrintOrderInfo(const XFinApi::TradeApi::Order &order)
{
	printf("  ProductType=%d, Ref=%s, ID=%s, InstID=%s, Price=%g, Volume=%ld, NoTradedVolume=%ld, Direction=%d, OpenCloseType=%d, PriceCond=%d, TimeCond=%d, VolumeCond=%d, Status=%d, Msg=%s, %s, FrontID=%ld, SessionID=%ld\n",
		(int)order.ProductType,
		order.OrderRef.c_str(), order.OrderID.c_str(),
		order.InstrumentID.c_str(), order.Price, order.Volume, order.NoTradedVolume,
		(int)order.Direction, (int)order.OpenCloseType,
		(int)order.PriceCond,
		(int)order.TimeCond,
		(int)order.VolumeCond,
		(int)order.Status,
		order.StatusMsg.c_str(),
		order.OrderTime.c_str(),
		order.FrontID,
		order.SessionID
	);
}

static void  PrintTradeInfo(const XFinApi::TradeApi::TradeOrder &trade)
{
	printf("  ID=%s, OrderID=%s, InstID=%s, Price=%g, Volume=%ld, Direction=%d, OpenCloseType=%d, %s\n",
		trade.TradeID.c_str(), trade.OrderID.c_str(),
		trade.InstrumentID.c_str(), trade.Price, trade.Volume,
		(int)trade.Direction, (int)trade.OpenCloseType,
		trade.TradeTime.c_str());
}

static void  PrintInstrumentInfo(const XFinApi::TradeApi::Instrument &inst)
{
	printf(" ExchangeID=%s, ProductID=%s, ID=%s, Name=%s\n",
		inst.ExchangeID.c_str(), inst.ProductID.c_str(),
		inst.InstrumentID.c_str(), inst.InstrumentName.c_str());
}

static void  PrintPositionInfo(const XFinApi::TradeApi::Position &pos)
{
	printf("  InstID=%s, Direction=%d, Price=%g, PosToday=%ld, PosYesterday=%ld, BuyPosition=%ld, SellPosition=%ld\n",
		pos.InstrumentID.c_str(), (int)pos.Direction,
		DEFAULT_FILTER(pos.PreSettlementPrice),
		DEFAULT_FILTER(pos.PositionToday), DEFAULT_FILTER(pos.PositionYesterday),
		DEFAULT_FILTER(pos.BuyPosition), DEFAULT_FILTER(pos.SellPosition));
}

static void  PrintAccountInfo(const XFinApi::TradeApi::Account &acc)
{
	printf("  PreBalance=%g, PreCredit=%g, PreMortgage=%g, Mortgage=%g, Withdraw=%g, Deposit=%g, DeliveryMargin=%g\n",
		DEFAULT_FILTER(acc.PreBalance), DEFAULT_FILTER(acc.PreCredit), DEFAULT_FILTER(acc.PreMortgage), DEFAULT_FILTER(acc.Mortgage),
		DEFAULT_FILTER(acc.Withdraw), DEFAULT_FILTER(acc.Deposit), DEFAULT_FILTER(acc.DeliveryMargin));
}

static bool TimeIsSmaller(const std::string &lhs, const std::string &rhs)
{
	int h1, m1, s1, h2, m2, s2;
	sscanf(lhs.c_str(), "%d:%d:%d", &h1, &m1, &s1);
	sscanf(rhs.c_str(), "%d:%d:%d", &h2, &m2, &s2);

	if (h1 == h2)
	{
		if (m1 == m2)
			return s1 < s2;

		return m1 < m2;
	}
	return h1 < h2;
}

//////////////////////////////////////////////////////////////////////////////////
//API 创建失败错误码的含义，其他错误码的含义参见XTA_W32\Cpp\ApiEnum.h文件
static const char *StrCreateErrors[] = {
	"无错误",
	"头文件与接口版本不匹配",
	"头文件与实现版本不匹配",
	"实现加载失败",
	"实现入口未找到",
	"创建实例失败",
	"无授权文件",
	"授权版本不符",
	"最后一次通信超限",
	"机器码错误",
	"认证文件到期",
	"认证超时"
};

//////////////////////////////////////////////////////////////////////////////////
//行情事件
class MarketEvent : public XFinApi::TradeApi::MarketListener
{
public:
	MarketEvent() {}
	~MarketEvent() {}

	void OnNotify(const XFinApi::TradeApi::NotifyParams & notifyParams) override
	{
		printf("* Market");
		PrintNotifyInfo(notifyParams);

		//连接成功后可订阅合约
		if ((int)XFinApi::TradeApi::ActionKind::Open == notifyParams.ActionType &&
			(int)XFinApi::TradeApi::ResultKind::Success == notifyParams.ResultType && market)
		{
			//订阅
			XFinApi::TradeApi::QueryParams param;
			param.InstrumentID = Cfg.InstrumentID;
			market->Subscribe(param);
		}

		//ToDo ...
	}

	void OnSubscribed(const XFinApi::TradeApi::QueryParams &instInfo) override
	{
		PrintSubscribedInfo(instInfo);

		//ToDo ...
	}

	void OnUnsubscribed(const XFinApi::TradeApi::QueryParams &instInfo) override
	{
		PrintUnsubscribedInfo(instInfo);

		//ToDo ...
	}

	void OnTick(const XFinApi::TradeApi::Tick &tick) override
	{
		if (Cfg.SellPrice1 <= 0 && Cfg.BuyPrice1 <= 0)
			PrintTickInfo(tick);

		Cfg.SellPrice1 = tick.AskPrice[0];
		Cfg.BuyPrice1 = tick.BidPrice[0];

		//ToDo ...
	}
};

//////////////////////////////////////////////////////////////////////////////////
//交易事件
class TradeEvent : public XFinApi::TradeApi::TradeListener
{
public:
	TradeEvent() {}
	~TradeEvent() {}

	void OnNotify(const XFinApi::TradeApi::NotifyParams &notifyParams) override
	{
		printf("* Trade");
		PrintNotifyInfo(notifyParams);

		//ToDo ...
	}

	void OnUpdateOrder(const XFinApi::TradeApi::Order &order) override
	{
		printf("- OnUpdateOrder:\n");
		PrintOrderInfo(order);

		//ToDo ...
	}

	void OnUpdateTradeOrder(const XFinApi::TradeApi::TradeOrder &trade) override
	{
		printf("- OnUpdateTradeOrder:\n");
		PrintTradeInfo(trade);

		//ToDo ...
	}

	void OnQueryOrder(const std::vector<XFinApi::TradeApi::Order> &orders) override
	{
		printf("- OnQueryOrder:\n");

		std::vector<XFinApi::TradeApi::Order> sortedOrders = orders;
		std::sort(sortedOrders.begin(), sortedOrders.end(), [this](const XFinApi::TradeApi::Order &lhs, const XFinApi::TradeApi::Order &rhs)
		{
			return TimeIsSmaller(lhs.OrderTime, rhs.OrderTime);
		});

		for (const XFinApi::TradeApi::Order &order : sortedOrders)
		{
			PrintOrderInfo(order);

			//ToDo ...
		}
	}

	void OnQueryTradeOrder(const std::vector<XFinApi::TradeApi::TradeOrder> &trades) override
	{
		printf("- OnQueryTradeOrder:\n");

		std::vector<XFinApi::TradeApi::TradeOrder> sortedTradeOrders = trades;
		std::sort(sortedTradeOrders.begin(), sortedTradeOrders.end(), [this](const XFinApi::TradeApi::TradeOrder &lhs, const XFinApi::TradeApi::TradeOrder &rhs)
		{
			return TimeIsSmaller(lhs.TradeTime, rhs.TradeTime);
		});

		for (const XFinApi::TradeApi::TradeOrder &trade : sortedTradeOrders)
		{
			PrintTradeInfo(trade);

			//ToDo ...
		}
	}

	void OnQueryInstrument(const std::vector<XFinApi::TradeApi::Instrument> &insts) override
	{
		printf("- OnQueryInstrument:\n");

		for (const XFinApi::TradeApi::Instrument &inst : insts)
		{
			PrintInstrumentInfo(inst);

			//ToDo ...
		}
	}

	void OnQueryPosition(const std::vector<XFinApi::TradeApi::Position> &posInfos) override
	{
		printf("- OnQueryPosition\n");
		for (const XFinApi::TradeApi::Position &pos : posInfos)
			PrintPositionInfo(pos);

		//ToDo ...
	}

	void OnQueryAccount(const XFinApi::TradeApi::Account &accInfo) override
	{
		printf("- OnQueryAccount\n");
		PrintAccountInfo(accInfo);

		//ToDo ...
	}
};

//////////////////////////////////////////////////////////////////////////////////
//行情测试
static bool  CreateAndOpenMarket6()
{
    //创建 IMarket
	//const char* path 指 xxx.exe 同级子目录中的 xxx.so 文件
	int err = -1;

	market = XFinApi_CreateMarketApi("XTA_L64/Api/CTP_v6.3.6_20160606/XFinApi.CTPTradeApi.so", &err);

	if (err || !market)
	{
		printf("* Market XFinApiCreateError=%s;\n", StrCreateErrors[err]);
		return false;
	}

	//注册事件
	marketEvent = new MarketEvent();
	market->SetListener(marketEvent);

	//连接服务器
	//Cfg.SetNonTradeTime();//非交易时段
	XFinApi::TradeApi::OpenParams openParams;
	openParams.HostAddress = Cfg.MarketAddress;
	openParams.BrokerID = Cfg.BrokerID;
	openParams.UserID = Cfg.UserName;
	openParams.Password = Cfg.Password;
	openParams.IsUTF8 = true;
	market->Open(openParams);
	
	return true;
}

static bool  CreateAndOpenMarket13()
{
    //创建 IMarket
	//const char* path 指 xxx.exe 同级子目录中的 xxx.so 文件
	int err = -1;

	market = XFinApi_CreateMarketApi("XTA_L64/Api/CTP_v6.3.13_20181119/XFinApi.CTPTradeApi13.so", &err);

	if (err || !market)
	{
		printf("* Market XFinApiCreateError=%s;\n", StrCreateErrors[err]);
		return false;
	}

	//注册事件
	marketEvent = new MarketEvent();
	market->SetListener(marketEvent);

	//连接服务器
	XFinApi::TradeApi::OpenParams openParams;
	openParams.HostAddress = CfgSE.MarketAddress;
	openParams.BrokerID = CfgSE.BrokerID;
	openParams.UserID = CfgSE.UserName;
	openParams.Password = CfgSE.Password;
	openParams.IsUTF8 = true;
	market->Open(openParams);
	
	return true;
}

static bool  CreateAndOpenMarket15()
{
    //创建 IMarket
	//const char* path 指 xxx.exe 同级子目录中的 xxx.so 文件
	int err = -1;

	market = XFinApi_CreateMarketApi("XTA_L64/Api/CTP_v6.3.15_20190220/XFinApi.CTPTradeApi15.so", &err);

	if (err || !market)
	{
		printf("* Market XFinApiCreateError=%s;\n", StrCreateErrors[err]);
		return false;
	}

	//注册事件
	marketEvent = new MarketEvent();
	market->SetListener(marketEvent);

	//连接服务器
	XFinApi::TradeApi::OpenParams openParams;
	openParams.HostAddress = CfgSE.MarketAddress;
	openParams.BrokerID = CfgSE.BrokerID;
	openParams.UserID = CfgSE.UserName;
	openParams.Password = CfgSE.Password;
	openParams.IsUTF8 = true;
	market->Open(openParams);
	
	return true;
}

void MarketTest()
{
	if (!CreateAndOpenMarket6()) //CTP_v6.3.6_20160606版本
        return;
    //if (!CreateAndOpenMarket13()) //CTP_v6.3.13_20181119版本
    //    return;
    //if (!CreateAndOpenMarket15()) //CTP_v6.3.15_20190220版本
    //    return;

	/*
	连接成功后才能执行订阅行情等操作，检测方法有两种：
	1、IMarket::IsOpened()=true
	2、MarketListener::OnNotify中
	(int)XFinApi::TradeApi::ActionKind::Open == notifyParams.ActionType &&
	(int)XFinApi::TradeApi::ResultKind::Success == notifyParams.ResultType
	*/

	/* 行情相关方法
	while (!market->IsOpened())
		std::this_thread::sleep_for(std::chrono::seconds(1));

	//订阅行情，已在MarketEvent::OnNotify中订阅
	XFinApi::TradeApi::QueryParams param;
	param.InstrumentID = Cfg.InstrumentID;
	market->Subscribe(param);

	//取消订阅行情
	market->Unsubscribe(param);
	*/
}

//////////////////////////////////////////////////////////////////////////////////
//交易测试
static bool CreateAndOpenTrade6()
{
    //创建 ITrade
	//const char* path 指 xxx.exe 同级子目录中的 xxx.so 文件
	int err = -1;

	trade = XFinApi_CreateTradeApi("XTA_L64/Api/CTP_v6.3.6_20160606/XFinApi.CTPTradeApi.so", &err);

	if (err || !trade)
	{
		printf("* Trade XFinApiCreateError=%s;\n", StrCreateErrors[err]);
		return false;
	}

	//注册事件
	tradeEvent = new TradeEvent;
	trade->SetListener(tradeEvent);

	//连接服务器
	//Cfg.SetNonTradeTime();//非交易时段
	XFinApi::TradeApi::OpenParams openParams;
	openParams.HostAddress = Cfg.TradeAddress;
	openParams.BrokerID = Cfg.BrokerID;
	openParams.UserID = Cfg.UserName;
	openParams.Password = Cfg.Password;
	openParams.IsUTF8 = true;
	trade->Open(openParams);
	
	return true;
}

static bool CreateAndOpenTrade13()
{
    //创建 ITrade
	//const char* path 指 xxx.exe 同级子目录中的 xxx.so 文件
	int err = -1;

	trade = XFinApi_CreateTradeApi("XTA_L64/Api/CTP_v6.3.13_20181119/XFinApi.CTPTradeApi13.so", &err);

	if (err || !trade)
	{
		printf("* Trade XFinApiCreateError=%s;\n", StrCreateErrors[err]);
		return false;
	}

	//注册事件
	tradeEvent = new TradeEvent;
	trade->SetListener(tradeEvent);

	//连接服务器
	XFinApi::TradeApi::OpenParams openParams;
	openParams.HostAddress = CfgSE.TradeAddress;
	openParams.BrokerID = CfgSE.BrokerID;
	openParams.UserID = CfgSE.UserName;
	openParams.Password = CfgSE.Password;
	openParams.Configs.insert(std::make_pair(std::string("AppID"), CfgSE.AppID));
	openParams.Configs.insert(std::make_pair(std::string("AuthCode"), CfgSE.AuthCode));
	openParams.IsUTF8 = true;
	trade->Open(openParams);
	
	return true;
}

static bool CreateAndOpenTrade15()
{
    //创建 ITrade
	//const char* path 指 xxx.exe 同级子目录中的 xxx.so 文件
	int err = -1;

	trade = XFinApi_CreateTradeApi("XTA_L64/Api/CTP_v6.3.15_20190220/XFinApi.CTPTradeApi15.so", &err);

	if (err || !trade)
	{
		printf("* Trade XFinApiCreateError=%s;\n", StrCreateErrors[err]);
		return false;
	}

	//注册事件
	tradeEvent = new TradeEvent;
	trade->SetListener(tradeEvent);

	//连接服务器
	XFinApi::TradeApi::OpenParams openParams;
	openParams.HostAddress = CfgSE.TradeAddress;
	openParams.BrokerID = CfgSE.BrokerID;
	openParams.UserID = CfgSE.UserName;
	openParams.Password = CfgSE.Password;
    openParams.Configs.insert(std::make_pair(std::string("AppID"), CfgSE.AppID));
	openParams.Configs.insert(std::make_pair(std::string("AuthCode"), CfgSE.AuthCode));
	openParams.IsUTF8 = true;
	trade->Open(openParams);
	
	return  true;
}

void TradeTest()
{
	if (!CreateAndOpenTrade6()) //CTP_v6.3.6_20160606版本
        return;
    //if (!CreateAndOpenTrade13()) //CTP_v6.3.13_20181119版本
    //    return;
    //if (!CreateAndOpenTrade15()) //CTP_v6.3.15_20190220版本
    //    return;

	/*
	//连接成功后才能执行查询、委托等操作，检测方法有两种：
	1、ITrade::IsOpened()=true
	2、TradeListener::OnNotify中
	(int)XFinApi::TradeApi::ActionKind::Open == notifyParams.ActionType &&
	(int)XFinApi::TradeApi::ResultKind::Success == notifyParams.ResultType
	*/
	while (!trade->IsOpened())
		std::this_thread::sleep_for(std::chrono::seconds(1));

	XFinApi::TradeApi::QueryParams qryParam;
	qryParam.InstrumentID = Cfg.InstrumentID;

	//查询委托单
	std::this_thread::sleep_for(std::chrono::seconds(1));//有些接口查询有间隔限制，如：CTP查询间隔为1秒
	std::cout << "Press any key to QueryOrder.\n";
	getchar();
	trade->QueryOrder(qryParam);

	//查询成交单
	std::this_thread::sleep_for(std::chrono::seconds(3));
	std::cout << "Press any key to QueryTradeOrder.\n";
	getchar();
	trade->QueryTradeOrder(qryParam);

	//查询合约
	std::this_thread::sleep_for(std::chrono::seconds(3));
	std::cout << "Press any key to QueryInstrument.\n";
	getchar();
	trade->QueryInstrument(qryParam);

	//查询持仓
	std::this_thread::sleep_for(std::chrono::seconds(3));
	std::cout << "Press any key to QueryPosition.\n";
	getchar();
	trade->QueryPosition(qryParam);

	//查询账户
	std::this_thread::sleep_for(std::chrono::seconds(1));
	std::cout << "Press any key to QueryAccount.\n";
	getchar();
	trade->QueryAccount(qryParam);

	//委托下单
	std::this_thread::sleep_for(std::chrono::seconds(1));
	std::cout << "Press any key to OrderAction.\n";
	getchar();
	XFinApi::TradeApi::Order order;
	order.InstrumentID = Cfg.InstrumentID;
	order.Price = Cfg.SellPrice1;
	order.Volume = 1;
	order.Direction = XFinApi::TradeApi::DirectionKind::Buy;
	order.OpenCloseType = XFinApi::TradeApi::OpenCloseKind::Open;

	//下单高级选项，可选择性设置
	order.ActionType = XFinApi::TradeApi::OrderActionKind::Insert;//下单
	order.OrderType = XFinApi::TradeApi::OrderKind::Order;//标准单
	order.PriceCond = XFinApi::TradeApi::PriceConditionKind::LimitPrice;//限价
	order.VolumeCond = XFinApi::TradeApi::VolumeConditionKind::AnyVolume;//任意数量
	order.TimeCond = XFinApi::TradeApi::TimeConditionKind::GFD;//当日有效
	order.ContingentCond = XFinApi::TradeApi::ContingentCondKind::Immediately;//立即
	order.HedgeType = XFinApi::TradeApi::HedgeKind::Speculation;//投机
	order.ExecResult = XFinApi::TradeApi::ExecResultKind::NoExec;//没有执行

	trade->OrderAction(order);
}

int main()
{
	#if defined(__unix__)
	system("sudo echo");
	#endif
	
	//可在Config类中修改用户名、密码、合约等信息

	MarketTest();
	TradeTest();

	std::this_thread::sleep_for(std::chrono::seconds(2));
	std::cout << "Press any key to close.\n";
	getchar();

	//关闭连接
	if (market)
	{
		market->Close();
		XFinApi_ReleaseMarketApi(market);//必须释放资源
	}
	if (trade)
	{
		trade->Close();
		XFinApi_ReleaseTradeApi(trade);//必须释放资源
	}
	//清理事件
	if (marketEvent)
	{
		delete marketEvent;
		marketEvent = nullptr;
	}
	if (tradeEvent)
	{
		delete tradeEvent;
		tradeEvent = nullptr;
	}

	std::this_thread::sleep_for(std::chrono::seconds(1));
	std::cout << "Closed.\n";
	getchar();

	return 0;
}
