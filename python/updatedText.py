with open('original.txt', 'r', encoding='utf-8') as original_file:
    original_data = original_file.readlines()


# Create an empty list to store the updated data
updated_data = []

# Loop over each line in the original data
for line in original_data:
    # Split the line into words
    words = line.split()
    # Get the first word (the key)
    key = words[0]
    # Append the key to the updated data list
    updated_data.append(key)

# Open the new file for writing
with open('updated1.txt', 'w') as updated_file:
    # Write the updated data to the new file
    updated_file.write('\n'.join(updated_data))
