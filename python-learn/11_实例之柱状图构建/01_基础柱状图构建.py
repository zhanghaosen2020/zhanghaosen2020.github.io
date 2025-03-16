"""
基础柱状图
掌握构建一个基础的柱状图并能够反转X和Y轴
"""
from pyecharts.charts import Bar
from pyecharts.options import LabelOpts

# 构建柱状图对象
bar = Bar()

# 添加x轴数据
bar.add_xaxis(["中国","美国","英国"])

# 添加y轴数据
bar.add_yaxis("GDP",[30,20,10],label_opts=LabelOpts(position="right"
                                        ))  # 让x和 y反转后的数字到柱状图右边

# 反转x和y轴
bar.reversal_axis()

# 绘图
bar.render("base histogram.html")
