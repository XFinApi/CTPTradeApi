#pragma once

#include "XFinApiCommon.h"
#include "ApiEnum.h"

namespace XFinApi
{
namespace TradeApi
{
    // 开启参数
    struct OpenParams
    {
		virtual ~OpenParams() {};
        // 用户名
        std::string UserID;
        // 密码
        std::string Password;
        // 主机地址
        std::string HostAddress;
        // 经纪公司代码
        std::string BrokerID;
        // 网络类型
        NetworkKind NetworkType = NetworkKind::TCP;

        // 是否使用 UTF-8 编码字符串
        bool IsUTF8 = false;
        bool IsOutputLog = true;

        // 附加配置
        std::map<std::string, std::string> Configs;
    };
}
}
