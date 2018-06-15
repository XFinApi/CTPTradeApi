#pragma once

#include "XFinApiCommon.h"
#include "OpenParams.h"
#include "QueryParams.h"
#include "TradeListener.h"
#include "Order.h"

//////////////////////////////////////////////////////////////////////////
namespace XFinApi
{
namespace TradeApi
{
    // 交易接口
    class ITrade
    {
    public:
        virtual ~ITrade() {}

        // 启动交易接口
        virtual void Open(const OpenParams &params) = 0;
        // 关闭交易接口
        virtual void Close() = 0;

        // 委托单动作
        virtual void OrderAction(Order &order) = 0;

        // 查询委托单
        virtual void QueryOrder(const QueryParams &params) = 0;
        // 查询成交单
        virtual void QueryTradeOrder(const QueryParams &params) = 0;
        // 查询合约
        virtual void QueryInstrument(const QueryParams &params) = 0;
        // 查询持仓
        virtual void QueryPosition(const QueryParams &params) = 0;
        // 查询账户
        virtual void QueryAccount(const QueryParams &params) = 0;

        // 是否已启动
        virtual bool IsOpened() const = 0;
        // 设置事件监听器
        virtual void SetListener(TradeListener *listener) = 0;
        // 获得启动参数
        virtual const OpenParams& GetOpenParams() const = 0;

        // 获得版本字符串
        virtual const char* Version(int type = 0) const = 0;
    };
}
}

//////////////////////////////////////////////////////////////////////////
#if !defined(SWIG)

extern "C" XFINAPI XFinApi::TradeApi::ITrade* XFinApi_CreateTradeApi_Impl(const char *path, const char *ver, int *errCode);

// 加载交易模块
inline XFinApi::TradeApi::ITrade* XFinApi_CreateTradeApi(const char *path, int *errCode = nullptr)
{
    return XFinApi_CreateTradeApi_Impl(path, XFINAPI_ITRADEAPI_VERSION, errCode);
}

// 释放交易模块
extern "C" XFINAPI void XFinApi_ReleaseTradeApi(XFinApi::TradeApi::ITrade *ptr);

#else

XFinApi::TradeApi::ITrade* XFinApi_CreateTradeApi(const char *path, int *errCode);
void XFinApi_ReleaseTradeApi(XFinApi::TradeApi::ITrade *ptr);

#endif
