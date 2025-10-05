#include <stdio.h>

#include "../include/fioaccount.h"
#include "../include/liststruct.h"

void print_account(const ACCOUNT *acc) {
  if (!acc) return;
  printf(
      "ID: %s\nНомер: %s\nВалюта: %s\nТип: %s\nБаланс: %.2lf\nДата: "
      "%d.%d.%d\n\n",
      acc->identifier, acc->card_number, acc->currency, acc->card_type,
      acc->balance, acc->open_date.day, acc->open_date.month,
      acc->open_date.year);
}

int main(int argc, char *argv[]) {
  FileMode mode =
      (argc > 3 && strcmp(argv[3], "binary") == 0) ? BINARY_MODE : TEXT_MODE;

  if (strcmp(argv[1], "save") == 0) {
    DblList *list = createList();
    if (!list) {
      fprintf(stderr, "Ошибка создания списка\n");
      return 1;
    }

    rand_gen_struct_in_container(list, 10000);
    save_accounts(argv[2], list, mode);

    clear(list);
    fList(list);

  } else if (strcmp(argv[1], "load") == 0) {
    DblList *list = load_accounts(argv[2], mode);

    if (list) {
      Node *curr = list->Head;

      while (curr) {
        print_account((ACCOUNT *)(intptr_t)curr->Data);
        curr = curr->Next;
      }

      clear(list);
      fList(list);
    }
  } else if (strcmp(argv[1], "list") == 0) {
    size_t cnt = count_in_file(argv[2], mode);
    printf("Кол-во элементов в файле: %ld", cnt);
  } else if (strcmp(argv[1], "get") == 0) {
    int idx = atoi(argv[2]);
    ACCOUNT *acc = get_element_from_file(argv[3], idx, mode);

    print_account(acc);
    free(acc);
  }

  return EXIT_SUCCESS;
}
