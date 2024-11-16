import paramiko

def sendCommand(command):
	stdin, stdout, stderr = ssh.exec_command(command)
	print('<< ', stdout.read().decode())

ssh = paramiko.SSHClient()

ssh.set_missing_host_key_policy(paramiko.AutoAddPolicy())

ip = ''
port = 22
#username = 'kali'
#password = 'kali'
username = ''
password = ''

ssh.connect(ip, port=port, username=username, password=password)

command = 'whoami'

while command.lower().strip() != 'kapat':
	if command != '':
		sendCommand(command)
	command = input('>> ')
