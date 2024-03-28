open Stdio

let make_list_with_length_and_value length v =
  let rec aux cum =
    if List.length cum < length then aux (v::cum) else cum
  in aux []

let sum_of_primes_smaller_than n =
  let rec prime_sieves_and_sum l i sum= 
    if i > n then sum
    else if List.nth l i == false then prime_sieves_and_sum l (i+1) sum
    else prime_sieves_and_sum (List.mapi (fun j x -> if j>i && j mod i = 0 then false else x) l) (i+1) (sum+i)
  in prime_sieves_and_sum (false::false::(make_list_with_length_and_value (n-1) true)) 2 0

let () = 
  printf "the sum of prime smaller than 2000000 is %d\n" (sum_of_primes_smaller_than 2000000)
