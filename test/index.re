open! BsSquel;
open BsSquel.Params.Infix;

Select.(
    make()
        |> from(~alias="aloha", "tbl")
        |> join(~alias="tobias", "tbl2", "tbl.a = tobias.a")
        |> field("tobias.ok")
        |> field("count(*)")
        |> group("tobias.ok")
        |> order("tobias.ok", `Desc)
        |> whereEx(
            Expression.make()
                |> Expression.and_("ok = 4")
                |> Expression.or_("ok = 40")
        )
        |> where("true")
        |> where("blah in (?, ?, ?)"
            |? 9 |+ 999 |+. "nine"
        )
        |> where("a = ?" |?. 10)
        |> toParam
        |> Js.log
);

Insert.(
    make()
        |> into("tbl")
        |> setString("a", "a\"'y")
        |> setInt("b", 99)
        |> setBool("bool", true)
        |> toParam
        |> Js.log
);

Update.(
    make()
        |> table("tbl")
        |> setInt("v", 39)
        |> where("a = 9")
        |> toParam
        |> Js.log
);

Select.(
    make()
        |> from("tracks")
        |> field("*")
        |> where("name = ?" |?. "My Body's Made of Crushed Little Stars")
        |> where("primaryArtistId = ?" |?. 312)
        |> toParam
        |> Js.log
);