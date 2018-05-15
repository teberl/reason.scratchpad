/* Score calling in tennis is unusual in that each point has a corresponding call that is different from its point value.
   Further explanation: https://en.wikipedia.org/wiki/Tennis_scoring_system#Game_score

   PatternMatching
   https://reasonml.github.io/docs/en/pattern-matching.html */
let getCallFromPoints = score =>
  switch (score) {
  | 0 => "0"
  | 1 => "15"
  | 2 => "30"
  | 3 => "40"
  | _ => "NotAScore"
  };

let hasTwoPointsDiff = (playerOne: int, playerTwo: int) =>
  abs(playerOne - playerTwo) > 1;

let playerOneWins = (playerOne: int, playerTwo: int) =>
  playerOne > 3
  && playerOne > playerTwo
  && hasTwoPointsDiff(playerOne, playerTwo);

let playerTwoWins = (playerOne: int, playerTwo: int) =>
  playerTwo > 3
  && playerTwo > playerOne
  && hasTwoPointsDiff(playerOne, playerTwo);

let parseScoreToCall = (~playerOne, ~playerTwo) =>
  switch (playerOne, playerTwo) {
  | (0, 0) => "love-love"
  | (3, 3) => "deuce"
  | _ when playerOne < 0 || playerTwo < 0 => "invalid score"
  | _ when playerOneWins(playerOne, playerTwo) => "PlayerOne wins!"
  | _ when playerTwoWins(playerOne, playerTwo) => "PlayerTwo wins!"
  | _ when playerOne < 4 && playerTwo < 4 =>
    getCallFromPoints(playerOne) ++ "-" ++ getCallFromPoints(playerTwo)
  | _ when playerOne == playerTwo => "deuce"
  | _ when playerOne > playerTwo => "PlayerOne advantage"
  | _ when playerOne < playerTwo => "PlayerTwo advantage"
  };