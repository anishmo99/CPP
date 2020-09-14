def palindrome(x):
	# string
	i = 0
	flag = 0
	j = len(x) - 1
	while(i <= j):
		if x[i] != x[j]:
			flag = -1
			break
		i += 1
		j -= 1
	if (flag == 0):
		print("Palindrome")
	elif(flag == -1):
		print("NOT Palindrome")

s = input()
palindrome(s)