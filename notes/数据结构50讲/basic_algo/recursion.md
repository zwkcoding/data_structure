## Recursion
### Judge: Three Conditions:
  - The problem can be solved with solutions of sub-problems
  - The solving method is same among the problem and sub-problems
  - It exists Termination conditions  

### Steps: Two Key Steps:
  - write down the recursion formulas  
  `f(n) = f(n-1) + f(n-2`
  - find the termination conditions  
  try with smaller sub problems,e.g `f(1) = 1, f(2) = 2`

### Cons
  - Stack overflow because of too large depth
  - Duplicate Calculation  
  use table ` hasSolvedList` to store calculated solutions of sub-problem
  - large time and space Consumption  
  replace recursion with `while loops`, it's just a human-imitated recusion version.