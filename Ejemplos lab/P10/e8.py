def variable_lenghth(**kwargs):
    print(f"{len(kwargs)} data structures and their operations:")
    for title, name in kwargs.items():
        print(f"\t{title}->{name}")

variable_lenghth(stack="pop, push", queue="enqueue, dequeueu", list="add, delete")