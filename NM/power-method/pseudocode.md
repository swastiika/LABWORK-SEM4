## PSEUDO-CODE - POWER METHOD

**Step 1**: Start

**Step 2**: Define and Read matrix `n`, `A[n][n]`, tolerance, `x[n]`;

**Step 3**: Initialize `lambda_new = 0`, `lambda_old = 0`, `maxIterations = 1000`, `temp[n]`;

**Step 4**: // Main iterations loop  
           **FOR** `iter = 1` **TO** `maxIterations` **DO**  
           
           - **Matrix-vector multiplication**  
             **FOR** `i = 0` **TO** `n-1` **DO**  
                 `temp[i] = 0`  
                 **FOR** `j = 0` **TO** `n-1` **DO**  
                     `temp[i] ← temp[i] + A[i,j] * x[j]`  
                 **END FOR**  
             **END FOR**  
             
           - **Find maximum absolute value**  
             `max_val = 0`  
             **FOR** `i = 0` **TO** `n-1` **DO**  
                 **IF** `|temp[i]| > max_val` **THEN**  
                     `max_val = |temp[i]|`  
                 **END IF**  
             **END FOR**  
             
           - **Normalize vector**  
             **FOR** `i ← 0` **TO** `n-1` **DO**  
                 `temp[i] = temp[i] / max_val`  
             **END FOR**  
             
           - `lambda_new = max_val`  
             
           - **Check convergence**  
             **IF** `|lambda_new - lambda_old| < tolerance` **THEN**  
                 **BREAK**  
             **END IF**  
             
           - `lambda_old ← lambda_new`  
             
           - **Update vector**  
             **FOR** `i ← 0` **TO** `n-1` **DO**  
                 `x[i] ← temp[i]`  
             **END FOR**  
           **END FOR**

**Step 5**: Print "Dominant eigenvalue", `lambda_new`

**Step 6**: Print "Eigenvector",  
        **FOR** `i = 0` **TO** `n-1`  
             Print `x[i]`

**Step 7**: End
