open Stdio

let rec collatz n =
  if n = 1 then 1
  else 1 + if n mod 2 = 0 then collatz (n / 2) else collatz (3 * n + 1)

let max_pair limit =
  let rec loop n max_collatz max_n =
    let collatz_n = collatz n in
    if n > limit then max_n
    else if collatz_n > max_collatz then (loop (n + 1) collatz_n n)
    else (loop (n + 1) max_collatz max_n) in 
  loop (limit/2) 0 0

let () = 
  let limit = 1_000_000 in
  printf "%d\n" (max_pair limit)
