module Make = (M : { type t }) => {
    [@bs.send.pipe: M.t] external where : string => M.t = "";
    [@bs.send.pipe: M.t] external whereEx : Expression.t => M.t = "where";
};