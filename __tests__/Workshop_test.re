open Jest;

open Workshop;

describe("square", () =>
  Expect.(
    test("squares the provided number", () =>
      expect(square(3)) |> toBe(9)
    )
  )
);

describe("setAge", () => {
  open Expect;
  let p1: person = {name: "name", age: 1};
  let p2 = setAge(~newAge=5, ~person=p1);
  test("updates the age of the person record", () =>
    expect(p2.age) |> toBe(5)
  );
  test("keeps the name of the person record unchagend", () =>
    expect(p2.name) |> toBe("name")
  );
});

describe("printPerson", () => {
  open Expect;
  let p1: person = {name: "StarLord", age: 42};
  let expectedResult = "StarLord is 42 years old !";
  test("print a person", () =>
    expect(printPerson(p1)) |> toBe(expectedResult)
  );
});