'''
This is the implementation to the merge sort algorithm using python.this algorithm use the recursivly calling
method to split the array. therefore this algorithm will increase the performance of the sorting

date : 01/01/2017


'''


def array_sort(Mylist):
    # check whether the array greater than zero. therefor this algorithm will valid for the array that have two or more elements
    length=len(Mylist)
    if length>1:
        #find the midpoint to split the array , in python we can use the int() 
        midpoint = int(length/2)

        leftarray = Mylist[:midpoint]
        rightarray = Mylist[midpoint:]

        # recursivly call  the function again and again finally this end up with arrays with one elements (number of arrrays =length)
        array_sort(leftarray)
        array_sort(rightarray)
        #print(leftarray)
        #print(rightarray)
        
        
        (i,j,k)=(0,0,0)
        
        # check wheather their is one element and swap the element if following condition satisfied
        #if i < len(leftarray) and j < len(rightarray):
        leftlength=len(leftarray)
        rightlength=len(rightarray)

        while i < leftlength and j < rightlength:
            if leftarray[i] < rightarray[j]:         # make the ascending order
                Mylist[k]=leftarray[i]
                i=i+1
            else:
                Mylist[k]=rightarray[j]
                j=j+1
            k=k+1

        while i < leftlength:  #makes other bits
            Mylist[k]=leftarray[i]
            i=i+1
            k=k+1

        while j < rightlength:
            Mylist[k]=rightarray[j]
            j=j+1
            k=k+1 
   # print(Mylist)

# testcases 
#Mylist=[]
#Mylist=[4,4,4]
#Mylist=[0]
#Mylist=[1,2,3,4,5,6,7,8,9,10]
#Mylist=[0,0]                       
#Mylist=[0,2]    

Mylist = [54,26,93,17,77,31,44,55,20,100,100,0,0]
print(Mylist)
print("sorted array:")
print()
array_sort(Mylist)
print(Mylist)
