## PSEUDO CODE FOR LINEAR CURVE FITTING

**Step 1**: Start

**Step 2**: Declare variables n,sumx,sumxx,sumy,sumyy,sumxy,a,b

**Step 3**: Read number of variables

**Step 4**: Read datas:
        For i=0 to n-1:
           Read x[i],y[i]
        End For
**Step 5**: Initialize: 
         sumx,sumxx,sumy,sumyy,sumxy=0

**Step 6**: find sum:
        For i=0; to n-1:
            sumx = sumx + x[i]
            sumy = sumy + y[i]
            sumxx = sumxx + x[i]*x[i]
            sumxy = sumxy + x[i]*y[i]
            sumyy = sumyy + y[i]*y[i]

**Step 7**: Calculate constant a and b of y = a + bx
          b = (n*sumxy - sumx*sumy)/(n*sumxx - sumx*sumx)
          a = (sumy - sumx*b)/n

**Step 8**: Print the value of a and b

**Step 9**: End