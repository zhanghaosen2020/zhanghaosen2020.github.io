string = "itheima is a brand of itcast"
count = 0
for x in string:
    if x == "a":
        count +=1
# print(f"itheima is a brand of itcast中一共有：{count}个字母a")
print(string + f"中一共有：{count}个字母a")