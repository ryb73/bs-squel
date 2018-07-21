type t;

[@bs.module "squel"] external _make : Js.t(_) => t = "update";
let make () = _make { "replaceSingleQuotes": true };

[@bs.send.pipe: t] external table : string => t = "";

include Settable.Make({ type nonrec t = t });
include Whereable.Make({ type nonrec t = t });

[@bs.send] external toString : t => string = "";
[@bs.send] external toParam : t => string = "";
