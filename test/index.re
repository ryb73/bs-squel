open Squel;
open Squel.Params.Infix;

Select.(
    make ()
        |> from alias::"aloha" "tbl"
        |> join alias::"tobias" "tbl2" "tbl.a = tobias.a"
        |> field "tobias.ok"
        |> field "count(*)"
        |> group "tobias.ok"
        |> order "tobias.ok" `Desc
        |> whereEx (
            Expression.make ()
                |> Expression.and_ "ok = 4"
        )
        |> where "true"
        |> where (
            "blah in (?, ?, ?)"
                |? 9 |+ 999 |+. "nine"
        )
        |> where ("a = ?" |?. 10)
        |> toString
        |> Js.log
);

Insert.(
    make ()
        |> into "tbl"
        |> set "a" "ay"
        |> set "b" 99
        |> toString
        |> Js.log
);

Update.(
    make ()
        |> table "tbl"
        |> set "v" 39
        |> where "a = 9"
        |> toString
        |> Js.log
);