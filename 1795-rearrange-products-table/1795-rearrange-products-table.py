import pandas as pd

def rearrange_products_table(products: pd.DataFrame) -> pd.DataFrame:
    # Melt the DataFrame to unpivot the store columns into rows
    melted_products = pd.melt(
        products,
        id_vars=['product_id'],      # Keep 'product_id' as the identifier
        var_name='store',            # Name of the new column for store names (store1, store2, etc.)
        value_name='price'           # Name of the new column for the prices
    )
    
    # Drop rows with NaN values in the 'price' column (products not available in that store)
    result = melted_products.dropna(subset=['price']) 
    
    return result
