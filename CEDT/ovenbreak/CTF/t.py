with open("out.txt", "a") as f:
    # f.write("Now the file has more content!")
    with open("./CTF11.txt", "r", encoding="utf-8") as file:
        content = file.read()
        for c in content:
            if c == "\\n":
                print("WHWHWH")
