import openai
# Define OpenAI API key 
openai.api_key = "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"

# Set up the model and prompt
model_engine = "text-davinci-003"


prompt = input("YOU: ")

# Define a function to generate a response
def generate_response(prompt):
    completion = openai.Completion.create(
        engine=model_engine,
        prompt=prompt,
        max_tokens=1024,
        stop=None,
        temperature=0.5,
    )

    response = completion.choices[0].text
    print("ChatBot:", response)
    
# Create a loop to continue prompting the user
while True:
    generate_response(prompt)
    prompt = input("YOU: ")
    if prompt == "CLOSE!":
        break