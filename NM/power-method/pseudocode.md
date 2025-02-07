## PSEUDO-CODE-POWER METHOD
**Step 1**: Start
**Step 2**: Define and Read matrix  n,A[n][n], tolerance,x[n];
**Step 3**: Initialize lamba_new =0, lambda_old=0, maxIterations =1000,temp[n];
**Step 3**: //main iterations loop
           FOR iter ← 1 TO maxIterations DO
        // Matrix-vector multiplication
        FOR i ← 0 TO n-1 DO
            temp[i] ← 0
            FOR j ← 0 TO n-1 DO
                temp[i] ← temp[i] + A[i,j] * x[j]
            END FOR
        END FOR
        
        // Find maximum absolute value
        max_val ← 0
        FOR i ← 0 TO n-1 DO
            IF |temp[i]| > max_val THEN
                max_val ← |temp[i]|
            END IF
        END FOR
        
        // Normalize vector
        FOR i ← 0 TO n-1 DO
            temp[i] ← temp[i] / max_val
        END FOR
        
        lambda_new ← max_val
        
        // Check convergence
        IF |lambda_new - lambda_old| < tolerance THEN
            BREAK
        END IF
        
        lambda_old ← lambda_new
        
        // Update vector
        FOR i ← 0 TO n-1 DO
            x[i] ← temp[i]
        END FOR
    END FOR
**Step 4**: print"dominant vector",lambda_new;
**Step 5**: print"eigen vector",
        for i=0; to n-1:
             print x[i]
**Step 6**: End


