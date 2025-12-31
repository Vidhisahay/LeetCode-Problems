import pandas as pd

def second_highest_salary(employee_df: pd.DataFrame) -> pd.DataFrame:
    # Get unique salaries and sort them in descending order
    unique_salaries = employee_df['salary'].drop_duplicates().sort_values(ascending=False)

    # Check if there are at least two unique salaries
    if len(unique_salaries) < 2:
        # Return None if no second highest salary exists
        return pd.DataFrame({'SecondHighestSalary': [None]})
    else:
        # Get the second element (index 1) from the sorted unique salaries
        second_highest = unique_salaries.iloc[1]
        # Return as a DataFrame with the required column name
        return pd.DataFrame({'SecondHighestSalary': [second_highest]})