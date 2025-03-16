"""
升值加薪

"""
information = {"王力宏":{"部门":"科技部","工资":3000,"级别":1},
               "周杰伦":{"部门":"市场部","工资":5000,"级别":2},
               "林俊杰":{"部门":"市场部","工资":7000,"级别":3},
               "张学友":{"部门":"科技部","工资":4000,"级别":1},
               "刘德华":{"部门":"市场部","工资":6000,"级别":2}}
print(f"当前员工的信息如下：{information}")
for name in information:
    level = information[name]["级别"]
    if level == 1:
        information[name]["级别"] = 2
        information[name]["工资"] += 1000
print(f"升值加薪后员工的信息如下：{information}")



