"""
背景：基于python模块，我们在编写代码时，导入许多外部代码来丰富功能
     但是，如果python的模块太多了，就可能造成一定的混乱，那么如何管理呢？
什么是python包：从物理上看，包就是一个文件夹，在该文件夹下包含了一个__init__.py文件
               该文件夹可以包含多个模块文件
               从逻辑上看，包的本质依然是模块

"""
# 创建一个包:1，根目录 2，新建，第四个选项 里面要有__init__.py,才算是一个包

# 导入自定义的包中的模块，并使用 三种导入方法
# import my_package.my_module1
# import my_package.my_module2
#
# my_package.my_module1.info_print1()
# my_package.my_module2.info_print2()

# from my_package import my_module1
# from my_package import my_module2
# my_module1.info_print1()
# my_module2.info_print2()

from my_package.my_module1 import info_print1
from my_package.my_module2 import info_print2
info_print1()
info_print2()

# 这里同样有__all__,只不过列表需要定义在包中的__init__.py中
from my_package import *
my_module1.info_print1()
# my_module2.info_print2()
