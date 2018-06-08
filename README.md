# CTPTradeApi

#### 项目介绍
- TradeApi

​        标准统一、性能优异、易于扩展的金融交易、行情接口，程序或交易策略代码无需修改，即可在各交易所、期货公司、资管系统间平滑移植。 Api底层使用C++11保证性能优异，用户开发可以无差异的支持C++（11+）、C#（.Net Framework 2.0+、.Net Core 2.0+）、Java（8.0+）、Python（3.0+）等多种开发语言，支持Windows、Linux、Mac、Android、iOS等各种操作系统。

- QQ群：650920857
- CTPTradeApi是基于CTP v6.3.6的一个统一封装，可实现多语言的使用，简化开发过程。

#### 软件架构
- ITradeApi ： 统一接口，位于Cpp目录下，使用者可直接引用此目录的头文件和lib进行开发，CTPTradeApi.dll会动态加载到程序中，不进行依赖。
- CTPTradeApi 
  - thostmduserapi.dll           CTP行情dll
  - thosttraderapi.dll              CTP交易dll
  - XFinApi.CTPTradeApi.dll   release发布版本dll
  - XFinApi.CTPTradeApid.dll  debug开发版本dll

#### 支持交易接口

- CTP 上期所接口
- Feams 飞马接口
- Sgit 飞鼠郑商所接口
- XSpeed 大连飞创XSpeed柜台接口
- ZDCTP 直达CTP平台，外盘交易接口
- SHZD 直达交易接口
- ESITap 易盛9.0北斗星期货期权交易平台，外盘
- ESTap 易盛9.0启明星期货期权交易平台，内盘
- LTS  华宝LTS，股票交易接口
- SPNativeAPI   Sharp Point Limited 
- ksotp 金仕达
- UFX  恒生统一金融接口
- pbxgj 彭博信管家资管平台
- rohon 上海融航资管平台
- jn 上海金牛资管平台
- tdx 通达信软件

#### 使用说明

Demo 下载后直接运行即可使用