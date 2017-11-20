external _unsafeApply : 'return => 'b => array 'c => 'return = "apply" [@@bs.send];

type _any;
external _any : _ => _any = "%identity";

type paramBuilder = ParamBuilder _any (array _any);

let build expr => ParamBuilder (_any expr) [||];

let bind v (ParamBuilder expr bindings) => {
    Js.Array.push (_any v) bindings;
    ParamBuilder expr bindings;
};

type _t;
external _strVal : _t = "str" [@@bs.module "squel"];
external _toString : _t => string = "toString" [@@bs.send];
let toString (ParamBuilder expr bindings) => {
    let params = [| expr |] |> Js.Array.concat bindings;
    _unsafeApply _strVal Js.null params
        |> _toString;
};

module Infix = {
    let (|?) s v => bind v (build s);
    let (|+) pb v => bind v pb;
    let (|+.) pb v => pb |+ v |> toString;
    let (|?.) s v => s |? v |> toString;
};