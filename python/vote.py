from selenium import webdriver
from selenium.webdriver.chrome.options import Options
from selenium.webdriver.common.by import By
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC

# Set up Chrome options to open in incognito mode
chrome_options = Options()
chrome_options.add_argument("--incognito")

# Set up webdriver with Chrome and incognito options
driver = webdriver.Chrome(options=chrome_options)

# Open the webpage
driver.get("https://www.votebradenton.com/?fbclid=IwAR0CpXVwNlm5YWc9kNsytT02Bgazr_0aDpFsjGmSqGIwo0uXBOdHNT0_Yws")

# Find and click the "Services" button
services_button = WebDriverWait(driver, 10).until(EC.element_to_be_clickable((By.LINK_TEXT, "SERVICES'\n' 31 SUBCATEGORIES")))
services_button.click()

# Find and click the "Wealth Management" button
wealth_management_button = WebDriverWait(driver, 10).until(EC.element_to_be_clickable((By.LINK_TEXT, "WEALTH MANAGEMENT")))
wealth_management_button.click()

# Find and click the "Aksala Wealth Advisors" button
aksala_button = WebDriverWait(driver, 10).until(EC.element_to_be_clickable((By.LINK_TEXT, "Aksala Wealth Advisors")))
aksala_button.click()

# Find and click the "REVIEW AND CAST MY BALLOT" button
review_button = WebDriverWait(driver, 10).until(EC.element_to_be_clickable((By.LINK_TEXT, "REVIEW AND CAST MY BALLOT")))
review_button.click()

# Find and click the "Submit Ballot" button
submit_button = WebDriverWait(driver, 10).until(EC.element_to_be_clickable((By.ID, "submit_button")))
submit_button.click()

# Wait for the "Done" button to appear and click it
done_button = WebDriverWait(driver, 10).until(EC.element_to_be_clickable((By.LINK_TEXT, "Done")))
done_button.click()

# Close the webpage
driver.quit()

print("Success")
