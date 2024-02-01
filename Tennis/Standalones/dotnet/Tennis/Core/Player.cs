using System.ComponentModel;
using System.Diagnostics;

namespace Kata.Tennis.Core;

public class Player: INotifyPropertyChanged
{

    public Player (string Name){
        this.Name = Name;
    }
    // holds information about the Set
    public Points Score { get; set; } = Points.Love;

    // Holds the Score for the active set.
    public int SetScore { get; set; } = 0;
    public int SetsWon { get; set; } = 0;

    private string Name {get; set;}

    // Holds the SetScores, if many sets are played
    public List<int> SetScores { get; set; } = [];

    public event PropertyChangedEventHandler? PropertyChanged;

    public void HasLostAdvantage() => this.Score = Points.Deuce;
    public void ResetMatch() => this.Score = Points.Love;

    public void WonSet(Player opponent)
    {
        SetsWon++;
        SetScores.Add(SetScore);
        opponent.SetScores.Add(opponent.SetScore);
        SetScore = 0;
        opponent.SetScore = 0;
    }

    public void HasWonSet(Player opponent)
    {
        this.SetScore++;
        ResetMatch();
        opponent.ResetMatch();
    }

    public void HasWonMatch(Player opponent)
    {
        switch (this.Score)
        {
            case Points.Love:
                this.Score = Points.Fifteen;
                break;

            case Points.Fifteen:
                this.Score = Points.Thrity;
                break;

            case Points.Thrity:
                if (opponent.Score == Points.Forty)
                {
                    opponent.Score = Points.Deuce;
                    this.Score = Points.Deuce;
                }
                else
                {
                    this.Score = Points.Forty;
                }
                break;

            case Points.Forty:
                HasWonSet(opponent);
                break;

            case Points.Advantage:
                HasWonSet(opponent);
                break;

            case Points.Deuce:
                if (opponent.Score == Points.Advantage)
                {
                    opponent.HasLostAdvantage();
                }
                else if (this.Score == Points.Deuce)
                {
                    this.Score = Points.Advantage;
                }
                else
                {
                    ResetMatch();
                }
                break;

            default:
                throw new Exception("unreachable condition has been found in PlayerWonMatch");
        }
        Debug.WriteLine($"[{Name}] won and has a score of: {this.Score}");
        PropertyChanged?.Invoke(this, new PropertyChangedEventArgs("Score"));
    }

}