
'''
    This is the code for the insertion sort algorithm
    This code will handle the execution time using the time.time() method in python and
    here use the random arrays (using the random()) as the input to the algorithm to sorting to
    ascending order
'''

import time
import random


random.seed()


#test cases enable what you want
# This will generate the 10000 length of numbers that are in range 1-1000000
mylist=[random.randint(1,100) for i in range (10)]
#mylist=sorted(mylist, key=int, reverse=True)   # input a descending order list
#mylist=sorted(mylist)  # input the ascending order list
print(mylist)
start=time.time()
# start the tim# print(mylist) print the list

def insertion_sort(mylist):

    length=len(mylist)
    #assuming the first emelent is already sorted
    for i in range (1,length):  
        #to chech the max ans shift each of them to get relevent position
        current=mylist[i]
        j=i     # to run the while loop
        while current<mylist[j-1] and j>0:
            mylist[j]=mylist[j-1]  # shifting
            j=j-1    # shifting back derection

        mylist[j]=current
                

insertion_sort(mylist)
end =time.time()
print("sorted")
print(mylist)

elapsedtime=end-start
print("time(ms) : %0.5f"% (1000*elapsedtime))
