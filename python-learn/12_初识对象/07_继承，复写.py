"""
复写：子类继承父类的成员属性和成员方法后如果对其不满意
     那么可以进行复写 即在子类中重新定义同名的属性或方法

"""
class Phone:
    IMEI = None # 手机的序列号
    producer = "ITHEIMA" # 生产厂家

    def call_by_5g(self):
        print("使用5g通话")

# 定义字类、复写父类成员
class MyPhone(Phone):
    producer = "我生产" # 复写父类的成员

    def call_by_5g(self):
        print("开启CPU单核模式，确保省电")
        # print("使用5g通话")   # 复写父类的成员
        # 1
        # print(f"父类的厂商是：{Phone.producer}")
        # Phone.call_by_5g(self)

        # 2
        print(f"父类的厂商是：{super().producer}")
        super().call_by_5g() # 直接调用父类的5g通话，不需要自己再实现一边了
        print("关闭单核模式")

phone = MyPhone() # 括号  创建对象时
print(phone.producer)
phone.call_by_5g()# 复写后的成员

# 调用父类同名成员，若直接用会调用子类的，我们想用父类原来的怎么办
# 在子类中调用父类

