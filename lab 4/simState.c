#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

#define STATES 8

// 2D array with 8 rows, 2 columns
char state_machine[STATES][2];
char states[] = "ABCDEFGH";
char current_state = 'D';
// Boolean array keeping track of what states are deleted
bool deleted[STATES];

// Function to find index of a state
int getstate_index(char state) {
    return strchr(states, state) - states;
}

// Function to print out current state machine configuration
void print_state_machine() {
    // for loop will take values 1-7
    for (int i = 0; i < STATES; i++) {
        if (!deleted[i]) {
            printf("%c %c %c\n", states[i], state_machine[i][0], state_machine[i][1]);
        }
    }
}

// Initialize state machine based on the input configs
void initialize_state_machine() {
    state_machine[0][0] = 'G'; state_machine[0][1] = 'D';
    state_machine[1][0] = 'A'; state_machine[1][1] = 'F';
    state_machine[2][0] = 'D'; state_machine[2][1] = 'E';
    state_machine[3][0] = 'E'; state_machine[3][1] = 'H';
    state_machine[4][0] = 'B'; state_machine[4][1] = 'A';
    state_machine[5][0] = 'F'; state_machine[5][1] = 'C';
    state_machine[6][0] = 'H'; state_machine[6][1] = 'B';
    state_machine[7][0] = 'F'; state_machine[7][1] = 'G';

    // initialize all states as not deleted by using the 'deleted' array
    for (int i = 0; i < STATES; i++) {
        deleted[i] = false;
    }
}

// function marking reachable states by checking all reachable values
void mark_reachable(int index, bool reachable[]) {
    if (reachable[index] || deleted[index]) return;
    reachable[index] = true;

    int next0 = getstate_index(state_machine[index][0]);
    int next1 = getstate_index(state_machine[index][1]);

    mark_reachable(next0, reachable);
    mark_reachable(next1, reachable);
}

// Function to identify and print garbage states
void identify_garbage() {
    bool reachable[STATES] = {false};
    mark_reachable(getstate_index(current_state), reachable);

    bool garbage_found = false;

    for (int i = 0; i < STATES; i++) {
        if (!reachable[i] && !deleted[i]) {
            if (!garbage_found) {
                printf("Garbage: ");
                garbage_found = true;
            }
            printf("%c ", states[i]);
        }
    }
    if (!garbage_found) {
        printf("No garbage");
    }
    printf("\n");
}

void delete_states(char* arg) {
    if (arg == NULL) {
        // deleting unreachable states
        bool reachable[STATES] = {false};
        mark_reachable(getstate_index(current_state), reachable);

        bool any_deleted = false;
        for (int i = 0; i < STATES; i++) {
            if (!reachable[i] && !deleted[i]) {
                deleted[i] = true;

                if (!any_deleted) {
                    printf("Deleted: ");
                    any_deleted = true;
                }

                printf("%c ", states[i]);
            }

        }

        if (!any_deleted) {
            printf("No states deleted.");
        }
        printf("\n");
    } else {
        // Delete specific state if it is valid
        int idx = getstate_index(arg[0]);
        if (idx >= 0 && idx < STATES && !deleted[idx]) {
            deleted[idx] = true;
            printf("Deleted.\n");
        } else {
            printf("Not deleted.\n");
        }
    }
}

int main(int argc, char *argv[]) {
    initialize_state_machine();
    printf("Starting state: %c\n", current_state);

    char command[10];
    while (scanf("%s", command) != EOF) {
        if (strcmp(command, "0") == 0) {
            current_state = state_machine[getstate_index(current_state)][0];
            printf("%c\n", current_state);
        } else if (strcmp(command, "1") == 0) {
            current_state = state_machine[getstate_index(current_state)][1];
            printf("%c\n", current_state);
        } else if (command[0] == 'c' && strlen(command) == 4) {
            // Ensure command format is 'c <input> <state>'
            int input = command[1] - '0';
            char new_state = command[2];
            if (input == 0 || input == 1) {
                state_machine[getstate_index(current_state)][input] = new_state;
            }
        } else if (strcmp(command, "p") == 0) {
            print_state_machine();
        } else if (strcmp(command, "g") == 0) {
            identify_garbage();
        } else if (command[0] == 'd') {
            if (strlen(command) > 1) {
                delete_states(&command[1]);
            } else {
                delete_states(NULL);
            }
        }
    }

    return 0;
}
