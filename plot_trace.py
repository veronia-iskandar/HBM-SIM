import matplotlib.pyplot as plt
import numpy as np
import xlrd


book = xlrd.open_workbook('result.xls')
sheet = book.sheet_by_name('Sheet1')
data = [[sheet.cell_value(r, c) for c in range(sheet.ncols)] for r in range(sheet.nrows)]
# Profit !
print(data)

x = data[3]
y = data[2]

plt.scatter(x, y)
plt.show()
