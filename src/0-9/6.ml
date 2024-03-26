open Stdio

let sum_of_square_range start stop =
  let rec aux i cum =
    if i > stop then cum
    else aux (i + 1) (cum + (i * i))
  in
  aux start 0

let square_of_sum_range start stop =
  let rec aux i cum =
    if i > stop then cum * cum
    else aux (i + 1) (cum + i)
  in
  aux start 0

let () = 
  let result = square_of_sum_range 1 100 - sum_of_square_range 1 100 in
  printf "%d\n" result (* Output: 25164150 *)
