open Stdio

let rec pascal_helper acc = function
  | [] -> acc
  | [_] -> acc @ [1]  (* Base case: the last element of the row is always 1 *)
  | x :: (y :: _ as xs) ->
    pascal_helper (acc @ [x + y]) xs;;

let pascal_triangle_rows_greater_than_k rows k =
  
  let rec pascal row_index prev_row acc =
    if row_index > rows+1 then acc
    else pascal (row_index + 1) (pascal_helper [1] prev_row) (acc + (List.fold_left (fun acc x -> if x > k then acc + 1 else acc) 0 prev_row))
  in
  pascal 1 [1] 0

let () =
  printf "%d\n" (pascal_triangle_rows_greater_than_k 100 1_000_000)
