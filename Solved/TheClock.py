def main():
    DEGREE_PER_MIN = 55#round(365/6) #in tenth of degrees

    degrees = int(input())
    time = 0
    time_to_degree = 0
    while degrees != time_to_degree:
        time += 1
        time_to_degree = (time * DEGREE_PER_MIN) % 3600
        if time > 720:
            break
    hours = round(time/60)
    if hours == 0:
        hours = 12
    print(f"{hours:02}:{time % 60:02}") 



if __name__ == "__main__":
    main()


