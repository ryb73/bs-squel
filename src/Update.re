type t;
[@bs.module "squel"] external make : unit => t = "update";

[@bs.send.pipe : t] external table : string => t = "";

include Settable.Make({ type nonrec t = t });

[@bs.send.pipe : t] external where : string => t = "";
[@bs.send.pipe : t] external whereEx : Expression.t => t = "where";

[@bs.send] external toString : t => string = "";
