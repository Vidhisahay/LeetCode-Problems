import pandas as pd

def valid_emails(users: pd.DataFrame) -> pd.DataFrame:
    # Use str.match to filter rows that fit the regex pattern
    # The pattern ensures the prefix starts with a letter and ends with @leetcode.com
    pattern = r'^[a-zA-Z][a-zA-Z0-9._-]*@leetcode\.com$'
    
    return users[users['mail'].str.match(pattern)]
