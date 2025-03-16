"""
class 子类(父类):  # 单继承
    类的内容体

class 子类(父类1,父类2...)
    类的内容体
"""
# 演示演示单继承
class Phone:
    IMEI = None # 学列号
    producer = "ITCAST" # 厂商

    def call_by_4g(self):
        print("4g通话")

class Phone2023(Phone):
    face_id = "10001" #面部识别id

    def call_by_5g(self):
        print("2023新功能：5g通话")
phone = Phone2023()  # 别忘括号
print(phone.producer)
phone.call_by_4g()
phone.call_by_5g()

# 演示多继承
class NFCRreadr:
    nfc_type = "第五代"
    producer = "HM"

    def read_card(self):
        print("NFC读卡")

    def write_card(self):
        print("NFC写卡")

class RemotControl:
    rc_type = "红外遥控"
    def control(self):
        print("红外遥控开启了")

class MyPhone(Phone,NFCRreadr,RemotControl):
    pass # 用来补全语法，表示这里是空的
phone = MyPhone()
phone.call_by_4g()
phone.read_card()
phone.write_card()

# 多继承中对于同名的成员，调用时谁先引用，就显示谁，优先级就越高
print(phone.producer) # 结果为ITCAST