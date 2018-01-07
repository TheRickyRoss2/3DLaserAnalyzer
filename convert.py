#!/usr/bin/python

with open("9pads_Ch2.csv", 'r') as f:
    o =  open("9Pads_Ch2.txt", 'w')
    x = 0
    y = 0
    for line in f:
        x = float(line.split(",")[3])
        y = float(line.split(",")[4])
        o.write(str(x)+"\n"+str(y)+"\n")
    o.close()

