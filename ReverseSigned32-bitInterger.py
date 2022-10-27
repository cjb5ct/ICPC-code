class Solution:
    def reverse(self, x: int) -> int:
        
        def outofrange(n):
            if n < -2**31 or n > 2**31 - 1:
                return 0
            else: 
                return n
        
        
        if x == 0:
            return 0
        if x < 0:
            # negative so need to deal with negative sign
            s = str(x)
            rev = s[::-1]
            if rev[0] == "0":
                leading = ""
                i = 0
                while rev[i] == "0":
                    i+=1
                while i < len(rev)-1:
                    leading+= rev[i]
                    i+=1
                neg = "-" + leading
                ret = int(neg) 
                ret = outofrange(ret)
                return ret
            else:
                fins = ""
                for i in range(len(rev)-1):
                    fins += rev[i]
            
                final = "-" + fins
                ret = int(final)
                ret = outofrange(ret)
                return ret
            #print(fins)
        else:
            s = str(x)
            rev = s[::-1]
            if rev[0] == "0":
                leading = ""
                i = 0
                while rev[i] == "0":
                    i+=1
                while i < len(rev):
                    leading+= rev[i]
                    i+=1
                ret = int(leading) 
                ret = outofrange(ret)
                return ret
            else:
                ret = int(rev)
                ret = outofrange(ret)
                return ret
            #print(rev)
