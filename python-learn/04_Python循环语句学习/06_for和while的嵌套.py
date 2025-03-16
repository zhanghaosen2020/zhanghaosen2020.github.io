"""
for与while的嵌套
"""
i = 1
while i< 100:
    print("今天是向小美表白的第%d天"%i)
    for x in range(1,11):
        print(f"送给小美的第{x}枝玫瑰花")
    print("小美，我喜欢你")
    print("第%d天的表白结束,加油坚持！"%i)
    i += 1
print("第%d天，小美被我的诚心打动，表白成功"%i)