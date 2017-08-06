
'''
    This is the all full code for take the time
    This code will handle the execution time using the time.time() method in python and
    here use the random arrays (using the random()) as the input to the algorithm to sorting to
    ascending order
'''

import time
import random


random.seed()


#test cases enable what you want
# This will generate the 10000 length of numbers that are in range 1-1000000
#mylist=[random.randint(5,5) for i in range (2)]    # you can change the number of elements here
#mylist=sorted(mylist, key=int, reverse=True)   # input a descending order list
#mylist=sorted(mylist)  # input the ascending order list
mylist=[]
#print(mylist)
mylist1=list(mylist)    # tempary variables
mylist2=list(mylist)

start=time.time()
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

print("Bubble sort")
print("time(ms) : %0.5f"% (1000*elapsedtime))
print()

mylist=mylist1
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

elapsedtime=end-start
print("Selection sort")
print("time(ms) : %0.5f"% (1000*elapsedtime))
print()

mylist=mylist2    # assign the variables
start=time.time()
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

elapsedtime=end-start
print("Insertion sort")
print("time(ms) : %0.5f"% (1000*elapsedtime))
print()