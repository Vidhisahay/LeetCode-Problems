import pandas as pd

def students_and_examinations(students: pd.DataFrame, subjects: pd.DataFrame, examinations: pd.DataFrame) -> pd.DataFrame:
    # 1. Create all student-subject combinations
    all_combinations = students.merge(subjects, how='cross')
    
    # 2. Count exam attendances
    exam_counts = examinations.groupby(['student_id', 'subject_name']).size().reset_index(name='attended_exams')
    
    # 3. Merge counts onto combinations and fill missing with 0
    result = all_combinations.merge(exam_counts, on=['student_id', 'subject_name'], how='left')
    result['attended_exams'] = result['attended_exams'].fillna(0).astype(int)
    
    # 4. Sort and select columns
    return result.sort_values(by=['student_id', 'subject_name'])[['student_id', 'student_name', 'subject_name', 'attended_exams']]
