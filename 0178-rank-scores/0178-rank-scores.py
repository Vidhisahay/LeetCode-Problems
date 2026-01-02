import pandas as pd

def order_scores(scores: pd.DataFrame) -> pd.DataFrame:
    # Use the rank method with 'dense' to assign ranks to the scores in descending order with no gaps
    scores["rank"] = scores["score"].rank(method="dense", ascending=False).astype(int)
    
    # Sort the DataFrame by score in descending order
    result_df = scores.sort_values(by="score", ascending=False)
    
    # Return only the required columns: 'score' and 'rank'
    return result_df[["score", "rank"]]