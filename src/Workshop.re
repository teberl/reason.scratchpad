type person = {
  name: string,
  age: int,
};

let square = (value: int) => value * value;

let setAge = (~person: person, ~newAge: int) => {...person, age: newAge};

let printPerson = person =>
  person.name ++ " is " ++ string_of_int(person.age) ++ " years old !";