# 方法1：使用print直接输出类型信息
print(type("我丢了"))
print(type("1314"))
print(type("13.00"))
print(type(13.00))
print(type(13))
# 方法2：使用变量存储type()语句的结果
string_type=type("你好")
int_type=type(666)
float_type=type(666.00)
print(string_type,int_type,float_type)

# 方法3：使用type()语句，查看变量中存储的数据类型
name="你好"
name_type=type(name)
print(name_type)