import pandas as pd

def largest_orders(orders: pd.DataFrame) -> pd.DataFrame:
    # 1. Check if the DataFrame is empty
    if orders.empty:
        return pd.DataFrame(columns=['customer_number'])
    
    # 2. Count the occurrences of each customer_number
    # 3. Find the index (customer_number) of the maximum count
    largest_customer = orders['customer_number'].value_counts().idxmax()
    
    # 4. Return as a DataFrame per problem requirements
    return pd.DataFrame({'customer_number': [largest_customer]})
