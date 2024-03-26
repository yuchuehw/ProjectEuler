open Stdio

let isprime i =
  let rec aux j =
    if j * j > i then true
    else if i mod j = 0 then false
    else aux (j + 1)
  in
  if i < 2 then false
  else aux 2

let kth_prime k= 
  let rec find_prime i k_ =
    if k_ = k then i-1  (* Terminate when k_ equals k *)
    else if isprime i then find_prime (i+1) (k_+1)
    else find_prime (i+1) k_
  in find_prime 2 0  (* Start from 2 and prime count 0 *)

let () = 
  printf "%d\n" (kth_prime 10001)
