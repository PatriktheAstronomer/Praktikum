import matplotlib.pyplot as plt
import csv
import numpy as np
#This code is my old code, which was made to different purpose than teachin. However, might be useful for someone.
if __name__ == "__main__":
    x = []
    y1 = []
    y2 = []
    y3 = []
    y4 = []
    y5 = []
    y6 = []
    y7 = []
    y8 = []
    medianY = []
    quantile25 = []
    quantile75 = []
    Months = ["Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"]
    i = 0
    file = csv.reader(open('rocni-chody-AL.csv','r'))
    next(file)
    for row in file:
        y1.append(float(row[0]))
        x.append(i)
        i += 1
    plt.plot(x,y1,linestyle = ":", color = "k")
    
    file = csv.reader(open('rocni-chody-BI.csv','r'))
    next(file)
    for row in file:
        y2.append(float(row[0]))
    plt.plot(y2,linestyle = ":", color = "k")

    file = csv.reader(open('rocni-chody-EA.csv','r'))
    next(file)
    for row in file:
        y3.append(float(row[0]))
    plt.plot(y3,linestyle = ":", color = "k")

    file = csv.reader(open('rocni-chody-FR.csv','r'))
    next(file)
    for row in file:
        y4.append(float(row[0]))
    plt.plot(y4,linestyle = ":", color = "k")

    file = csv.reader(open('rocni-chody-IP.csv','r'))
    next(file)
    for row in file:
        y5.append(float(row[0]))
    plt.plot(y5,linestyle = ":", color = "k")

    file = csv.reader(open('rocni-chody-MD.csv','r'))
    next(file)
    for row in file:
        y6.append(float(row[0]))
    plt.plot(y6,linestyle = ":", color = "k")

    file = csv.reader(open('rocni-chody-ME.csv','r'))
    next(file)
    for row in file:
        y7.append(float(row[0]))
    plt.plot(y7,linestyle = ":", color = "k")

    file = csv.reader(open('rocni-chody-SC.csv','r'))
    next(file)
    for row in file:
        y8.append(float(row[0]))
    plt.plot(y8,linestyle = ":", color = "k")

    for j in range (0,12):
        medianY.append(np.quantile([y1[j], y2[j], y3[j], y4[j], y5[j], y6[j], y7[j], y8[j]], .50))
        quantile25.append(np.quantile([y1[j], y2[j], y3[j], y4[j], y5[j], y6[j], y7[j], y8[j]], .25))
        quantile75.append(np.quantile([y1[j], y2[j], y3[j], y4[j], y5[j], y6[j], y7[j], y8[j]], .75))

    plt.fill_between(x, quantile25, quantile75, color = "gray", label = "Q25-Q75")
    plt.plot(medianY, color = "r", label = "Median")

    plt.xlabel('Month')
    plt.xticks(range(len(Months)), Months)
    plt.ylabel('Temperature $\circ$C')
    plt.title('Annual cycle of temperatures')
    plt.legend()
    plt.show()
