## **PSEUDO CODE FOR SOLVING SECOND ORDER DIFFERENTIAL EQUATION USING RK4**

**Step 1**:Start

**Step 3**: define f(x)

**Step 4**: define g(x)

**Step 5** Declare variables x,y,z,a,b,c,k1,k2,k3,k4,l1,l2,l3,l4,xn,h

**Step 6**: Input 
      -Initial values of x,y,z
      -Final value of x
      -step size
**Step 7**: do
       k1 = h*g(x,y,z)
       l1 = h*f(x,y,z)

       k2 = h*g(x+h/2,y+k1/2,z+l1/2)
       l2 = h*f(x+h/2,y+k1/2,z+l1/2)


       k3 = h*g(x+h/2,y+k2/2,z+l2/2)
       l3 = h*f(x+h/2,y+k2/2,z+l2/2)

      k4 = h*g(x+h,y+k3,z+l3)
      l4 = h*f(x+h,y+k3,z+l3)
      x = x+h;
      y = y + (k1+2k2+2k3+k4)/6
      z = z + (l1+2l2+2l3+l4)/6

      while(x<xn);

**Step 8**: Print the values of y and z

**Step 9**: End

        

       

        