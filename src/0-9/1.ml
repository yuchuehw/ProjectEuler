open Stdio

(* Calculates the sum of numbers less than [max] that are divisible by 3 or 5 *)
let sum_of_multiples_3_5 max =
  let rec loop n acc =
    if n < max then
      loop (n + 1) (if n mod 3 = 0 || n mod 5 = 0 then n + acc else acc)
    else
      acc
  in
  loop 1 0
  
let () =
  printf "Sum of multiples of 3 or 5 less than 1000: %i\n" (sum_of_multiples_3_5 1000)
