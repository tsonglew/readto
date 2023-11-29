import time

start_time = time.time()
size = 0
while True:
    try:
        data = buffer.read()
        size += len(data)
        duration = time.time() - start_time
        speed = (size / 1024 / 1024 ) / duration
        print(f"{speed}MB/s")
    except EOFError as e:
        break