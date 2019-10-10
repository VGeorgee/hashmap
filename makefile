SRCS = main.c HashArray.c LinkedList.c
OBJS = $(SRCS:%.c=%.o)
TARGETS = main
.PHONY: clean
all: $(TARGETS)
main: $(OBJS)
$(CC) $(OBJS) -o main
%.o: %.c
$(CC) -Wall -c $< -o $@
clean:
rm -rf $(OBJS) *~ $(TARGETS)
