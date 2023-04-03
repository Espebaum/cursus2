import smtplib
from email.mime.multipart import MIMEMultipart
from email.mime.text import MIMEText
from email.mime.base import MIMEBase
from email import encoders

# Define sender, receiver, subject, and body
fromaddr = "vocops5000@gmail.com"
toaddr = "vocops5000@yonsei.ac.kr"
subject = "Test email with attachment"
body = "This is a test email sent with Python"

# Create the message object
msg = MIMEMultipart()

# Add the sender, receiver, subject, and body to the message
msg['From'] = fromaddr
msg['To'] = toaddr
msg['Subject'] = subject
msg.attach(MIMEText(body, 'plain'))

# Open the file to be sent
filename = "test.txt"
attachment = open(filename, "rb")

# Create the attachment object
p = MIMEBase('application', 'octet-stream')
p.set_payload((attachment).read())
encoders.encode_base64(p)
p.add_header('Content-Disposition', "attachment; filename= %s" % filename)

# Attach the attachment object to the message
msg.attach(p)

# Login to the SMTP server
server = smtplib.SMTP('smtp.gmail.com', 587)
server.starttls()
server.login(fromaddr, "hbvcyidasojdkhui")

# Send the message
text = msg.as_string()
server.sendmail(fromaddr, toaddr, text)

# Close the SMTP server connection
server.quit()