type t;
external make : unit => t = "delete" [@@bs.module "squel"];

external from : string => t = "" [@@bs.send.pipe: t];

external where : string => t = "" [@@bs.send.pipe: t];
external whereEx : Expression.t => t = "where" [@@bs.send.pipe: t];

external toString : t => string = "" [@@bs.send];