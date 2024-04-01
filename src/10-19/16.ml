open Printf

let () =

  let result = 2.0 ** 1000.0 in
  let str = sprintf "%f" result in

  let rec sum_digits i sum =
    if i >= String.length str || str.[i] = '.' then
      sum
    else
      let digit = int_of_char str.[i] - int_of_char '0' in
      sum_digits (i + 1) (sum + digit)
  in

  let sum = sum_digits 0 0 in

  printf "%d\n" sum
