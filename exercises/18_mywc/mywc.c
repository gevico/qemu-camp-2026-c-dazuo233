#include "mywc.h"

WordCount **create_hash_table() {
  WordCount **hash_table = calloc(HASH_SIZE, sizeof(WordCount *));
  return hash_table;
}

unsigned int hash(const char *word) {
  unsigned long h = 5381;
  int c;
  while ((c = *word++))
    h = ((h << 5) + h) + c;
  return h % HASH_SIZE;
}

bool is_valid_word_char(char c) { return isalpha(c) || c == '\''; }

char to_lower(char c) { return tolower(c); }

void add_word(WordCount **hash_table, const char *word) {
    unsigned int index = hash(word);
    WordCount *entry = hash_table[index];

    while (entry != NULL) {
        if (strcmp(entry->word, word) == 0) {
            entry->count++;
            return;
        }
        entry = entry->next;
    }

    WordCount *new_entry = malloc(sizeof(WordCount));
    strncpy(new_entry->word, word, MAX_WORD_LEN - 1);
    new_entry->word[MAX_WORD_LEN - 1] = '\0';
    new_entry->count = 1;
    new_entry->next = hash_table[index];
    hash_table[index] = new_entry;
}

void print_word_counts(WordCount **hash_table) {
  printf("Word Count Statistics:\n");
  printf("======================\n");

    WordCount *all[10000];
    int total = 0;

    for (int i = 0; i < HASH_SIZE; i++) {
        WordCount *entry = hash_table[i];
        while (entry != NULL) {
            all[total++] = entry;
            entry = entry->next;
        }
    }

    for (int i = 0; i < total - 1; i++) {
        for (int j = i + 1; j < total; j++) {
            if (all[j]->count > all[i]->count) {
                WordCount *tmp = all[i];
                all[i] = all[j];
                all[j] = tmp;
            }
        }
    }

    for (int i = 0; i < total; i++) {
        printf("%-21s%d\n", all[i]->word, all[i]->count);
    }
}

void free_hash_table(WordCount **hash_table) {
    for (int i = 0; i < HASH_SIZE; i++) {
        WordCount *entry = hash_table[i];
        while (entry != NULL) {
            WordCount *temp = entry;
            entry = entry->next;
            free(temp);
        }
    }
    free(hash_table);
}

void process_file(const char *filename) {
  FILE *file = fopen(filename, "r");
  if (!file) {
    perror("Error opening file");
    exit(EXIT_FAILURE);
  }

  WordCount **hash_table = create_hash_table();
  char word[MAX_WORD_LEN];
  int word_pos = 0;
  int c;

  while ((c = fgetc(file)) != EOF) {
    if (is_valid_word_char(c)) {
      if (word_pos < MAX_WORD_LEN - 1) {
        word[word_pos++] = to_lower(c);
      }
    } else {
      if (word_pos > 0) {
        word[word_pos] = '\0';
        add_word(hash_table, word);
        word_pos = 0;
      }
    }
  }

  if (word_pos > 0) {
    word[word_pos] = '\0';
    add_word(hash_table, word);
  }

  fclose(file);
  print_word_counts(hash_table);
  free_hash_table(hash_table);
}
