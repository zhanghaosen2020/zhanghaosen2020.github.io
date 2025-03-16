"""
演示自定义模块
"""
# 导入自定义模块使用
# import my_module
# my_module.test(11,2)
# from my_module import test
# test(111,2)

# 导入不同模块的同名功能 后边的会覆盖前边的，也可以注意哪一个变亮了，哪一个灰
# from my_module import test
# from my_module1 import test
# test(21,11)

# __main__ 变量:
from my_module import test

# __all__变量 ：如果一个模块文件中有‘ _all_’，使用‘from xxx import *’导入时，只能导入这个列表中的元素
from my_module1 import * # all只限制 *
test_a(9,8)
test_b(9,8)
