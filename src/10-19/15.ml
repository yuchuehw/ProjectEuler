open Stdio

let lattice_path width height =
  let memo_table = Hashtbl.create (width * height) in
  let rec aux x y =
    if x = width && y = height then 1
    else if x > width || y > height then 0
    else
      match Hashtbl.find_opt memo_table (x, y) with
      | Some result -> result
      | None ->
          let result =
            aux x (y + 1) + aux (x + 1) y
          in
          Hashtbl.add memo_table (x, y) result;
          result
  in
  aux 0 0

let () =
  let width = 20 in
  let height = 20 in
  printf "%d\n" (lattice_path width height)
