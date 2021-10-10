def response(input_text):
    user_message = str(input_text).lower()

    if user_message in ('hello', 'hi', 'hey'):
        return "Hey! How are you?"
    elif user_message in ('i am good', 'good'):
        return "That is good to hear! :)"
    elif user_message in ('how are you', 'how are you?'):
        return "I am good! Thanks for asking :)"
    elif user_message in ('who are you', 'who are you?'):
        return "I am a CRIO #IBD Remote Working Tools Edition Support BOT. My name is BOTSY BOT."
    elif user_message in ('what can you do', 'what can you do?'):
        return "I can help you with your queries. Please enter Menu to know more."
    elif user_message in ('menu'):
        return "Enter the serial number or the query\n 1. What is CRIO IBD Remote Working Tools Edition\n 2. What are the challenges?\n 3. Where should I submit my project?\n 4. What are the themes?\n 5. How should I submit my project?\n 6. What is in there for me?\n 7. What is the deadline?\n 8. I have more queries."
    elif user_message in ('1', str('What is CRIO IBD Remote Working Tools Edition').lower()):
        return "Welcome to the Remote Working Tools edition of #IBelieveinDoing!\nIn this edition, you will be building useful open-source apps and extensions to boost team productivity and make WFH funnier, easier, and healthier for the mind :)\nThe most popular tech solutions built in this edition stand a chance to get featured on Crio’s social pages. And not just that.\nGrab this chance to walk away with assured recognitions, exciting rewards, and a fantastic Crio scholarship for Crio Learning programs :)\nAre you ready for this exciting #IBelieveinDoing challenge?"
    elif user_message in ('2', str('What are the challenges?').lower()):
        return "Task 1: Build Open-Source apps and extensions of your choice. Build a smart tool to make remote working easier for people. Pick an idea from our idea pool or come up with an idea of your own, and build it in the given time.\nTask 2: Share your experience with the world. Write a blog on Medium/Dev.to about what you learned while building your tool. You can also share a demo video of your work. Don’t forget to popularize your blog/video as that’s going to decide your winning points."
    elif user_message in ('3', str('Where should I submit my project?').lower()):
        return "Share your project here: https://crioforms.typeform.com/to/AKt3qw7R?utm_source=xxxxx#name=xxxxx"
    elif user_message in ('4', str('What are the themes?').lower()):
        return "1. Chrome extensions\n 2. Slack extensions\n 3. Alexa skills\n 4. AWS Lambda functions\n 5. Android apps\n 6. Telegram Bot\n 7. Discord Bot\n 8. Voice assistants\n 9. Miscellaneous"
    elif user_message in ('5', str('How should I submit my project?').lower()):
        return "Please find the submission guidelines at https://docs.google.com/document/d/1DXgKki3EcEEb-99Oqyyq0WLItTBhXj3aZ1swtKkwg6U/edit#heading=h.w6cf7cfugx3"
    elif user_message in ('6', str('What is in there for me?').lower()):
        return "Winner: Sennheiser Wireless Noise Cancellation Headphone + 25% Additional Scholarship to Crio signature programs.\nTop 2 Performers: OnePlus smart band + 25% Additional Scholarship to Crio signature programs.\nTop 3 - Top 15 Performers: ₹ 5,000 Amazon gift voucher."
    elif user_message in ('7', str('What is the deadline?').lower()):
        return "July 11, 2021 11:59 PM IST"
    elif user_message in ('8', str('I have more queries.').lower()):
        return "Please join the slack channel and ask our advocates."
    else:
        return "I don't understand! Try again"
