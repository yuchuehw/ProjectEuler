open Stdio

let is_palindrome n =
  let str_n = Int.to_string n in
  let len = String.length str_n in
  let rec check_palindrome i =
    if i >= len / 2 then true
    else if str_n.[i] <> str_n.[len - 1 - i] then false
    else check_palindrome (i + 1)
  in
  check_palindrome 0

let largest_palindrome_product min max =
  let rec outer_loop i answer =
    if i > max then answer
    else
      let rec inner_loop j answer =
        if j > max then answer
        else
          let product = i * j in
          let new_answer =
            if product > answer && is_palindrome product then product else answer
          in
          inner_loop (j + 1) new_answer
      in
      let answer = inner_loop min answer in
      outer_loop (i + 1) answer
  in
  outer_loop min (-1)

let () =
  let lower_bound = 100 in
  let upper_bound = 999 in
  printf "The biggest palindrome product in the range of [%d, %d] is %d\n"
    lower_bound upper_bound (largest_palindrome_product lower_bound upper_bound)
