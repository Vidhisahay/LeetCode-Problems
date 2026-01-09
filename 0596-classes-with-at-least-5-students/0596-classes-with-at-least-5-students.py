import pandas as pd

def find_classes(courses: pd.DataFrame) -> pd.DataFrame:
    # Group by 'class' and filter groups with 5 or more rows (students)
    result_df = courses.groupby('class').filter(lambda x: len(x) >= 5)
    # Select the 'class' column and get unique values, then convert back to DataFrame
    return result_df[['class']].drop_duplicates()