import time
import random
from numba import cuda


@cuda.jit
def table(d_gpuTable, d_length, d_glength):
    index = cuda.grid(1)
    stride = cuda.gridsize(1)
    i = index
    for i in range(index,stride,d_length):
        if( i < index ):
            d_gpuTable[i] = i
        else:
            d_gpuTable[i] = -1

def rotation(t):
    sortedRotations = []
    for i in range(len(t)):
        rotation = t[i:] + t[:i] ## banana$ --> anana$b --> banana just moving this to the front
        sortedRotations.append(rotation)

    sortedRotations = sorted(sortedRotations)
    return sortedRotations

def bwt(t):
    '''computes the BWT(t), where t is a string'''
    bwtStr = ""

    sortedRotations = []
    sortedRotations = rotation(t)
    for i in sortedRotations:
        bwtStr += i[-1]
    return bwtStr

def ranksList(text):
    ranks_lst = []
    a = 0
    c = 0
    g = 0
    t = 0
    d = 0
    for i in range(len(text)):
        if text[i] == '$':
            d += 1
            ranks_lst.append((text[i], d))
        if text[i] == 'A':
            a += 1
            ranks_lst.append((text[i], a))
        if text[i] == 'C':
            c += 1
            ranks_lst.append((text[i], c))
        if text[i] == 'G':
            g += 1
            ranks_lst.append((text[i], g))
        if text[i] == 'T':
            t += 1
            ranks_lst.append((text[i], t))
            
    return ranks_lst
            

def helperList(t):
    temp = sorted(t)
    helperStr = ''.join(temp)
    helper_lst = []
    a = 0
    c = 0
    g = 0
    t = 0
    d = 0
    for i in range(len(helperStr)):
        if helperStr[i] == '$':
            d += 1
            helper_lst.append((helperStr[i], d))
        if helperStr[i] == 'A':
            a += 1
            helper_lst.append((helperStr[i], a))
        if helperStr[i] == 'C':
            c += 1
            helper_lst.append((helperStr[i], c))
        if helperStr[i] == 'G':
            g += 1
            helper_lst.append((helperStr[i], g))
        if helperStr[i] == 'T':
            t += 1
            helper_lst.append((helperStr[i], t))
            
    return helper_lst
    

def reverseBwt(t):
    '''computes the inverse of the BWT, where t is a string'''
    ranks_lst = ranksList(t)
    helper_lst = helperList(t)
    
    text = ""
    
    for i in range(len(t)):
        if i == 0:
            currSuff = helper_lst[i]
            index = ranks_lst.index(currSuff)
            text += helper_lst[index][0]
            currSuff = helper_lst[index]
        else:
            index = ranks_lst.index(currSuff)
            text += helper_lst[index][0]
            currSuff = helper_lst[index]
    return text

f = open("hw3_test3.txt", "r")         # open the file
text =(''.join(random.choice('CGTA') for _ in range(10000))+'$')##f.readline().strip()            # text is on the first line
print("Original Text = ",text)
start = time.time()
print("BWT of Text   = ",bwt(text))
end = time.time()
print("Reverse BWT   = ",reverseBwt(bwt(text)))
print("Time Elapsed during BWT sort + assembly = ",(end-start))
# print(reverseBwt(text))              # expected output TACATCACGT$
