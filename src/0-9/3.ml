open Stdio

(* Finds the largest prime factor of a given number *)
let largest_prime_factor number =
  let rec factor n i =
    if n = 1 then i 
    else if n mod i = 0 then factor (n / i) i
    else factor n (i + 1)
  in
  factor number 2

let () =
  let number_to_factor = 600851475143 in
  printf "The largest prime factor of %d is %d\n"
    number_to_factor (largest_prime_factor number_to_factor)
