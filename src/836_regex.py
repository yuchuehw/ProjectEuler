import re
print("".join(word[0] for word in " ".join(re.findall(r'<b>(.*?)<\/b>', question)).split()))
