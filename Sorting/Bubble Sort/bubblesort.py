
'''
    This is the code for the bubble sort algorithm
    This code will handle the execution time using the time.time() method in python and
    here use the random arrays (using the random()) as the input to the algorithm to sorting to
    ascending order
'''

import time
import random


random.seed()


#test cases enable what you want
# This will generate the 10000 length of numbers that are in range 1-1000000
mylist=[random.randint(0,100000) for i in range (1000)]
#mylist=sorted(mylist, key=int, reverse=True)   # input a descending order list
#mylist=sorted(mylist)  # input the ascending order list
#mylist=[]
#print(mylist)

start=time.time()
# start the tim# print(mylist) print the list

def bubble_sort(mylist):
    length=len(mylist)
    for i in range (length-1,0,-1):  # reverse for loop to reduse the lenght one by one
        #to chech the max ans swaping each of them
        for j in range (0,i):               # 0 to n-2
            if mylist[j+1]<mylist[j]:
                #swapping posiiotns
                tem = mylist[j]
                #mylist[j+1]=tem
                mylist[j]=mylist[j+1]
                mylist[j+1]=tem

bubble_sort(mylist)
end =time.time()

elapsedtime=end-start
#print("sorted ")
#print(mylist)
print("time(ms) : %0.5f"% (1000*elapsedtime))
