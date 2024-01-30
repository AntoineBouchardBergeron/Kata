using System.Diagnostics;

namespace Kata.Tennis.Core;

public class TennisGame
{

    public readonly Player Red = new("Red");

    public readonly Player Blue = new("Blue");

    private int numberOfSetWinsToWinGame = 3;


    private async Task PlayMatch()
    {
        await Task.Delay(10);
        if (Random.Shared.Next() % 2 == 0)
        {
            Red.HasWonMatch(Blue);
        }
        else
        {
            Blue.HasWonMatch(Red);
        }
    }

    private async Task PlaySet()
    {
        await PlayMatch();
        while (Red.Score != Points.Love && Blue.Score != Points.Love)
        {
            await PlayMatch();
        }

        if (Red.SetScore > 2 && Blue.SetScore > 2)
        {
            if (Red.SetScore - Blue.SetScore > 2)
            {
                Red.WonSet(Blue);
                Debug.WriteLine("Red won the set");
            }
            else if (Blue.SetScore - Red.SetScore > 2)
            {
                Blue.WonSet(Red);
                Debug.WriteLine("Blue won the set");
            }
        }
    }

    public async Task PlayGame()
    {
        Debug.WriteLine("Game has started!");
        while (Blue.SetsWon < numberOfSetWinsToWinGame || Red.SetsWon < numberOfSetWinsToWinGame)
        {
            await PlaySet();
        }
    }
}