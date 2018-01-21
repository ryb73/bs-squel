module Make = (M : { type t }) => {
    [@bs.send.pipe: M.t] external setInt : (string, int) => M.t = "set";
    [@bs.send.pipe: M.t] external setFloat : (string, float) => M.t = "set";
    [@bs.send.pipe: M.t] external setString : (string, string) => M.t = "set";

    [@bs.send.pipe: M.t] external _setBool : (string, Js.boolean) => M.t = "set";
    let setBool = (column, bool) => Js.Boolean.to_js_boolean(bool) |> _setBool(column);

    let setJson = (column, json) => Js.Json.stringify(json) |> setString(column);
};