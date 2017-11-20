type t;
external make : unit => t = "insert" [@@bs.module "squel"];

external into : string => t = "" [@@bs.send.pipe: t];
external set : string => 'a => t = "" [@@bs.send.pipe: t];

external toString : t => string = "" [@@bs.send];