def classify_website(url):
    # Normalize the URL by removing the 'https://' part if it exists
    if url.startswith("https://"):
        url = url[8:]
    
    # Check the prefixes
    if url.startswith("www.nowcoder.com"):
        return "Nowcoder"
    elif url.startswith("ac.nowcoder.com"):
        return "Ac"
    else:
        return "No"

def main():
    import sys
    input = sys.stdin.read
    data = input().strip().split('\n')
    
    T = int(data[0].strip())
    results = []
    
    for i in range(1, T + 1):
        url = data[i].strip()
        result = classify_website(url)
        results.append(result)
    
    # Output all results
    for result in results:
        print(result)

if __name__ == "__main__":
    main()
