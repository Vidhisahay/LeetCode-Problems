import pandas as pd

def categorize_products(activities: pd.DataFrame) -> pd.DataFrame:
    # Group by sell_date and aggregate
    result = activities.groupby('sell_date')['product'].agg([
        # 1. Count different products sold (unique)
        ('num_sold', 'nunique'),
        # 2. Sort unique product names and join them with a comma
        ('products', lambda x: ','.join(sorted(x.unique())))
    ]).reset_index()
    
    # 3. Return result ordered by sell_date
    return result.sort_values('sell_date')
