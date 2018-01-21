type t;
[@bs.module "squel"] external make : unit => t = "insert";

[@bs.send.pipe : t] external into : string => t = "";
[@bs.send.pipe : t] external set : (string, 'a) => t = "";

[@bs.send] external toString : t => string = "";
