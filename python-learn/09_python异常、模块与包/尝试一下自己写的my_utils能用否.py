"""
演示异常、模块、包的综合案例练习
"""
# 创建my_util 包，在内创建两个模块，并提相应的功能函数
import my_utils.str_util
from my_utils import file_util
print(my_utils.str_util.str_reverse("一帆风顺"))
print(my_utils.str_util.substr("itheima",0,3))

file_util.print_file_info("D:/bill.txt")
file_util.append_to_file("D:/bill.txt","hahaaha")
file_util.print_file_info("D:/bill.txt")