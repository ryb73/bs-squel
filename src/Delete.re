type t;

[@bs.module "squel"] external _make : Js.t(_) => t = "delete";
let make () = _make { "replaceSingleQuotes": Js.true_ };

[@bs.send.pipe: t] external from : string => t = "";

include Whereable.Make({ type nonrec t = t });

[@bs.send] external toString : t => string = "";
[@bs.send] external toParam : t => string = "";
