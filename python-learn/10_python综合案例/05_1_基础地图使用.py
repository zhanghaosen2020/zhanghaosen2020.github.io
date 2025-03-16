"""
演示地图可视化的基本使用
"""
from pyecharts.charts import Map
from pyecharts.options import VisualMapOpts

# 准备地图对象
map = Map()

# 准备数据 元组嵌入列表
data = [
    ("四川省",101),
    ("广东省",101),
    ("北京市",334),
    ("上海市",223),
    ("台湾省",323)
]

# 添加数据
map.add("测试地图", data, "china")

# 设置全局选项
map.set_global_opts(
    visualmap_opts=VisualMapOpts(is_show=True,is_piecewise=True,
    pieces=[
        {"min":1,"max":9,"label":"1-9","color":"#CCFFFF"},
        {"min":10,"max":99,"label":"10-00","color":"#ff6666"},
        {"min":100,"max":500,"label":"100-500","color":"#CC0900"}
    ]
                                 )


)
# 绘图
map.render("ChinaMap.html")