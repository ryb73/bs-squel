type t;
[@bs.module "squel"] external make : unit => t = "expr";

[@bs.send.pipe : t] external and_ : string => t = "and";
[@bs.send.pipe : t] external or_ : string => t = "or";
