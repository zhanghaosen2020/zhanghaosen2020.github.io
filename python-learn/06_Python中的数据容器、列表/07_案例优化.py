my_str = "万过薪月,员序程马黑来,nohtyp学"
# 法1，先翻转，再切片
reslut1 = my_str[::-1][9:14]
print(f"方法1：{reslut1}")

# 法2，先切片，后倒叙
reslut2 = my_str[5:10][::-1]
print(f"方法2：{reslut2}")

# 法3，先split分隔“,”,后replace替换“来”为“ ”，倒叙字符
reslut3 = my_str.split(",")[1].replace("来","")[::-1]
print(f"方法3：{reslut3}")
