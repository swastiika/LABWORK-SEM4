## PSEUDO-CODE FOR INTEGRATION USING SIMPSON 1/3 RULE

**Step 1**: Start

**Step 2**: Define Function func(x);

**Step 3**: Input lower_limit, upper_limit, sub_interval

**Step 4**: Compute step_size = (upper_limit - lower_limit)/sub_interval;

**Step 5**: compute integration = func(lower_limit) + func(upper_limit);

**Step 6**: initialize i =1;

**Step 7**: Loop, while(i<=step_size-1)
         k = lowerlimit + i*step_size;
         if(i%2==0) then integration = integration + 2*func(k);
         else integration = integration + 4*func(k);

**Step 8**: integration = integration*h/3;

**Step 9**: Print integration

**Step 10**: End