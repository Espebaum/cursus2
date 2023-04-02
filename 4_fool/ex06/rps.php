<?php

// Prompt user to select rock, paper, or scissors
echo "Choose rock, paper, or scissors: ";
$user_choice = trim(fgets(STDIN));

// Generate random choice for computer
$choices = array('rock', 'paper', 'scissors');
$computer_choice = $choices[rand(0, 2)];

// Announce winner of game
// echo "You chose: $user_choice\n";
// echo "The computer chose: $computer_choice\n";

if ($user_choice == $computer_choice) {
    echo "It's a tie!\n";
} elseif ($user_choice == 'rock' && $computer_choice == 'scissors' ||
          $user_choice == 'paper' && $computer_choice == 'rock' ||
          $user_choice == 'scissors' && $computer_choice == 'paper') {
    echo "Congratulations! You won! The computer chose $computer_choice.\n";
} else {
    echo "Sorry, you lost. The computer chose $computer_choice.\n";
}
?>
