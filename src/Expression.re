type t;
external make : unit => t = "expr" [@@bs.module "squel"];

external and_ : string => t = "and" [@@bs.send.pipe: t];
external or_ : string => t = "or" [@@bs.send.pipe: t];