"""
能够通过json模块对数据进行处理
"""
import json
from pyecharts.charts import Line
from pyecharts.options import TitleOpts,LabelOpts

# 处理数据
f_us = open("D:/美国.txt","r",encoding="UTF-8")
us_data = f_us.read()     # 读取美国的全部内容
f_jp = open("D:/日本.txt","r",encoding="UTF-8")
jp_data = f_jp.read()     # 读取日本的全部内容
f_in = open("D:/印度.txt","r",encoding="UTF-8")
in_data = f_in.read()     # 读取印度的全部内容

# 去掉不合JSON规范的开头
us_data = us_data.replace("jsonp_1629344292311_69436(","")
jp_data = jp_data.replace("jsonp_1629350871167_29498(","")
in_data = in_data.replace("jsonp_1629350745930_63180(","")

# 去掉不合JSON规范的结尾
us_data = us_data[:-2] # 如果用上边一样的方法去除 ); 可能会去除的有些多  所以采用切片的方法
jp_data = jp_data[:-2]
in_data = in_data[:-2]

# JSON转Python字典
us_dict = json.loads(us_data)
jp_dict = json.loads(jp_data)
in_dict = json.loads(in_data)
# print(type(us_dict))
# print(us_data)

# 尝试获取trend key
us_trend_data = us_dict['data'][0]['trend']
jp_trend_data = jp_dict['data'][0]['trend']
in_trend_data = in_dict['data'][0]['trend']
# print(type(us_trend_data))
# print(us_trend_data)

# 获取日期数据，用于x轴，取2020年 到314下标结束
us_x_data = us_trend_data['updateDate'][:314]
jp_x_data = jp_trend_data['updateDate'][:314]
in_x_data = in_trend_data['updateDate'][:314]
# print(x_data)

# 获取确诊数据，用于y轴，取2020年 到314下标结束
us_y_data = us_trend_data['list'][0]['data'][:314]
jp_y_data = jp_trend_data['list'][0]['data'][:314]
in_y_data = in_trend_data['list'][0]['data'][:314]
# print(y_data)

# 生成图表
line = Line() # 构建折线图对象

# 添加x轴数据
line.add_xaxis(us_x_data) # x轴是共用的，所以使用一个国家的数据即可
# line.add_xaxis(in_x_data)
# 添加y轴数据
line.add_yaxis("美国确诊人数",us_y_data,label_opts=LabelOpts(is_show=False))
line.add_yaxis("日本确诊人数",jp_y_data,label_opts=LabelOpts(is_show=True))
line.add_yaxis("印度确诊人数",in_y_data,label_opts=LabelOpts(is_show=False))

# 设置全局选项
line.set_global_opts(
    # 设置标题
    title_opts=TitleOpts(title="2020年美日印三国确诊人数对比折线图",pos_left="center"
                         ,pos_bottom="1%")

)

# 调用render 方法，生成图表
line.render()
# 关闭文件
f_us.close()
f_jp.close()
f_in.close()




