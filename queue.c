#include "queue.h"
#include "tile_game.h"

int match_maze(uint8_t tiles1[4][4], uint8 tiles2[4][4]);
struct 

void enqueue(struct queue *q, struct game_state state) {
	insert_at_head(&(q->data), serialize(state));
	return;
}

struct game_state dequeue(struct queue *q) { 
	size_t temp = remove_from_tail(&(q->data));
	return (deserialize(temp)); 
}

int match_maze(uint8_t tiles1[4][4], uint8_t tiles2[4][4]){
	int out = 1;
	int i;
	int j;
	for(i = 0; i<4; i++){
		for(j = 0; j<4; j++){
			if(tiles1[i][j] != tiles2[i][j]){
				out = 0;
			}
		}
	}
	return out;
}



struct game_state copy_state(struct game_state state){
	struct game_state out = state;
	return out;
}


int number_of_moves(struct game_state start) { 
	uint8_t final[4][4];
	int i;
	int j;
	int ct = 1;
	for(i = 0; i < 4; i++){
		for (j = 0; j < 4; j++;){
			final[i][j] = ct;
			ct ++;
		}
	}
	final[3][3] = 0;
	struct queue q;
	enqueue(&q, start);
	while(q -> data.head != NULL){
		struct game_state curr;
		curr = dequeue(&q);
		if(match_maze(final, curr) == 1){
			return curr.num_steps;
		}
		for(i = 0; i<4; i++){
			struct game_state next = copy_state(curr);
			if(i == 0){
				move_up(next);
				enqueue(&q, next);
			}
			if(i ==1){
				move_down(next);
				enqueue(&q, next);
			}
			if(i ==2){
				move_left(next);
				enqueue(&q, next);
			}
			if(i ==3){
				move_right(next);
				enqueue(&q, next);
			}
		}
	}
	return 0; 
}
