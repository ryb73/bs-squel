type t;
[@bs.module "squel"] external make : unit => t = "delete";

[@bs.send.pipe : t] external from : string => t = "";

[@bs.send.pipe : t] external where : string => t = "";
[@bs.send.pipe : t] external whereEx : Expression.t => t = "where";

[@bs.send] external toString : t => string = "";
