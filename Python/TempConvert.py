#TempConvert.py
TempStr=input("请输入温度值：")
if TempStr[-1] in ['F']:
    C=(eval(TempStr[0:-1])-32)/1.8
    print("转换后的温度是{:.2f}C".format(C))
elif TempStr[-1] in ['C']:
    F=1.8*eval(TempStr[0:-1])+32
    print("转换后的温度是{:.2f}F".format(F))
