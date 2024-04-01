open Stdio

let ones = [|""; "one"; "two"; "three"; "four"; "five"; "six"; "seven"; "eight"; "nine"|]
let teens = [| "ten"; "eleven"; "twelve"; "thirteen"; "fourteen"; "fifteen"; "sixteen"; "seventeen"; "eighteen"; "nineteen" |]
let tens = [|""; ""; "twenty"; "thirty"; "forty"; "fifty"; "sixty"; "seventy"; "eighty"; "ninety"|]

let rec length_of_number n =
  if n < 10 then String.length ones.(n)
  else if n < 20 then String.length teens.(n - 10)
  else if n < 100 then String.length tens.(n / 10) + length_of_number (n mod 10)
  else if n < 1000 then
    String.length ones.(n / 100) + String.length "hundred" +
    (if n mod 100 <> 0 then String.length "and" + length_of_number (n mod 100) else 0)
  else String.length "onethousand"

let total_length = List.fold_left (fun acc x -> acc + length_of_number x) 0 (List.init 1000 (fun x -> x + 1))

let () = printf "%d\n" total_length
