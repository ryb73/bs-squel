open Squel;
open Squel.Params.Infix;

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
        )
        |> where("true")
        |> where("blah in (?, ?, ?)"
            |? 9 |+ 999 |+. "nine"
        )
        |> where("a = ?" |?. 10)
        |> toString
        |> Js.log
);

Insert.(
    make()
        |> into("tbl")
        |> setString("a", "ay")
        |> setInt("b", 99)
        |> setBool("bool", true)
        |> toString
        |> Js.log
);

Update.(
    make()
        |> table("tbl")
        |> setInt("v", 39)
        |> where("a = 9")
        |> setJson("j", Js.Json.number(11.0))
        |> setJson("j2", Js.Json.string("yo"))
        |> setJson("j3", Js.Json.boolean(Js.false_))
        |> setJson("j4", Js.Json.null)
        |> setJson("j5",
            [|1.0, 2.0, 3.0|]
                |> Js.Array.map(Js.Json.number)
                |> Js.Json.array
        )
        |> setJson("j6",
            [|("dog", Js.Json.string("good"))|]
                |> Js.Dict.fromArray
                |> Js.Json.object_
        )
        |> toString
        |> Js.log
);
