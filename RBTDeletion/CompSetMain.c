#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#include "Set.h"

int nextKey(const int MAX_VAL_KEY) {
  return random() % MAX_VAL_KEY + 1;
}

int main(int argc, char** argv) {
  if (argc != 3) {
    fprintf(stderr, "Syntax: %s <max_num_keys> <max_val_key>\n", argv[0]);
    return 1;
  } else {
    clock_t start, end;
    const int MAX_NUM_KEYS = atoi(argv[1]);
    const int MAX_VAL_KEY = atoi(argv[2]);
    Set s;

    start = clock();
    //
    // Initialize the Set datatype:
    initialize(&s);
    //
    // Insert elements in the set:
    for (int i = 0; i < MAX_NUM_KEYS; i++) {
      int key = nextKey(MAX_VAL_KEY);
      insert(s, key);
    }
    printf("Done Inserting\n");
    //
    // Search for elements in the set:
    int num_hits = 0;
    for (int i = 0; i < MAX_NUM_KEYS; i++) {
      if (contains(s, i))
        num_hits++;
    }
    printf("Done Searching\n");
    //
    // Close the set:
    close(s);
    //
    // Print final result: time and number of elements found:
    end = clock();
    fprintf(stderr, "Time = %lf\n", ((double)(end - start))/CLOCKS_PER_SEC);
    printf("Number of hits = %d\n", num_hits);
  }
}
