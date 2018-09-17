xcopy ..\XTA_W32\Api\CTP_v6.3.6_20160606 Release\XTA_W32\Api\CTP_v6.3.6_20160606 /I /E /Y
copy ..\XTA_W32\Cpp\XFinApi.ITradeApi.dll Release\XFinApi.ITradeApi.dll /Y

xcopy ..\XTA_W32\Api\CTP_v6.3.6_20160606 Debug\XTA_W32\Api\CTP_v6.3.6_20160606 /I /E /Y
copy ..\XTA_W32\Cpp\XFinApi.ITradeApid.dll Debug\XFinApi.ITradeApid.dll /Y

xcopy ..\XTA_W64\Api\CTP_v6.3.6_20160606 x64\Release\XTA_W64\Api\CTP_v6.3.6_20160606 /I /E /Y
copy ..\XTA_W64\Cpp\XFinApi.ITradeApi.dll x64\Release\XFinApi.ITradeApi.dll /Y

xcopy ..\XTA_W64\Api\CTP_v6.3.6_20160606 x64\Debug\XTA_W64\Api\CTP_v6.3.6_20160606 /I /E /Y
copy ..\XTA_W64\Cpp\XFinApi.ITradeApid.dll x64\Debug\XFinApi.ITradeApid.dll /Y

pause