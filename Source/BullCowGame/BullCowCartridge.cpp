// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();
	
	InitGame();
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{		   
	if (bGameOver)
	{
		ClearScreen();
		InitGame();
	}
	else
	{
		ProcessGuess(Input);
	}
}

void UBullCowCartridge::ProcessGuess(FString Guess)
{
	if (Guess == HiddenWord)
	{
		PrintLine(TEXT("You have Won!"));
		EndGame();
		return;
	}

	//if (!IsIsogram)
	//{
	//	PrintLine(Text("No repeating letters, guess again!"));
	//}
	
	if (Guess.Len() == HiddenWord.Len())
	{
		PrintLine(TEXT("The Hidden Word is %i characters long, try again!"), HiddenWord.Len());
		return;
	}

	PrintLine(TEXT("Lost a life."));
	--Lives;
	
	if (Lives > 0)
	{
		PrintLine(TEXT("You guessed wrong. %i live left"), Lives);
		return;
	}	

	PrintLine(TEXT("You have Lost!"));
	EndGame();	
}

void UBullCowCartridge::InitGame()
{
	HiddenWord = TEXT("hello");
	Lives = HiddenWord.Len();
	bGameOver = false;

	PlayerGreeting();

	int i = 0;

	const char HW[] = "hello";
	HW;
}

void UBullCowCartridge::EndGame()
{
	bGameOver = true;
	PrintLine(TEXT("Press enter to continue..."));
}

void UBullCowCartridge::PlayerGreeting() const
{
	PrintLine(TEXT("The HiddenWord is: %s."), *HiddenWord);
	PrintLine(TEXT("Welcome to a Bull Cows Game!"));
	PrintLine(TEXT("Guess the %i letter word."), HiddenWord.Len());
	PrintLine(TEXT("You have %i lives."), Lives);
	PrintLine(TEXT("Type in you guess \nand press enter to continue..."));
}
