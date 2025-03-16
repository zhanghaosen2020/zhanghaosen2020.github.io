"""
1、了解什么是模块
   那么模块它的英文呢，python模块（module），那么其实模块就是一个Python的代码文件，
   以.py结尾，在我们的模块，或者说在模块的这一份Python代码文件的内部，
   我们可以去定义函数定义类定义变量等等。 那所以模块啊，其实本质上来说就是一个Python文件
   里面提供了各种各样的类函数，或者说变量。

    Python中有很多各种不同的模块，每一个模块都可以帮助我们快速的实现一些功能，
    比如实现和时间相关的功能。可以使用Time模块，我们可以认为一个模块就是一个工具包，
    每一个工具包中。 都有各种不同的工具供我们进行实现各种不同的功能。

    模块就是一个python文件，里边有类、函数、变量等，我们可以拿过来用（导入模块去使用）
2、掌握导入python内置的模块
"""
# 使用import导入time模块使用sleep功能（函数）
import time # time里边的功能全部都可以使用
print("他好")
time.sleep(1) # 程序执行到此等待一段指定秒，然后继续下边的操作
# 通过.就可以使用模块内的全部功能（类、函数、变量）
print("我也好")

# from 模块名 import 功能名
from time import sleep
print("他好")
sleep(2)
print("我也好")

# 使用 * 导入time模块的全部功能
from time import * # * 表示全部的意思
print("他好")
sleep(2)
print("我也好")

# 使用as给特定功能加上别名
# import time as t
#
# print("他好")
# t.sleep(5)
# print("我也好")
from time import sleep as sl
print("他好")
sl(5) # sleep(5)
print("我也好")
# 注意事项：在开头导入模块