
def vacuum_cleaner(location, room_a, room_b):

    print("\nInitial State:")
    print("Vacuum Location:", location)
    print("Room A:", room_a)
    print("Room B:", room_b)

    step = 1

    while room_a == "Dirty" or room_b == "Dirty":

        print("\nStep", step)

        if location == "A":

            if room_a == "Dirty":
                print("Action: SUCK")
                room_a = "Clean"

            else:
                print("Action: MOVE RIGHT")
                location = "B"

        else:

            if room_b == "Dirty":
                print("Action: SUCK")
                room_b = "Clean"

            else:
                print("Action: MOVE LEFT")
                location = "A"

        print("Vacuum Location:", location)
        print("Room A:", room_a)
        print("Room B:", room_b)

        step += 1

    print("\nGoal State Reached!")
    print("Both rooms are clean.")
    print("Vacuum Location:", location)

location = input("Enter vacuum location (A/B): ").upper()
room_a = input("Enter Room A status (Clean/Dirty): ").capitalize()
room_b = input("Enter Room B status (Clean/Dirty): ").capitalize()

vacuum_cleaner(location, room_a, room_b)
