import pandas as pd

def actors_and_directors(actor_director: pd.DataFrame) -> pd.DataFrame:
    # Group by both IDs and count occurrences
    stats = actor_director.groupby(['actor_id', 'director_id']).size().reset_index(name='counts')
    
    # Filter for at least 3 collaborations
    result = stats[stats['counts'] >= 3][['actor_id', 'director_id']]
    
    return result
