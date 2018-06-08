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

#### 使用说明

Demo 下载后直接运行即可使用