# given two strings, return true if the strings can be made equal with only one edit operation, being either an insert, remove, or replace of a character

def oneEdit(stringOne, stringTwo):
    sizeone = len(stringOne)
    sizetwo = len(stringTwo)
    if sizeone == sizetwo:
        # if they equal eachother then the only plausible operation is replace
        differences = 0
        for i in range(sizeone): 
            if differences > 1: 
                return False
            if (stringOne[i] != stringTwo[i]):
                # they are not the same on this character so add a difference
                differences+=1
        return True
            
    char = min(sizeone, sizetwo)
    for i in range(char):
        # loop through until you find a different character and if you do
        # try adding the different character and removing and if neither equal eachother
        # then its not possible  
        if stringOne[i] != stringTwo[i]:
            if len(stringOne) > len(stringTwo):
                stringOne = stringOne[:i] + stringOne[i+1:]
            else:
                stringTwo = stringTwo[:i] + stringTwo[i+1:]
                    
            if stringOne == stringTwo:
                return True
            else:
                return False
            
    return True
