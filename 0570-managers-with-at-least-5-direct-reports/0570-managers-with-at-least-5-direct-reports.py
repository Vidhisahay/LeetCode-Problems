import pandas as pd

def find_managers(employee: pd.DataFrame) -> pd.DataFrame:
    # 1. Count occurrences of each managerId
    counts = employee['managerId'].value_counts()
    
    # 2. Filter for managerIds with 5 or more reports
    valid_manager_ids = counts[counts >= 5].index
    
    # 3. Filter original DataFrame to find names matching those IDs
    result = employee[employee['id'].isin(valid_manager_ids)][['name']]
    
    return result
