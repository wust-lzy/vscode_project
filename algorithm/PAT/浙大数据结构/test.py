book = []
book.append(1)
sum = []
sum.append(1)
tem = 6
for i in range(25):
    book.append(tem)
    sum.append(tem+sum[i])
    tem = tem + 4
# for i in range(25):
#     print(sum[i])

cnt = 0
for i in range(25):
    if sum[i]
