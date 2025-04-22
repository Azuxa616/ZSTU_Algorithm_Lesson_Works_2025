    #此题c++处理输入困难，故使用python
    
    height =input().split()
    height = [int(i) for i in height]
    count =len(height)
    visited= [0 for i in range(count)]
    res=0
    N=0
    while(N<count):
        last_height = -1
        for i in range(count):
            if(visited[i]==0):
                if(last_height==-1 or height[i]<=last_height):
                    visited[i]=1
                    last_height=height[i]
                    N+=1
        res+=1
            
        
    print(res)