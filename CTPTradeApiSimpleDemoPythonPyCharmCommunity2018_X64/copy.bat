xcopy ..\XTA_W64\Api\CTP_v6.3.6_20160606 XTA_W64\Api\CTP_v6.3.6_20160606 /I /E /Y
xcopy ..\XTA_W64\Api\CTP_v6.3.13_20181119 XTA_W64\Api\CTP_v6.3.13_20181119 /I /E /Y
xcopy ..\XTA_W64\Api\CTP_v6.3.15_20190220 XTA_W64\Api\CTP_v6.3.15_20190220 /I /E /Y
copy ..\XTA_W64\Python\XFinApi_TradeApi.py XFinApi_TradeApi.py /Y
copy ..\XTA_W64\Python\_XFinApi_TradeApi.cp36-win_amd64.pyd _XFinApi_TradeApi.cp36-win_amd64.pyd /Y

pause