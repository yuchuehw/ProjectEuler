open Stdio

let rec gcd a b =
  if b = 0 then a
  else gcd b (a mod b)

let lcm a b =
  if a = 0 || b = 0 then 0 (* Handle edge case where a or b is 0 *)
  else (a * b) / gcd a b

let lcm_of_range start stop =
  let rec lcm_of_range_helper current result =
    if current > stop then result
    else lcm_of_range_helper (current + 1) (lcm result current)
  in
  lcm_of_range_helper start 1

let () =
  printf "%d\n" (lcm_of_range 1 20) (* Output: 232792560 *)
