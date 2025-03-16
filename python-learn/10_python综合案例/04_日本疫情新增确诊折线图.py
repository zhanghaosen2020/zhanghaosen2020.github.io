"""
利用D盘的日本.txt文档，提取数据
"""
# 导入json包
import json
from pyecharts.charts import Line
from pyecharts.options import TitleOpts,LabelOpts,ToolboxOpts
# 只读模式打开日本文档
f_jp = open("D:/日本.txt","r",encoding="UTF-8")
# 读出全部数据
jp_data = f_jp.read()
# print(jp_data)
# 去除首尾的无关项
jp_data = jp_data.replace("jsonp_1629350871167_29498(","")
jp_data = jp_data[:-2]
# json转python字典格式
jp_dict = json.loads(jp_data)
# print(type(jp_dict))
# 取出来trend 的新增确诊
jp_trend_data= jp_dict["data"][0]["trend"]
# 从trend的data中取出日期作为x轴数据，取出新增确诊作为y轴数据
jp_x_data = jp_trend_data["updateDate"][:315]
jp_y_data = jp_trend_data["list"][3]["data"][:315]

# 绘制图像
# 创建一个折线图对象
line = Line()
# 为x轴,y轴添加数据
line.add_xaxis(jp_x_data)
line.add_yaxis("日本新增确诊人数",jp_y_data,label_opts=LabelOpts(is_show=False))
# 设置全局选项
line.set_global_opts(
    title_opts=TitleOpts(title="2020年度日本新增新冠人数折线图",pos_left="center",
                         pos_bottom="1%"),
    toolbox_opts=ToolboxOpts(is_show=True)

)
line.render("jp_newadd_data.html")
f_jp.close()








