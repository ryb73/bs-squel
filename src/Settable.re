module Make = (M : { type t }) => {
    [@bs.send.pipe: M.t] external setInt : (string, int) => M.t = "set";
    [@bs.send.pipe: M.t] external setFloat : (string, float) => M.t = "set";
    [@bs.send.pipe: M.t] external setString : (string, string) => M.t = "set";
    [@bs.send.pipe: M.t] external setBool : (string, bool) => M.t = "set";
};