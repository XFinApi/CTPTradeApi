#pragma once

#include "XFinApiCommon.h"
#include "OpenParams.h"
#include "QueryParams.h"
#include "MarketListener.h"

//////////////////////////////////////////////////////////////////////////
namespace XFinApi
{
namespace TradeApi
{
    // 行情接口
    class IMarket
    {
    public:
        virtual ~IMarket() {}

        // 启动行情接口
        virtual void Open(const OpenParams &params) = 0;
        // 关闭行情接口
        virtual void Close() = 0;
        // 订阅合约
        virtual void Subscribe(const QueryParams &params) = 0;
        // 退订合约
        virtual void Unsubscribe(const QueryParams &params) = 0;

        // 是否已启动
        virtual bool IsOpened() const = 0;
        // 设置事件监听器
        virtual void SetListener(MarketListener *listener) = 0;
        // 获得启动参数
        virtual const OpenParams& GetOpenParams() const = 0;

        // 获得版本字符串
        virtual const char* Version(int type = 0) const = 0;
    };
}
}

//////////////////////////////////////////////////////////////////////////
#if !defined(SWIG)

extern "C" XFINAPI XFinApi::TradeApi::IMarket* XFinApi_CreateMarketApi_Impl(const char *path, const char *ver, int *errCode);

// 加载行情模块
inline XFinApi::TradeApi::IMarket* XFinApi_CreateMarketApi(const char *path, int *errCode = nullptr)
{
    return XFinApi_CreateMarketApi_Impl(path, XFINAPI_ITRADEAPI_VERSION, errCode);
}

// 释放行情模块
extern "C" XFINAPI void XFinApi_ReleaseMarketApi(XFinApi::TradeApi::IMarket *ptr);

#else

XFinApi::TradeApi::IMarket* XFinApi_CreateMarketApi(const char *path, int *errCode);
void XFinApi_ReleaseMarketApi(XFinApi::TradeApi::IMarket *ptr);

#endif
