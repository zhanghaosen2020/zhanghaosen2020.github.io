"""
混合类型的list[1,2,3,"sws","swsqw"],不好用上边的来做类型注解
所以用Union联合注解
"""
# 使用Union类型，必须先要导包
from typing import Union
my_list: list[Union[int,str]] = [1,2,3,"sws","swsqw"]

def func(data: Union[int,str])->Union[str,int]:
    pass
# 不仅可以在变量类型注解中可用，也可以在形参和返回值的类型注解中可用
func()