def hasSingleCycle(array):
    # Write your code here.
    visited = {}
    indi = 0
    count = 0
    while(count < len(array)):
        jump = array[indi] 
        #print(jump)
        if indi not in visited.keys():
            visited[indi] = 1
        
        indi += jump 
        while indi > len(array)-1:
            #wrap around front
            indi -= len(array)

        while indi < 0:
            indi += len(array)
        count+=1

    if len(visited.keys()) == len(array) and indi == 0:
        return True
    else:
        return False
