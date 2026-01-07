import pandas as pd

def game_analysis(activity: pd.DataFrame) -> pd.DataFrame:
    # Group the activity data by player_id and aggregate to find the minimum event_date for each player.
    # The result is a Series, which is then converted back to a DataFrame.
    first_logins = activity.groupby('player_id')['event_date'].min().reset_index()
    
    # Rename the 'event_date' column to 'first_login' as required by the problem output format.
    first_logins.rename(columns={'event_date': 'first_login'}, inplace=True)
    
    return first_logins

