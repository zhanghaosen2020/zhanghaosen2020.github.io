"""
GDP动态柱状图开发
"""
from pyecharts.charts import Bar,Timeline
from pyecharts.options import *
from pyecharts.globals import ThemeType
# 读取数据
f = open("C:/Users/Zhang/Desktop/资料/可视化案例数据/动态柱状图数据/1960-2019全球GDP数据.csv",
     "r",encoding="GB2312")  # 简体中文GB2312
data_lines = f.readlines()
f.close()
# 删除第一条对象 year等
data_lines.pop(0)
# 将数据转化为字典储存，格式为：
#{年份：[[国家,GDP],[国家,GDP],[国家,GDP],....[国家,GDP],年份：[国家,GDP],[国家,GDP],....]]]]}
data_dict = {}
for data_line in data_lines:
    # print(type(data_line)) str类型
    year = int(data_line.split(",")[0]) # 年份
    country = data_line.split(",")[1]   #国家
    gdp = float(data_line.split(",")[2]) # GDP数据
    # 如何判断字典里有没有指定的key
    """
    这里需要着重解释一下，我们在for循环外定义了一个空字典，所以当把gdp和country加入为year的
    Value值时，由于第一次循环内并没有1960这个年份数据，所以可能会报错KeyError，终止程序运行
    故这里用到了捕获异常的方式来解决第一个年份1960，1961，作为Key时，报错的问题18分 110个视频评论
    """
    try:
        data_dict[year].append([country,gdp])
    except KeyError:
        data_dict[year] = []
        data_dict[year].append([country,gdp])
# print(data_dict)

# 创建时间线对象
timeline = Timeline({"theme":ThemeType.LIGHT})
# 排序年份  字典对象的数据没有顺序 3.6之后的版本字典遍历就是有序的了
sorted_year_list = sorted(data_dict.keys())
# print(sorted_year_list)
for year in sorted_year_list:
    data_dict[year].sort(key=lambda element:element[1],reverse=True)
    # 取出本年份前8的国家
    year_data = data_dict[year][0:8]
    x_data = []
    y_data = []
    for country_gdp in year_data:
        x_data.append(country_gdp[0]) # x轴添加国家
        y_data.append(country_gdp[1] / 10**8 ) # y轴添加gdp
    #
    # 构建柱状图
    bar = Bar()
    x_data.reverse()
    y_data.reverse()
    bar.add_xaxis(x_data)
    bar.add_yaxis("GDP(亿)",y_data,label_opts=LabelOpts(position="right"))
    # 反转x和y轴
    bar.reversal_axis()
    # 设置每一年的图表的标题
    bar.set_global_opts(
        title_opts=TitleOpts(title=f"{year}年全球前8GDP数据")
    )
    timeline.add(bar,str(year))


# 设置时间线自动播放
timeline.add_schema(
    play_interval= 1000,
    is_timeline_show= True,
    is_auto_play= True,
    is_loop_play=False
)
# 绘图
timeline.render("1960-2019全球GDP前8国家.html")