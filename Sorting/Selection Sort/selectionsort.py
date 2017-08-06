
'''
    This is the code for the selection sort algorithm
    This code will handle the execution time using the time.time() method in python and
    here use the random arrays (using the random()) as the input to the algorithm to sorting to
    ascending order
'''

import time
import random

random.seed()


#test cases enable what you want
# This will generate the 10000 length of numbers that are in range 1-1000000
mylist=[random.randint(1,1000000) for i in range (10000)]
#mylist=sorted(mylist, key=int, reverse=True)   # input a descending order list
#mylist=sorted(mylist)  # input the ascending order list
#mylist=[]
#print(mylist)

start=time.time()
# start the tim# print(mylist) print the list
def selection_sort(mylist):
    length = len(mylist)
    for i in range (length-1,0,-1):   # reverse for loop
        elementposition=0
        for j in range(1,i+1):    # to find the max element in each step
            if mylist[elementposition]<mylist[j]:
                elementposition=j

        # use the tmperory veriable to swaping
        tem=mylist[i]
        mylist[i]=mylist[elementposition]
        mylist[elementposition]=tem

    
selection_sort(mylist)
end =time.time()
print("sorted")
print(mylist)
print()

elapsedtime=end-start
print("time(ms) : %0.5f"% (1000*elapsedtime))
