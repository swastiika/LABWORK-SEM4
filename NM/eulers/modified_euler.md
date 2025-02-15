## Modified EULERS PSEUDO-CODE:

**Step 1**: Start

**Step 2**: Define function as f(x,y)

**Step 3**: define variables,x0,y0,xn,h,mean

**Step 4**: Input:
        Initial values of x and y
        final value of x
        step size h

**Step 5**: while(x0<xn):
        mean = (f(x0,y0) + f(x0+h,f(x0,y0 + h*f(x0,y0))))/2
        y0 = y0 + h*mean
        x0 = x0 + h

**Step 6**: print the value of y0

**Step 7**: End