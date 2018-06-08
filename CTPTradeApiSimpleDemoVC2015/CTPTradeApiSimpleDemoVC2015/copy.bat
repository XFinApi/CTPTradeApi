xcopy ..\..\TradeApi_win32x86\Api\CTPTradeApi_v6.3.6_20160606 ..\Release\TradeApi_win32x86\Api\CTPTradeApi_v6.3.6_20160606 /I /E /Y
copy ..\..\TradeApi_win32x86\Cpp\XFinApi.ITradeApi.dll ..\Release\XFinApi.ITradeApi.dll /Y
copy ..\..\license.lic ..\Release\TradeApi_win32x86\Api\CTPTradeApi_v6.3.6_20160606\license.lic /Y

xcopy ..\..\TradeApi_win32x86\Api\CTPTradeApi_v6.3.6_20160606 ..\Debug\TradeApi_win32x86\Api\CTPTradeApi_v6.3.6_20160606 /I /E /Y
copy ..\..\TradeApi_win32x86\Cpp\XFinApi.ITradeApid.dll ..\Debug\XFinApi.ITradeApid.dll /Y
copy ..\..\license.lic ..\Debug\TradeApi_win32x86\Api\CTPTradeApi_v6.3.6_20160606\license.lic /Y

pause