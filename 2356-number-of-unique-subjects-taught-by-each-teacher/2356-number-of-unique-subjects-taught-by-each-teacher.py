import pandas as pd

def count_unique_subjects(teacher: pd.DataFrame) -> pd.DataFrame:
    
    # Group by teacher_id and count the number of unique subject_ids
    result_df = teacher.groupby('teacher_id')['subject_id'].nunique().reset_index()
    # Rename the count column for clarity (optional, but good practice)
    result_df.rename(columns={'subject_id': 'cnt'}, inplace=True)
    return result_df