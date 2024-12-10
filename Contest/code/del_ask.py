with open('ask.txt', 'r') as file:
	ask = file.read().split('\n')
print(ask)
with open('ask.txt', 'w') as file:
	file.write(' '.join(ask))