
'''
This program will scan the text file that given with sorted formact like dictionary 
and match the given string with command line.

This code is written using the python (version 3.6),  run it using command line arguments as follows
******      py test.py text_file.txt aelp            
please use this formact to run the code.

Author : E/13/200
Date   : 2017-02-22      '''

import sys
import time


if len(sys.argv) !=3:
    # This will print the error massage when you use a different formact to give the command line argument
	print(" \n Error: There is an error with command line arguments.\n #.... Please follow correct fomact as in documentation")
	sys.exit(0)

expresion=sys.argv[2]
#print(expresion[0])

list=[]
count=0

# Here I use the with-as , it will close the file automatically and easy to iterate the file
with open(sys.argv[1]) as myfile:
    for line in myfile:
        line = line.strip()   # store the words without '\n' character
        list.insert(count,line)
        count+=1

#print(count)
print("\n\n**These are the words that filtered from the file:\n")
print("..................................................")

start=time.time();     # measure the run time of the algorithm only
i=0
selecct_items=0

while i<count:
    length=len(list[i])
    list_array=list[i]
    print_condition = 0
    for j in range(0,length):
        step_counter=0
        for k in range(0,len(expresion)):
            if list_array[j]!=expresion[k]:
                step_counter +=1
        # check whether is there any word that have any different characters in the words in file
        if step_counter==len(expresion):
            print_condition =1

    # check the conditions to print the relavent word
    if print_condition==0 and len(list[i])!=0:
        selecct_items +=1
        print(  list[i])

    i=i+1

end =time.time()
elapsedtime=end-start


print("..................................................")
print( "\n** Selected", selecct_items,"out of",count,"words.\n")
print("** time : %0.5f"% (1000*elapsedtime),"ms")













