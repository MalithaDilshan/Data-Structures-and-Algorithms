
'''
This is the algorithm implementation of Quick sort using the python language. this is use the recursive method to split the array
date : 31/01/2017

'''

def quick_sort_array(Mylist,first,last):

    #check the condition thst should satisfied the array
    if first<last :

        breakpoint=break_array(Mylist,first,last)
        # call the array recursivly to sort the whole array
        quick_sort_array(Mylist,first,breakpoint-1)
        quick_sort_array(Mylist,breakpoint+1,last)


def break_array(Mylist,first,last):

    #find the position that should swap and use the pivot position as the first element of the array
    #here we can use a while loop to find the relevent number

    mypivot=Mylist[first]
    forward=first+1
    backword=last
    condition=True
    #while(forward>backword)
    #want to fid the crossing element to partition the array
    while condition:
        while Mylist[forward]<=mypivot  and forward<=backword:
            forward=forward+1

        while Mylist[backword]>=mypivot and forward<=backword:
            backword=backword-1

        #check the partition position and swapping
        if forward<=backword:
            #swapping the two elements
            tem=Mylist[forward]
            Mylist[forward]=Mylist[backword]
            Mylist[backword]=tem

        else:
            condition=False
    tem=mypivot
    Mylist[first]=Mylist[backword]
    Mylist[backword]=tem

    return backword     # return the breakpoint of the array to the calling function

# testcases 
#Mylist=[]
#Mylist=[4,4,4]
#Mylist=[0]
#Mylist=[1,2,3,4,5,6,7,8,9,10]

Mylist=[7,5,4,8,9,6,3,2,11,17,20,20,100,200]
#Mylist=[0,2]
print(Mylist)
print("sorted list:")
print()
length=len(Mylist)
first=0
last=length-1
quick_sort_array(Mylist,first,last)
print(Mylist)