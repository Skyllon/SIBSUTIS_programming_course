#include "../include/fioaccount.h"

static ACCOUNT *rand_gen_struct(void) {
  ACCOUNT *acc = (ACCOUNT *)malloc(sizeof(ACCOUNT));
  if (!acc) return NULL;

  snprintf(acc->identifier, IDENTIFIER_LIMIT, "ID%04d", rand() % 10000);
  acc->identifier[IDENTIFIER_LIMIT - 1] = '\0';

  snprintf(acc->card_number, CARD_NUMBER_LIMIT, "%04d%04d%04d", rand() % 10000,
           rand() % 10000, rand() % 10000);
  acc->card_number[CARD_NUMBER_LIMIT - 1] = '\0';

  const char *currencies[] = {"RUB", "USD", "EUR"};
  strncpy(acc->currency, currencies[rand() % 3], CURRENCY_NAME_LIMIT);
  acc->currency[CURRENCY_NAME_LIMIT - 1] = '\0';

  const char *types[] = {DEBIT, CREDIT};
  strncpy(acc->card_type, types[rand() % 2], CARD_TYPE_LIMIT);
  acc->card_type[CARD_TYPE_LIMIT - 1] = '\0';

  acc->balance = (double)(rand() % 1000000) / 10.0;
  time_t t = time(NULL);
  struct tm *tm = localtime(&t);
  acc->open_date.day = tm->tm_mday;
  acc->open_date.month = tm->tm_mon + 1;
  acc->open_date.year = tm->tm_year + 1900;
  acc->close_date = acc->open_date;
  acc->close_date.year += 6;
  acc->bank_cell = NULL;
  acc->cell = NULL;

  return acc;
}

void rand_gen_struct_in_container(DblList *container, size_t n) {
  if (!container) return;
  srand(time(NULL));

  for (size_t i = 0; i < n; ++i) {
    ACCOUNT *acc = rand_gen_struct();

    if (acc) bPush(container, (intptr_t)acc);
  }
}

static void save_text(DblList *list, FILE *file) {
  if (!list || !file) return;
  Node *curr = list->Head;

  while (curr) {
    ACCOUNT *acc = (ACCOUNT *)(intptr_t)curr->Data;
    if (!acc) {
      fprintf(stderr, "Обнаружен пустой элемент в списке\n");
      curr = curr->Next;
      continue;
    }

    fprintf(file, "%s,%s,%s,%s,%.2lf,%d.%d.%d\n", acc->identifier,
            acc->card_number, acc->currency, acc->card_type, acc->balance,
            acc->open_date.day, acc->open_date.month, acc->open_date.year);

    fflush(file);
    curr = curr->Next;
  }
}

static DblList *load_text(FILE *file) {
  DblList *list = createList();
  if (!list) return NULL;

  char line[512];
  while (fgets(line, sizeof(line), file)) {
    ACCOUNT acc = {0};
    intptr_t day, month, year;
    day = month = year = NULL;

    if (sscanf(line, "%30[^,],%15[^,],%20[^,],%15[^,],%lf,%ld.%ld.%ld",
               acc.identifier, acc.card_number, acc.currency, acc.card_type,
               &acc.balance, &day, &month, &year) != 8) {
      continue;
    }

    acc.open_date.day = day;
    acc.open_date.month = month;
    acc.open_date.year = year;
    acc.close_date = acc.open_date;
    acc.close_date.year += 6;

    ACCOUNT *new_acc = CreateAccount(acc.identifier, acc.card_number,
                                     acc.currency, acc.card_type, acc.balance);
    if (!new_acc) continue;

    new_acc->open_date = acc.open_date;
    new_acc->close_date = acc.close_date;
    bPush(list, (intptr_t)new_acc);
    fflush(file);
  }

  if (ferror(file)) {
    perror("Ошибка чтения текстового файла");
    clear(list);
    fList(list);
    return NULL;
  }

  return list;
}

