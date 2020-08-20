#from socket import *
import smtplib
from email.mime.text import MIMEText
from email.mime.multipart import MIMEMultipart

'''clientSocket = socket(AF_INET, SOCK_STREAM)		#TCP Connection to Server
clientSocket.connect(server)'''

email_user = 'shrey.mailtest@gmail.com'			#Enter the sender's mail ID 
email_password = 'QwertyASD619'				#Enter the sender's Password
email_send = 'dmu1@binghamton.edu'			#Enter receivers mail ID
subject = 'Python Mail'					#Enter the Subject of Mail

msg = MIMEMultipart()
msg['From'] = email_user
msg['To'] = email_send
msg['Subject'] = subject

body = 'Hi there, sending this email from Python!'	# Enter the content you want to send
msg.attach(MIMEText(body,'plain'))
text = msg.as_string()
server = smtplib.SMTP_SSL('smtp.gmail.com',465)		#SSL Socket 

server.ehlo()
server.login(email_user,email_password)


server.sendmail(email_user,email_send,text)
server.quit()