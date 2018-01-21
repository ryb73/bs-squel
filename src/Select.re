type t;
external make : unit => t = "select" [@@bs.module "squel"];

external _from : string => alias::string? => unit => t = "from" [@@bs.send.pipe: t];
let from ::alias=? table => _from table ::?alias ();

external field : string => t = "" [@@bs.send.pipe: t];
external group : string => t = "" [@@bs.send.pipe: t];

external where : string => t = "" [@@bs.send.pipe: t];
external whereEx : Expression.t => t = "where" [@@bs.send.pipe: t];

external join : string => alias::string? => string => t = "" [@@bs.send.pipe: t];
external joinEx : string => alias::string? => Expression.t => t = "" [@@bs.send.pipe: t];

external _order : string => Js.boolean => t = "order" [@@bs.send.pipe: t];
let order field order select => switch order {
    | `Asc => _order field Js.true_ select
    | `Desc => _order field Js.false_ select
};

external toString : t => string = "" [@@bs.send];