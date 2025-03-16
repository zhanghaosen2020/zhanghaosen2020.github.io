import json
from pyecharts.charts import Map
from pyecharts.options import TitleOpts,VisualMapOpts

f = open("C:/Users/Zhang/Desktop/资料/可视化案例数据/地图数据/疫情.txt","r",encoding="UTF-8")
data = f.read()
dict_data = json.loads(data)
cities_data = dict_data["areaTree"][0]["children"][12]["children"]
data_list = []
for city_data in cities_data:
    city_name = city_data["name"] + "市"
    city_confirm = city_data["total"]["confirm"]
    data_list.append((city_name,city_confirm))
map = Map()
map.add("四川省各市确诊疫情",data_list,"四川")
map.set_global_opts(
title_opts=TitleOpts(title="四川疫情地图"),
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
map.render("四川省疫情地图.html")
