import pandas as pd

def replace_employee_id(employees: pd.DataFrame, employee_uni: pd.DataFrame) -> pd.DataFrame:
    # Perform a left join on the 'id' column
    # This keeps all employees and adds 'unique_id' where available
    merged_df = pd.merge(employees, employee_uni, on='id', how='left')
    
    # Select only the required columns: unique_id and name
    return merged_df[['unique_id', 'name']]
