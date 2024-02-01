namespace Tennis.Components;

public class Game : ContentView
{

	private Kata.Tennis.Core.TennisGame TennisGame = new(); 
	public string ButtonText = "Start Game";
	Button StartGame;
	Label blueLabel;
	Label redLabel;
	public Game()
	{
		StartGame = new Button {
					Text = $"{ButtonText}",
				};
		StartGame.Clicked += async (sender, args) => 
			await TennisGame.PlayGame(); 

		blueLabel = new Label { BindingContext = TennisGame.Blue, HorizontalOptions = LayoutOptions.Center, VerticalOptions = LayoutOptions.Center, Text = $"Player 1 (Blue) points: { TennisGame.Blue.Score }"},
		redLabel = new Label { BindingContext = TennisGame.Red, HorizontalOptions = LayoutOptions.Center, VerticalOptions = LayoutOptions.Center, Text = $"Player 2 (Red) points: { TennisGame.Red.Score }"}
		
		blueLabel.SetBinding(TennisGame.Blue, "Score");

		Content = new VerticalStackLayout
		{
			Children = {
				new Label { HorizontalOptions = LayoutOptions.Center, VerticalOptions = LayoutOptions.Center, Text = "This is the tennis kata, the first to 3 set won wins the game!"},
				StartGame,
				blueLabel,
				redLabel,
					},
			Padding = 30,
			Spacing = 20,
		};
	}
}

