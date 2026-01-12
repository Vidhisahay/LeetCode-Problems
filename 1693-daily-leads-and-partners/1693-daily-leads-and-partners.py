import pandas as pd

def daily_leads_and_partners(daily_sales: pd.DataFrame) -> pd.DataFrame:
    # Group by date and make name, then count unique lead_id and partner_id
    result = daily_sales.groupby(['date_id', 'make_name']).agg(
        unique_leads=('lead_id', 'nunique'),
        unique_partners=('partner_id', 'nunique')
    ).reset_index()
    
    return result
