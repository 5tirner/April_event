# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    send_mail.py                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zasabri <zasabri@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/03 20:26:12 by zasabri           #+#    #+#              #
#    Updated: 2023/04/03 23:09:58 by zasabri          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import getpass
import smtplib
from email.mime.text import MIMEText
from email.mime.multipart import MIMEMultipart

#The smtplib module is used to connect to an SMTP server and send an email. The MIMEText, MIMEMultipart
#and MIMEImage classes from the email.mime module are used to create and format the email message.

message = MIMEMultipart()

message['From'] = input("From: ")
message['To'] = input("To: ")
message['Subject'] = input("Subject: ")

#Create a MIMEMultipart object to hold the email message. Set the From, To, and Subject headers of the email message
#Replace 'sender@email.com' and 'recipient@email.com' with the actual email addresses of the sender and recipient.

text = MIMEText('This Email Sent From Sh/Py')
message.attach(text)

#Create a MIMEText object containing the body text of the email message
#Attach the MIMEText object to the MIMEMultipart object using the attach() method.

smtp_server = 'smtp.gmail.com'
smtp_port = 587
smtp_username = input("Enetr Your Gmail: ")
smtp_password = input("Enter Password: ")

#Set the smtp_server, smtp_port, smtp_username
#and smtp_password variables to the appropriate values for your email account and SMTP server
#Replace 'your_email@gmail.com' and 'your_password' with your actual email address and password.
try:
    server = smtplib.SMTP(smtp_server, smtp_port)
    server.starttls()
    server.login(smtp_username, smtp_password)
    server.sendmail(message['From'], message['To'], message.as_string())
    server.quit()
    print("\n Done")
except:
    print("\nError:")
    print("1- Check Your Email And Your Password")
    print("2- Check Your Connection")

#Create an SMTP object by passing the smtp_server and smtp_port variables to the smtplib.SMTP() constructor
#Call the starttls() method to enable encryption of the connection
#Call the login() method to authenticate the user with the email server using the smtp_username and smtp_password variables
#Call the sendmail() method to send the email message
#Finally, call the quit() method to close the connection to the email server.