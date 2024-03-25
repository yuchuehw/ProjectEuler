open Stdio

(* Calculates the sum of even Fibonacci numbers less than [max] *)
let sum_even_fib max =
  let rec sum_even_fib_rec current_fib next_fib sum =
    if current_fib > max then sum
    else
      sum_even_fib_rec next_fib (current_fib + next_fib)
        (if current_fib mod 2 = 0 then sum + current_fib else sum)
  in
  sum_even_fib_rec 1 1 0

let () =
  let max_value = 4000000 in
  printf "Sum of even Fibonacci numbers under %d: %d\n" max_value (sum_even_fib max_value)
