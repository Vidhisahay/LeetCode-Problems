import pandas as pd

def department_highest_salary(employee: pd.DataFrame, department: pd.DataFrame) -> pd.DataFrame:
    # Merge the two DataFrames on departmentId
    merged_df = pd.merge(employee, department, left_on='departmentId', right_on='id', suffixes=('_emp', '_dept'))

    # Calculate the maximum salary for each department and add as a new column
    merged_df['max_salary'] = merged_df.groupby('departmentId')['salary'].transform('max')

    # Filter for rows where the employee's salary equals the department's max salary
    highest_paid = merged_df[merged_df['salary'] == merged_df['max_salary']]

    # Select and rename columns for the final output
    result = highest_paid[['name_dept', 'name_emp', 'salary']]
    result.columns = ['Department', 'Employee', 'Salary']
    return result
