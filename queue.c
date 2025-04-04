#include "queue.h"
#include "tile_game.h"

void enqueue(struct queue *q, struct game_state state) {
	insert_at_head(&(q->data), serialize(state));
	return;
}

struct game_state dequeue(struct queue *q) { 
	size_t temp = remove_from_tail(&(q->data));
	return (deserialize(temp)); 
}

int number_of_moves(struct game_state start) { 
	return 0; 
}
