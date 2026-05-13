import statistics

numbers = list(map(float, input("Введите числа через пробел: ").split()))

if not numbers:
    print("Массив пуст.")
else:
    mean_value = statistics.mean(numbers)
    median_value = statistics.median(numbers)
    modes = statistics.multimode(numbers)
    variance_value = statistics.pvariance(numbers)
    std_dev_value = statistics.pstdev(numbers)

    print(f"Среднее: {mean_value}")
    print(f"Медиана: {median_value}")

    if len(modes) == 1:
        print(f"Мода: {modes[0]}")
    else:
        print("Мода:", *modes)

    print(f"Дисперсия: {variance_value}")
    print(f"Стандартное отклонение: {std_dev_value}")