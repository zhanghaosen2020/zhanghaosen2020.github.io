my_str = "万过薪月,员序程马黑来,nohtyp学"
# 法1，先翻转，再切片
new_my_str = my_str[::-1] # 翻转字符串
print(f"{new_my_str}")
need_str = new_my_str[9:14]
print(f"{need_str}")

# 法2，split分隔“,”,用replace替换来为空倒叙字符串
new_my_str1 = my_str.split(",")
print(f"{new_my_str1}")
new_my_str2 = new_my_str1[1]
need_str1 = new_my_str2.replace("来"," ")
need_str2 = need_str1[::-1]
print(f"{need_str2}")

