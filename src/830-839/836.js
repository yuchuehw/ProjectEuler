// solution inspired by heyajulia (post #59)
[...document.getElementsByTagName("b")].map((el) => el.innerText).join(" ").split(" ").map(word => word.slice(0, 1)).join("")