ACCOUNT *get_element_from_text_file(const char *filename, intptr_t idx) {
  FILE *fp = fopen(filename, "r");
  if (!fp) return NULL;

  ACCOUNT *acc = NULL;
  char line[512];
  intptr_t current = 0;

  while (fgets(line, sizeof(line), fp)) {
    if (current++ == idx) {
      acc = (ACCOUNT *)malloc(sizeof(ACCOUNT));
      if (!acc) break;

      intptr_t day, month, year;
      if (sscanf(line, "%[^,],%[^,],%[^,],%[^,],%lf,%ld.%ld.%ld",
                 acc->identifier, acc->card_number, acc->currency,
                 acc->card_type, &acc->balance, &day, &month, &year) == 8) {
        acc->open_date.day = day;
        acc->open_date.month = month;
        acc->open_date.year = year;
        acc->close_date = acc->open_date;
        acc->close_date.year += 6;
      } else {
        free(acc);
        acc = NULL;
      }
      break;
    }
  }

  fclose(fp);
  return acc;
}

static void save_binary(DblList *list, FILE *file) {
  Node *curr = list->Head;

  while (curr) {
    ACCOUNT *acc = (ACCOUNT *)(intptr_t)curr->Data;

    if (!acc) {
      fprintf(stderr, "Пустой элемент!\n");
      curr = curr->Next;
      continue;
    }

    ACCOUNT acc_copy = *acc;
    acc->bank_cell = NULL;
    acc->cell = NULL;

    if (fwrite(&acc_copy, sizeof(ACCOUNT), 1, file) != 1) {
      perror("Ошибка записи");
      break;
    }

    fflush(file);
    curr = curr->Next;
  }
}

static DblList *load_binary(FILE *file) {
  DblList *list = createList();
  if (!list) return NULL;

  fseek(file, 0, SEEK_END);
  long size = ftell(file);
  rewind(file);

  if (size % sizeof(ACCOUNT) != 0) {
    fprintf(stderr, "Некорректный размер файла\n");
    fList(list);
    return NULL;
  }

  size_t count = size / sizeof(ACCOUNT);
  for (size_t i = 0; i < count; i++) {
    ACCOUNT acc;
    if (fread(&acc, sizeof(ACCOUNT), 1, file) != 1) {
      if (feof(file)) break;
      perror("Ошибка чтения бинарного файла");
      break;
    }

    ACCOUNT *new_acc = CreateAccount(acc.identifier, acc.card_number,
                                     acc.currency, acc.card_type, acc.balance);
    if (!new_acc) continue;

    new_acc->open_date = acc.open_date;
    new_acc->close_date = acc.close_date;
    bPush(list, (intptr_t)new_acc);
  }

  return list;
}

void save_accounts(const char *filename, DblList *list, FileMode mode) {
  FILE *file =
      (mode == BINARY_MODE) ? fopen(filename, "wb") : fopen(filename, "w");
  if (!file) {
    perror("Ошибка открытия файла");
    return;
  }

  if (mode == BINARY_MODE) {
    save_binary(list, file);
  } else {
    save_text(list, file);
  }

  fflush(file);
  fclose(file);
}

DblList *load_accounts(const char *filename, FileMode mode) {
  if (!filename) return NULL;

  FILE *file =
      (mode == BINARY_MODE) ? fopen(filename, "rb") : fopen(filename, "r");
  if (!file) {
    perror("Ошибка открытия файла");
    return NULL;
  }

  DblList *list = (mode == BINARY_MODE) ? load_binary(file) : load_text(file);
  fclose(file);

  return list;
}

size_t count_in_file(const char *filename, FileMode mode) {
  FILE *file =
      (mode == TEXT_MODE) ? fopen(filename, "r") : fopen(filename, "rb");
  if (!file) return NULL;

  size_t count = 0;
  if (mode == TEXT_MODE) {
    char buf[256];
    while (fgets(buf, sizeof(buf), file)) count++;
  } else {
    fseek(file, 0, SEEK_END);
    count = ftell(file) / sizeof(ACCOUNT);
  }
  fclose(file);
  return count;
}

ACCOUNT *get_element_from_file(const char *filename, intptr_t index,
                               FileMode mode) {
  if (!filename || index < 0) return NULL;

  if (mode == BINARY_MODE) {
    FILE *file = fopen(filename, "rb");
    if (!file) return NULL;

    ACCOUNT *acc = (ACCOUNT *)malloc(sizeof(ACCOUNT));
    if (!acc) {
      fclose(file);
      return NULL;
    }

    if (fseek(file, index * sizeof(ACCOUNT), SEEK_SET) != 0 ||
        fread(acc, sizeof(ACCOUNT), 1, file) != 1) {
      free(acc);
      acc = NULL;
    }

    fclose(file);
    return acc;
  } else {
    return get_element_from_text_file(filename, index);
  }
}
