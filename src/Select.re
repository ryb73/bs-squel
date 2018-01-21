type t;
[@bs.module "squel"] external make : unit => t = "select";

[@bs.send.pipe : t] external _from : (string, ~alias: string=?, unit) => t = "from";
let from = (~alias=?, table) => _from(table, ~alias?, ());

[@bs.send.pipe : t] external field : string => t = "";
[@bs.send.pipe : t] external group : string => t = "";

[@bs.send.pipe : t] external where : string => t = "";
[@bs.send.pipe : t] external whereEx : Expression.t => t = "where";

[@bs.send.pipe : t] external join : (string, ~alias: string=?, string) => t = "";
[@bs.send.pipe : t] external joinEx : (string, ~alias: string=?, Expression.t) => t = "";

[@bs.send.pipe : t] external _order : (string, Js.boolean) => t = "order";
let order = (field, order, select) =>
    switch order {
        | `Asc => _order(field, Js.true_, select)
        | `Desc => _order(field, Js.false_, select)
  };

[@bs.send] external toString : t => string = "";
