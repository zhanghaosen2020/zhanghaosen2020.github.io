import json
from pyecharts.charts import Map
from pyecharts.options import TitleOpts,VisualMapOpts
# 打开文件
f = open("C:/Users/Zhang/Desktop/资料/可视化案例数据/地图数据/疫情.txt","r",encoding="UTF-8")
# 读取文件内容
data  = f.read()
# 关闭文件夹
f.close()
# 将json文件转化为python字典
data_dict = json.loads(data)
# 获取济源市数据
cities_data = data_dict["areaTree"][0]["children"][3]["children"]
data_list = [] # 存入济源市数据
for city_daya in cities_data:
    city_name = city_daya["name"]+"市"
    city_confirm = city_daya["total"]["confirm"]
    data_list.append((city_name,city_confirm))
data_list.append(("济源市",5)) # 济源市的未被添加到框内，手动添加

map = Map() # 创建地图对象
map.add("河南疫情分布",data_list,"河南")
map.set_global_opts(
    title_opts=TitleOpts(title="河南疫情地图"),
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
map.render("河南省疫情地图.html")
