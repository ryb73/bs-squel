type t;
external make : unit => t = "update" [@@bs.module "squel"];

external table : string => t = "" [@@bs.send.pipe: t];
external set : string => 'a => t = "" [@@bs.send.pipe: t];

external where : string => t = "" [@@bs.send.pipe: t];
external whereEx : Expression.t => t = "where" [@@bs.send.pipe: t];

external toString : t => string = "" [@@bs.send];