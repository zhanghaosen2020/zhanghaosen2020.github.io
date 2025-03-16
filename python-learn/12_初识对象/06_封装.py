"""
面向对象的编程有如下几个特点：封装、继承和多态
封装是指：将现实世界事物在类中描述为属性和方法，即为封装
私有成员变量和方法用  __开头定义

私有成员的实际意义：在类中提供仅供内部使用的属性和方法而不对外开放 （类对象无法使用）
"""
# 定义一个类，内含私有成员变量和方法
class Phone:

    __current_voltage = 0.5 #当前手机的运行电压以两个下划
                           # 线开头的变量，函数名，即为私有
    def __keep_single_core(self):
        print("让CPU以单核模式运行")

    def call_by_5g(self):
        if self.__current_voltage >= 1:
            print("5g同通话已开启")
        else:
            self.__keep_single_core()
            print("电量不足，无法使用5g通话，并已经设置为单核模式进行省电")
phone = Phone()
# phone.__keep_single_core() 私有成员方法不可以使用，程序会报错
# print(phone.__current_voltage) 和上边一样，不能直接使用
# 私有的东西用户无法直接使用,但是其内部的其他成员是可以使用的，私有的只能内部自己使用
phone.call_by_5g()