open Stdio

let find_perfect_square n = 
  let rec aux i =
    if i * i > n then -1
    else if i * i = n then i
    else aux (i + 1)
  in
  aux 1

let find_triangle_with_perimeter perimeter =
  let rec aux_outer i =
    if i > perimeter then -1
    else
      let rec aux_inner j =
        if j > perimeter  then -1
        else
          let k = find_perfect_square (i * i + j * j) in
          if k > 0 && i + j + k = perimeter then i * j * k
          else if k > 0 then aux_inner (j + 1)
          else aux_inner (j + 1)
      in
      let result = aux_inner 1 in
      if result > 0 then result
      else aux_outer (i + 1)
  in
  aux_outer 1

let () = 
  printf "the product of the triangle with side a, b, c whose perimeter is 1000 is %d\n" (find_triangle_with_perimeter 1000)
