import pandas as pd
import numpy as np
import datetime as dt

def task1_1():
    df = pd.read_excel("C:/Users/Zhang/Desktop/非洲通讯产品销售数据.xlsx")
    df = pd.DataFrame(df)
    df['日期'] = pd.to_datetime(df['日期'])
    df['年份'] = df['日期'].dt.year
    df['季度'] = df['日期'].dt.quarter

    year_annual = pd.pivot_table(df, index=['年份', '地区', '国家', '服务分类'], values=['销售额', '利润'],
                                 aggfunc='sum').reset_index()

    quarter_annual = pd.pivot_table(df, index=['年份', '季度', '地区', '国家', '服务分类'], values=['销售额', '利润'],
                                    aggfunc='sum').reset_index()
    print(year_annual)
    print(quarter_annual)
    year_annual.to_excel('各年度销售额与利润统计.xlsx', index=False)
    quarter_annual.to_excel('各季度销售额与利润统计.xlsx', index=False)


task1_1()


# def tongbi(data):
#     data['tongbi_shu'] = data.销售额.diff()
#     data['tongbi_shu1'] = data.利润.diff()
#     data.fillna(0, inplace=True)
#     data['销售额同比增长率'] = data['tongbi_shu'] / (data['销售额'] - data['tongbi_shu'])
#     data['利润同比增长率'] = data['tongbi_shu1'] / (data['利润'] - data['tongbi_shu1'])
#     return data
#
#
# # ，并计算各国、各服务分类销售额和利润的同比增长率。
# def task1_1_sub():
#     df = pd.read_excel('各季度销售额与利润统计.xlsx')
#     df1 = pd.read_excel('各年度销售额与利润统计.xlsx')
#     df1.drop(columns=['服务分类'], inplace=True)
#     df1 = df1.groupby(['年份', '国家']).agg({'销售额': 'sum', '利润': 'sum'}).reset_index()
#     df1 = df1.groupby(['国家']).apply(tongbi)
#     df1.to_excel('各国家同比增长率.xlsx', index=False)
#     df2 = df.groupby(['年份', '服务分类']).agg({'销售额': 'sum', '利润': 'sum'}).reset_index()
#     df2 = df.groupby(['服务分类']).apply(tongbi)
#     df2.to_excel('各服务分类同比增长率.xlsx', index=False)
#     print(df2)
#
#
# task1_1_sub()
#
#
# # 任务 1.2 统计各地区、国家有关服务分类销售额和利润数据。
# def task1_2():
#     df = pd.read_excel("C:/Users/Zhang/Desktop/非洲通讯产品销售数据.xlsx")
#     # print(df.head(200).to_string())
#     df1 = pd.pivot_table(df, index=['地区', '国家', '服务分类'], values=['销售额', '利润'], aggfunc=np.sum).reset_index()
#     print(df1.head(100).to_string())
#     df1.to_excel('各地区、国家、服务分类销售额和利润.xlsx', index=False)
#
# task1_2()
# def task1_3():
#     df = pd.read_excel("C:/Users/Zhang/Desktop/非洲通讯产品销售数据.xlsx", sheet_name=1)
#     # print(df)
#     df = pd.DataFrame(df)
#     # df = df.drop(["备注：本表格中“销售合同”为“已成交合同”。"])
#     # print(df.to_string())
#     df1 = df["销售合同"].groupby(df["销售经理"]).sum()
#     df1 = pd.DataFrame(df1).sort_values('销售经理', ascending=False).reset_index()
#     df2 = df["成交率"].groupby(df["销售经理"]).mean()
#     df2 = pd.DataFrame(df2).sort_values('销售经理', ascending=False).reset_index()
#     df3 = pd.merge(df1, df2, on="销售经理")
#     df3["成交率"] = df3["成交率"].apply(lambda x: format(x, '.2%'))
#     print(df3)
#     df3.to_excel("各销售经理的成交合同数和成交率.xlsx")
# task1_3()


