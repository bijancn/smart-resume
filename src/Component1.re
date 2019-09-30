/* You're familiar handleClick from ReactJS. This mandatorily takes the payload,
   then the `self` record, which contains state (none here), `handle`, `reduce`
   and other utilities */
let handleClick = _event => Js.log("clicked!");

let foo = {
  let maybeString = None;
  let maybeString2 = Some("foo");
  switch (maybeString2) {
  | None => print_endline("no string")
  | Some(x) => print_endline("string is here: " ++ x)
  };
  switch (maybeString) {
  | None => print_endline("no string")
  | Some(x) => print_endline("string is here: " ++ x)
  };
};

let bar: string = {
  Belt.Option.
    // let x = Belt.Option.map(maybeString2)(fun x -> x ++ x);
    // Belt.Option.map None (fun x -> x * x)
    (Some("foofoo")->map(a => a)->getExn);
};

/* `make` is the function that mandatorily takes `children` (if you want to use
   `JSX). `message` is a named argument, which simulates ReactJS props. Usage:

   `<Component1 message="hello" />`

   Which desugars to

   `React.createElement(
     Component1.make,
     Component1.makeProps(~message="hello", ())
   )` */
[@react.component]
let make = (~message) => {
  foo;
  print_endline(bar);
  <div onClick=handleClick> {ReasonReact.string(message)} </div>;
};