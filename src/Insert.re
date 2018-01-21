type t;
[@bs.module "squel"] external make : unit => t = "insert";

[@bs.send.pipe : t] external into : string => t = "";

include Settable.Make({ type nonrec t = t });

[@bs.send] external toString : t => string = "";
