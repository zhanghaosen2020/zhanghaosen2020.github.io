"""
如果要做出数据可视化效果，可以借助pyecharts模块来完成
简介了，pyecharts的内容，安装以及两个实用的网站

1、构建一个基础的折线图
2、使用全局配置项设置属性
"""
# 导包，导入Line功能构建折线图对象
from pyecharts.charts import Line
from pyecharts.options import TitleOpts,LegendOpts,ToolboxOpts,VisualMapOpts
# 创建一个折线图对象
line = Line()
# 给折线图对象添加x轴的数据
line.add_xaxis(["中国","美国","英国"])
# 给折线图对象添加y轴的数据
line.add_yaxis("GDP",[30,20,10])

# pyecharts 模块中的配置选项 1、全局配置  2、系列配置选项
# 全局配置
line.set_global_opts(
    title_opts=TitleOpts("GDP展示",pos_left="center",pos_bottom="1%"),
    legend_opts=LegendOpts(is_show=True),
    toolbox_opts=ToolboxOpts(is_show=True),
    visualmap_opts=VisualMapOpts(is_show=True)
)

# 通过render 方法，将代码生成为图像
line.render()



