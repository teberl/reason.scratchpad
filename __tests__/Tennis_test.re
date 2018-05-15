open Jest;

open Expect;

open Tennis;

type score = {
  playerOne: int,
  playerTwo: int,
};

type testCase = {
  playerOne: int,
  playerTwo: int,
  expectedResult: string,
};

let testCases = [|
  {playerOne: 0, playerTwo: 0, expectedResult: "love-love"},
  {playerOne: 1, playerTwo: 0, expectedResult: "15-0"},
  {playerOne: 2, playerTwo: 0, expectedResult: "30-0"},
  {playerOne: 3, playerTwo: 0, expectedResult: "40-0"},
  {playerOne: 4, playerTwo: 0, expectedResult: "PlayerOne wins!"},
  {playerOne: 4, playerTwo: 1, expectedResult: "PlayerOne wins!"},
  {playerOne: 4, playerTwo: 2, expectedResult: "PlayerOne wins!"},
  {playerOne: 0, playerTwo: 1, expectedResult: "0-15"},
  {playerOne: 0, playerTwo: 2, expectedResult: "0-30"},
  {playerOne: 0, playerTwo: 3, expectedResult: "0-40"},
  {playerOne: 0, playerTwo: 4, expectedResult: "PlayerTwo wins!"},
  {playerOne: 1, playerTwo: 1, expectedResult: "15-15"},
  {playerOne: 1, playerTwo: 2, expectedResult: "15-30"},
  {playerOne: 1, playerTwo: 3, expectedResult: "15-40"},
  {playerOne: 1, playerTwo: 4, expectedResult: "PlayerTwo wins!"},
  {playerOne: 2, playerTwo: 4, expectedResult: "PlayerTwo wins!"},
  {playerOne: 2, playerTwo: 4, expectedResult: "PlayerTwo wins!"},
  {playerOne: 2, playerTwo: 1, expectedResult: "30-15"},
  {playerOne: 2, playerTwo: 2, expectedResult: "30-30"},
  {playerOne: 3, playerTwo: 2, expectedResult: "40-30"},
  {playerOne: 2, playerTwo: 3, expectedResult: "30-40"},
  {playerOne: 3, playerTwo: 3, expectedResult: "deuce"},
  {playerOne: 4, playerTwo: 4, expectedResult: "deuce"},
  {playerOne: 5, playerTwo: 4, expectedResult: "PlayerOne advantage"},
  {playerOne: 5, playerTwo: 5, expectedResult: "deuce"},
  {playerOne: 5, playerTwo: 6, expectedResult: "PlayerTwo advantage"},
  {playerOne: 5, playerTwo: 7, expectedResult: "PlayerTwo wins!"},
  {playerOne: 10, playerTwo: 10, expectedResult: "deuce"},
  {playerOne: (-2), playerTwo: 2, expectedResult: "invalid score"},
  {playerOne: 0, playerTwo: (-1), expectedResult: "invalid score"},
|];

Array.iter(
  testCase => {
    let playerOne = testCase.playerOne;
    let playerTwo = testCase.playerTwo;
    test(
      "if PlayerOne has "
      ++ string_of_int(playerOne)
      ++ " and PlayerTwo has "
      ++ string_of_int(playerTwo)
      ++ " points",
      () =>
      expect(parseScoreToCall(~playerOne, ~playerTwo))
      |> toBe(testCase.expectedResult)
    );
  },
  testCases,
);