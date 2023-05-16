import smtplib
import ssl
from email.message import EmailMessage

# Define the subject and body of the email
subject = 'Winter End Sale'
body_template = """
Hi {name},

We are starting our Winter End Sale with 50% discount on all items for specific customers. Grab your favorite items and enjoy!

Follow <a href="http://www.thewholesalers.com">The Wholesalers</a> to get more updates.

Thanks,
The Wholesalers
"""

# Add SSL (layer of security)
context = ssl.create_default_context()

# Open the credentials file and read the email and password from it
with open('credentials.txt') as f:
    email_sender = f.readline().strip()
    email_password = f.readline().strip()

# Open the file containing the list of names and emails
with open('names.txt') as f:
    for line in f:
        # Extract the name and email address from the line
        name, email = line.strip().split(', ')
        em = EmailMessage()
        em['From'] = email_sender
        em['To'] = email
        em['Subject'] = subject
        body = body_template.format(name=name)
        em.set_content(body)
        print(name, email)
        # Log in and send the email
        if email.endswith('@ucp.edu.pk'):
            with smtplib.SMTP_SSL('outlook.office365.com', 465, context=context) as smtp:
                smtp.login(email_sender, email_password)
                smtp.sendmail(email_sender, email, em.as_string())
        else:
            with smtplib.SMTP_SSL('smtp.gmail.com', 465, context=context) as smtp:
                smtp.login(email_sender, email_password)
                smtp.sendmail(email_sender, email, em.as_string())
