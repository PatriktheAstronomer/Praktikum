import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
excel_file = "ktc-cmip5-rcp45-areas.xls"
data = pd.ExcelFile(excel_file)
climaSheets = []
for sheet in data.sheet_names:
    climaSheets.append(data.parse(sheet))

tablesCount = len(climaSheets)
columnsCount = len(climaSheets[0]) #works in case all sheets are the same
rowsCount = len(climaSheets[0][1]) #first column is undefined in our data sample
saveas = ".png"
x = []
for l in range (1,columnsCount):
    x.append(l)
#it is better to use funtions defined in pandas, but this is a training code to show you, how data matipulation works
for i in range (0,tablesCount): #not pretty effective, however we have to transpone the data matrix
    y = [] 
    for l in range(0,columnsCount):
        y.append([])
    for j in range (1,columnsCount):
        for k in range(0,rowsCount):
            y[j].append(climaSheets[i][j][k])
    median = []
    kvan10 = []
    kvan90 = []
    for m in range (1,columnsCount):
        median.append(np.quantile(y[m],.50)) #calculates predefined quantiles
        kvan10.append(np.quantile(y[m],.10))
        kvan90.append(np.quantile(y[m],.90))

    plt.plot(x, median, color = "r", label = "median")
    plt.fill_between(x, kvan10, kvan90, color = "gray", label = "Q10-Q90")
    plt.xlabel('30yr period, 2006-2035')
    plt.title(data.sheet_names[i])
    plt.ylabel('Type area (%)')
    plt.legend()
    name = data.sheet_names[i]+saveas
    plt.savefig(name, dpi = 600) #consumes some time. Saves pictures in folder, where you run the code.
    plt.show() # not necessary to work
