import pandas as pd

def count_salary_categories(accounts: pd.DataFrame) -> pd.DataFrame:
    # Count accounts in each category using boolean indexing
    low_count = accounts[accounts['income'] < 20000].shape[0]
    average_count = accounts[(accounts['income'] >= 20000) & (accounts['income'] <= 50000)].shape[0]
    high_count = accounts[accounts['income'] > 50000].shape[0]

    # Create the result DataFrame with all three categories
    result_df = pd.DataFrame({
        'category': ['Low Salary', 'Average Salary', 'High Salary'],
        'accounts_count': [low_count, average_count, high_count]
    })

    return result_df