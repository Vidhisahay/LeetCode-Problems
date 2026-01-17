import pandas as pd

def sales_person(sales_person: pd.DataFrame, company: pd.DataFrame, orders: pd.DataFrame) -> pd.DataFrame:
    # 1. Merge Orders and Company to find "RED" company orders
    red_orders = pd.merge(orders, company, on='com_id')
    
    # 2. Get the list of sales_id that have orders for "RED"
    invalid_ids = red_orders[red_orders['name'] == 'RED']['sales_id'].unique()
    
    # 3. Filter SalesPerson table to exclude those invalid_ids
    # Using the tilde (~) operator for "NOT IN"
    result = sales_person[~sales_person['sales_id'].isin(invalid_ids)]
    
    # 4. Return only the 'name' column
    return result[['name']]
