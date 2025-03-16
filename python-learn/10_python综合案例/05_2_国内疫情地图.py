"""
演示全国疫情可视化地图开发
"""
import json
from pyecharts.charts import Map
from pyecharts.options import *
# 读取文件
f = open("C:/Users/Zhang/Desktop/资料/可视化案例数据/地图数据/疫情.txt","r",encoding="UTF-8")
data = f.read()
# 关闭文件
f.close()
# 取到各个省的数据
# 将字符串json转换为python的字典
data_dict = json.loads(data) # 基础字典数据
# 从字典中取出省分的数据
province_data_list = data_dict["areaTree"][0]["children"]
data_list =[] # 绘制地图时用的数据列表
# 组装每个省份和确诊人数为元组，并将各个省的数据封装到列表中
for province_data in province_data_list:
    province_name = province_data["name"]
    province_confirm = province_data["total"]["confirm"]
    data_list.append((province_name,province_confirm))
# 创建地图对象
map = Map()
# 添加数据
map.add("各省份确诊人数",data_list,"china")
# 全局选项
map.set_global_opts(
    title_opts=TitleOpts(title="全国疫情地图"),
    visualmap_opts=VisualMapOpts(
        is_show=True, # 是否显示
        is_piecewise=True, # 是否分段
        pieces=[
            {"min":1,"max":99,"label":"1-99","colore":"#ccffff"},
            {"min":100,"max":999,"label":"100-999","colore":"#ffff99"},
            {"min":1000,"max":4999,"label":"1000-4999","colore":"#ff9966"},
            {"min":5000,"max":9999,"label":"5000-9999","colore":"#ff6666"},
            {"min":10000,"max":99999,"label":"1000-99999","colore":"#cc3333"},
            {"min":100000,"label":"100000+","colore":"#990033"},
        ]

    )
)
# 生成图表
map.render("全国疫情地图.html")
