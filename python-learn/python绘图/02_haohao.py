import numpy as np

# 导入pandas库，简写为pd
import pandas as pd
import matplotlib.pyplot as plt
import matplotlib


font = {
    'family':'SimHei',
    'weight':'bold',
    'size':12
}
matplotlib.rc("font", **font)
matplotlib.rcParams['axes.unicode_minus']=False

# 读取表格,使用openpyxl引擎，获取表名为"SalesData"、"SalespersonData"的内容，使用 openpyxl 的一些优势是能够轻松地使用样式、条件格式等自定义电子表格
salesData = pd.read_excel("C:/Users/Zhang/Desktop/非洲通讯产品销售数据.xlsx",engine='openpyxl', sheet_name = "SalesData")
salespersonData = pd.read_excel("C:/Users/Zhang/Desktop/非洲通讯产品销售数据.xlsx",engine='openpyxl', sheet_name = "SalespersonData")
# 对第一张表进行处理
# info()函数用于打印DataFrame的简要摘要，显示有关DataFrame的信息，包括索引的数据类型dtype和列的数据类型dtype，非空值的数量和内存使用情况。
salesData.info() # 无缺失值
# Duplicated函数功能：查找并显示数据表中的重复值,.duplicated().sum()便是检查有多少个重复值
salesData.duplicated().sum()
salespersonData.info()
salespersonData.duplicated().sum()
# 先对日期列进行处理
# DataFrame.astype()当我们想将特定的列数据类型转换为另一种数据类型时，该函数非常方便。
year = salesData.loc[:, "日期"].astype("str").str.split("-", expand = True)[0]
# expand = True 这个参数直接将分裂后的结果转化成DataFrame
print(year)
year_data = salesData.loc[:, ["国家", "地区", "服务分类", "销售额", "利润"]]
year_data["年份"] = year
# print(year_data)
year_area_sale = year_data.groupby(["年份", "地区"])["销售额"].sum()
year_area_sale.to_csv("./year_area_sale.csv")
print(year_area_sale)
year_cou_sale = year_data.groupby(["年份", "国家"])["销售额"].sum()
year_cou_sale.to_csv("./year_cou_sale.csv")
print(year_cou_sale)
# 各年度各国的销售额的同比增长率
task1 = pd.read_csv("./year_cou_sale.csv")
print(task1)
temp = pd.merge(task1[task1.loc[:, "年份"] == 2017], task1[task1.loc[:, "年份"] == 2018], how="inner", left_on = "国家", right_on = "国家")
temp = pd.merge(temp, task1[task1.loc[:, "年份"] == 2019] ,how="inner", left_on = "国家", right_on = "国家")
temp = pd.merge(temp, task1[task1.loc[:, "年份"] == 2020] ,how="inner", left_on = "国家", right_on = "国家")
temp.drop(["年份_x", "年份_y"], axis = 1, inplace=True)
temp.columns = ["国家", "2017销售额", "2018销售额", "2019销售额", "2020销售额"]
temp
temp["2017-2018销售额同比增长率"] = (temp["2018销售额"] - temp["2017销售额"]) / temp["2017销售额"]
temp["2018-2019销售额同比增长率"] = (temp["2019销售额"] - temp["2018销售额"]) / temp["2018销售额"]
temp["2019-2020销售额同比增长率"] = (temp["2020销售额"] - temp["2019销售额"]) / temp["2019销售额"]
temp
temp.to_csv("./各年份各国家的销售额同比增长率.csv")
print(temp)
# 展示2020年年度销售额前3名的国家及其年增长率
three = temp.loc[:, ["国家", "2020销售额", "2019-2020销售额同比增长率"]].sort_values("2020销售额", ascending = False).head(3)
print(three)
year_cou_pro = year_data.groupby(["年份", "国家"])["利润"].sum()
year_cou_pro.to_csv("./year_cou_pro.csv")
print(year_cou_pro)