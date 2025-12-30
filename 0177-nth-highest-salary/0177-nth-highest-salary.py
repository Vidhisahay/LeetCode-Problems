import pandas as pd

def nth_highest_salary(employee: pd.DataFrame, N: int) -> pd.DataFrame:
    # 1. Get unique salaries and sort them in descending order
    unique_salaries = employee['salary'].drop_duplicates().sort_values(ascending=False)
    
    # 2. Check if N is valid (within the range of existing unique salaries)
    if N <= 0 or N > len(unique_salaries):
        # Return None wrapped in a DataFrame with the specific column name
        return pd.DataFrame({f'getNthHighestSalary({N})': [None]})
    
    # 3. Access the N-th salary (index N-1)
    result = unique_salaries.iloc[N - 1]
    
    # 4. Return the result in the required format
    return pd.DataFrame({f'getNthHighestSalary({N})': [result]})
