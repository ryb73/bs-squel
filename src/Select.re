type t;

[@bs.module "squel"] external _make : Js.t(_) => t = "select";
let make () = _make { "replaceSingleQuotes": true };

[@bs.send.pipe: t] external _from : (string, ~alias: string=?, unit) => t = "from";
let from = (~alias=?, table) => _from(table, ~alias?, ());

[@bs.send.pipe: t] external field : string => t = "";
[@bs.send.pipe: t] external group : string => t = "";

include Whereable.Make({ type nonrec t = t });

[@bs.send.pipe: t] external join : (string, ~alias: string=?, string) => t = "";
[@bs.send.pipe: t] external joinEx : (string, ~alias: string=?, Expression.t) => t = "";

[@bs.send.pipe: t] external _order : (string, bool) => t = "order";
let order = (field, order, select) =>
    switch order {
        | `Asc => _order(field, true, select)
        | `Desc => _order(field, false, select)
  };

[@bs.send] external toString : t => string = "";
[@bs.send] external toParam : t => string = "";
