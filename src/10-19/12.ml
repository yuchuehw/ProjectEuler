let find_triangle_with_factors target =
  let factor_count n =
    let rec aux n_prime i current_factor total_factors = 
      if n_prime = 1 then total_factors * current_factor
      else if n_prime mod i = 0 then aux (n_prime / i) i (current_factor + 1) total_factors
      else aux n_prime (i + 1) 1 (current_factor * total_factors)
    in aux n 2 1 1
  in

  let triangular_number n =
    n * (n + 1) / 2
  in

  let rec find_triangle i =
    let num = triangular_number i in
    let count = factor_count num in
    if count > target then num else find_triangle (i + 1)
  in

  find_triangle 1

let () =
  let target = 500 in
  let result = find_triangle_with_factors target in
  Printf.printf "The first triangular number with more than %d factors is %d\n" target result
