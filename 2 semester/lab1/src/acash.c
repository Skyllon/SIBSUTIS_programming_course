#include "../include/acash.h"  // Подключаем заголовочный файл

ACCOUNT *CreateAccount(const char *identifier, const char *card_number,
                       const char *currency, const char *card_type,
                       const double balance) {
  // Динамическое выделение памяти для всей структуры
  ACCOUNT *account = (ACCOUNT *)malloc(sizeof(ACCOUNT));

  // Инициализация полей структуры
  strncpy(account->identifier, identifier, sizeof(account->identifier) - 1);
  strncpy(account->card_number, card_number, sizeof(account->card_number) - 1);
  strncpy(account->currency, currency, sizeof(account->currency) - 1);
  strncpy(account->card_type, card_type, sizeof(account->card_type) - 1);
  account->balance = balance;

  // Дата откртия (берется текущая дата с помощью <time.h>)
  time_t my_time = time(NULL);
  struct tm current_time = *localtime(&my_time);
  account->open_date.day = current_time.tm_mday;
  account->open_date.month = current_time.tm_mon + 1;
  account->open_date.year = current_time.tm_year + 1900;

  // Дата закрытия (+6 лет к дате откртия)
  account->close_date.day = account->open_date.day;
  account->close_date.month = account->open_date.month;
  account->close_date.year = account->open_date.year + 6;

  return account;
}

void AccountInfo(const ACCOUNT *account) {
  printf(
      "Вы хотите вывести все данные о карте или только определенные детали?\n"
      "1 - Вывести всю информацию о карте.\n"
      "2 - Вывести определенную информацию.\n");

  short choice;
  do {
    printf("Введите ваш выбор (1 или 2): ");

    if (scanf("%hu", &choice) != 1) {
      // Очищаем буфер ввода
      while (getchar() != '\n');
      printf("Ошибка! Введите число!\n");
      choice = 0;
    } else {
      // Если ввод успешен, проверяем диапазон
      if (choice < 1 || choice > 2) printf("Ошибка! Выберите 1 или 2.\n");
    }
  } while (choice < 1 || choice > 2);

  // Вывод всех данных или отдельной информации
  if (choice == 1) {
    printf("Идентификатор: %s\n", account->identifier);
    printf("Номер карты: %s\n", account->card_number);
    printf("Валюта: %s\n", account->currency);
    printf("Тип карты: %s\n", account->card_type);
    printf("Баланс: %.2lf\n\n", account->balance);
  } else {
    printf(
        "Какую информацию о вашей расчетной карте вы хотели бы узнать?\n"
        "1. Идентификатор\n"
        "2. Номер карты\n"
        "3. Валюта\n"
        "4. Тип карты\n"
        "5. Баланс\n"
        "6. Информация о ячейке\n");

    do {
      printf("Введите ваш выбор (1-5): ");

      if (scanf("%hu", &choice) != 1) {
        // Очищаем буфер ввода
        while (getchar() != '\n');
        printf("Ошибка! Введите число!\n");
        choice = 0;
      } else if (choice < 1 || choice > 5)
        printf("Ошибка! Выберите число от 1 до 5.\n");
    } while (choice < 1 || choice > 5);

    switch (choice) {
      case 1:
        printf("Идентификатор: %s\n", account->identifier);
        break;
      case 2:
        printf("Номер карты: %s\n", account->card_number);
        break;
      case 3:
        printf("Валюта: %s\n", account->currency);
        break;
      case 4:
        printf("Тип карты: %s\n", account->card_type);
        break;
      case 5:
        printf("Баланс: %.2lf\n\n", account->balance);
        break;
        // case 6:
        //   cellB *cell = GetBankCell(account);
        //   if (cell) {
        //     // printf("ID: %u\n", get_id(cell));
        //     // printf("Размер: %hu\n", get_size(cell));
        //   }
        break;
    }
  }
}

void CompareTwoCards(const ACCOUNT *first_card, const ACCOUNT *second_card) {
  printf(
      "Первая карта имеет идентификатор: %s\n"
      "Вторая карта имеет идентификатор: %s\n\n",
      first_card->identifier, second_card->identifier);

  // Сравнение баланса
  if (first_card->balance > second_card->balance)
    printf("Баланс первой карты больше баланса второй (1: %.2lf, 2: %.2lf)\n",
           first_card->balance, second_card->balance);
  else if (first_card->balance < second_card->balance)
    printf("Баланс первой карты меньше баланса второй (1: %.2lf, 2: %.2lf)\n",
           first_card->balance, second_card->balance);
  else
    printf("Балансы на двух картах эквивалентны (1; %.2lf, 2: %.2lf)\n",
           first_card->balance, second_card->balance);

  // Сравнение по датам открытия/закрытия
  if (first_card->open_date.year == second_card->open_date.year &&
      first_card->open_date.day == second_card->open_date.day &&
      first_card->open_date.month == second_card->open_date.month) {
    printf("Обе карты были открыты в одно время!\n");
    printf("(%s) Дата открытия: %d.%d.%d\n", first_card->identifier,
           first_card->open_date.day, first_card->open_date.month,
           first_card->open_date.year);
    printf("(%s) Дата закрытия: %d.%d.%d\n", second_card->identifier,
           second_card->open_date.day, second_card->open_date.month,
           second_card->open_date.year);
  } else {
    printf("Карты имеют разную дату открытия и закрытия.\n");

    // Первая карта
    printf("Идентификатор: %s\n", first_card->identifier);
    printf("Дата открытия карты: %d.%d.%d\n", first_card->open_date.day,
           first_card->open_date.month, first_card->open_date.year);
    printf("Дата закрытия карты: %d.%d.%d\n\n", first_card->close_date.day,
           first_card->close_date.month, first_card->close_date.year);

    // Вторая карта
    printf("Идентификатор: %s", second_card->identifier);
    printf("Дата открытия карты: %d.%d.%d\n", second_card->open_date.day,
           second_card->open_date.month, second_card->open_date.year);
    printf("Дата закрытия карты: %d.%d.%d\n\n", second_card->close_date.day,
           second_card->close_date.month, second_card->close_date.year);
  }

  // Сравнение по типу карт
  if (strcmp(first_card->card_type, second_card->card_type) == 0)
    printf("Обе карты имеют одинаковый тип: %s", first_card->card_type);
  else {
    printf("Идентификатор: %s, тип: %s\n", first_card->identifier,
           first_card->card_type);
    printf("идентификатор: %s, тип: %s\n\n", second_card->identifier,
           second_card->card_type);
  }
}

void DepositAccount(ACCOUNT *account, const double sum_to_deposit) {
  // Проверяем чтобы была введена положительная сумма внесения
  if (sum_to_deposit <= 0) {
    printf("Ошибка! Сумма для внесения должна быть положительной!\n");
    exit(-1);
  }

  // Добавляем сумму внесения и отображаем баланс
  account->balance += sum_to_deposit;
  printf("Внесено: %.2lf%s\n", sum_to_deposit, account->currency);
  printf("Текущий баланс: %.2lf%s\n\n", account->balance, account->currency);
}

void WithdrawMoney(ACCOUNT *account, const double sum_to_withdraw) {
  // Проверка чтобы была введена положительная сумма снятия
  if (sum_to_withdraw <= 0) {
    printf("Ошибка! Сумма для внесения должна быть положительной!\n");
    exit(-1);
  }

  // Если карта кредитная, то проверить не превысили ли нижний порог
  if (strcmp(account->card_type, CREDIT) == 0) {
    if (account->balance - sum_to_withdraw < NEGATIVE_CREDIT_FIXED) {
      printf(
          "Вы не можете снять деньги, потому что превысили "
          "максимально отрицательный порог!\n");
      exit(-1);
    } else {
      account->balance -= sum_to_withdraw;

      // Отображаем баланс
      printf("Снято: %.2lf%s\n", sum_to_withdraw, account->currency);
      printf("Текущий баланс: %.2lf%s\n\n", account->balance,
             account->currency);
      exit(0);
    }
  } else {  // Дебетовая карта
    // Проверка достаточно ли средств, чтобы снять деньги
    if (account->balance > sum_to_withdraw) {
      account->balance -= sum_to_withdraw;

      // Отображаем баланс
      printf("Снято: %.2lf%s\n", sum_to_withdraw, account->currency);
      printf("Текущий баланс: %.2lf%s\n\n", account->balance,
             account->currency);
    } else {
      printf("На вашем счете недостаточно денег.\n");
      exit(-1);
    }
  }
}

void WithdrawPercentage(ACCOUNT *account, double percentage) {
  if (percentage < 0 || percentage > 100) {
    printf("Ошибка: процент должен быть от 0 до 100.\n");
    exit(-1);
  }

  double amount = (account->balance * percentage) / 100.0;
  if (strcmp(account->card_type, CREDIT) == 0) {
    account->balance -= amount;

    // Отображаем баланс
    printf("Снято: %.2lf%% %.2lf %s)\n", percentage, account->balance,
           account->currency);
    printf("Текущий баланс: %.2lf%s\n\n", account->balance, account->currency);
  } else if (account->balance >= amount) {
    account->balance -= amount;
    printf("Снято:  %.2f%% (%.2f %s)", percentage, amount, account->currency);
    printf("Текущий баланс: %.2lf %s", account->balance, account->currency);
  } else
    printf("Ошибка: недостаточно средств.\n");
}

void DepositPercentage(ACCOUNT *account, double percentage) {
  if (percentage < 0 || percentage > 100) {
    printf("Ошибка: процент должен быть от 0 до 100.\n");
    exit(-1);
  }

  double amount = (account->balance * percentage) / 100.0;
  account->balance += amount;
  printf("Deposited %.2f%% (%.2f %s). New balance: %.2f %s\n", percentage,
         amount, account->currency, account->balance, account->currency);
}

void Transfer(ACCOUNT *source_card, ACCOUNT *destination_card,
              const double amount, const double commission_rate) {
  if (amount <= 0) {
    printf("Ошибка: сума должна быть положительным числом\n");
    exit(-1);
  }

  // Валюта разная
  if (strcmp(source_card->currency, destination_card->currency) == 0) {
    double commission = amount * commission_rate;
    if (source_card->balance < amount + commission) {
      printf("Ошибка: не хватает денег для совершения перевода!\n");
      exit(-1);
    }

    source_card->balance -= (amount + commission);  // Снимаем с комиссией
    destination_card->balance += amount;  // Совершаем перевод на другую карту
    printf("Переведено: %.2lf %s с комиссией %.2lf %s\n", amount,
           source_card->currency, commission, source_card->currency);
  } else {
    // Если валюты одинаковые, то перевод без комиссии
    if (source_card->balance < amount) {
      printf("Ошибка: недостаточно средств для перевода!\n");
      exit(-1);
    }
    source_card->balance -= amount;
    destination_card->balance += amount;
    printf("Переведено: %.2lf %s", amount, source_card->currency);
  }
}

int IsAccountClosed(const ACCOUNT *account) {
  time_t my_time = time(NULL);
  struct tm current_time = *localtime(&my_time);
  int current_year = current_time.tm_year + 1990,
      current_day = current_time.tm_mday,
      current_month = current_time.tm_mon + 1;

  // Если срок службы просрочен - карта закрыта
  if (current_year > account->close_date.year) return 1;
  if (current_year == account->close_date.year &&
      current_month > account->close_date.month)
    return 1;
  if (current_year == account->close_date.year &&
      current_month == account->close_date.month &&
      current_day >= account->close_date.day)
    return 1;
  return 0;
}

void GetBonuses(BONUSES *bonuses, const double amount) {
  if (!bonuses || amount <= 0) return;

  double accrued = amount * bonuses->profit_percent;
  bonuses->current_balance += accrued;
  printf("Начислено:%.2f бонусов.\nВсего бонусов: %.2f\n", accrued,
         bonuses->current_balance);
}

double UseBonuses(BONUSES *bonuses, const double max_amount) {
  if (!bonuses || max_amount <= 0) return 0.0;

  double used = (bonuses->current_balance >= max_amount)
                    ? max_amount
                    : bonuses->current_balance;
  bonuses->current_balance -= used;
  printf("Использовано %.2f бонусов.\nТекущий баланс: %.2f\n", used,
         bonuses->current_balance);
  return used;
}

void DepositWithBonuses(ACCOUNT *account, BONUSES *bonuses,
                        const double amount) {
  if (amount <= 0) {
    printf("Ошибка: сумма должна быть положительным числом.\n");
    exit(-1);
  }

  account->balance += amount;
  printf("Внесено %.2f %s.\nТекущий баланс: %.2f %s\n", amount,
         account->currency, account->balance, account->currency);

  // Начисление бонусов
  if (bonuses) GetBonuses(bonuses, amount);
}

void WithdrawWithBonuses(ACCOUNT *account, BONUSES *bonuses,
                         const double amount) {
  if (amount <= 0) {
    printf("Ошибка: сумма должна быть положительным числом.\n");
    return;
  }

  if (strcmp(account->card_type, CREDIT) == 0) {
    // Для кредитной карты разрешен отрицательный баланс
    double bonus_coverage =
        UseBonuses(bonuses, amount);  // Использование бонусов
    double remaining = amount - bonus_coverage;

    // Если счет больше, чем порог отрицального значения для кредитной карты -
    // снимаем
    if (!(account->balance <= NEGATIVE_CREDIT_FIXED))
      account->balance -= remaining;

    printf(
        "Списано %.2f %s (использовано %.2f бонусов).\nТекущий баланс: "
        "%.2f %s\n",
        amount, account->currency, bonus_coverage, account->balance,
        account->currency);
  } else if (account->balance >= amount) {
    // Для дебетовой и эскроу карт проверяем баланс
    double bonus_coverage =
        UseBonuses(bonuses, amount);  // Использование бонусов
    double remaining = amount - bonus_coverage;

    account->balance -= remaining;
    printf(
        "Списано %.2f %s (использовано %.2f бонусов).\nТекущий баланс:: "
        "%.2f %s\n",
        amount, account->currency, bonus_coverage, account->balance,
        account->currency);
  } else
    printf("Ошибка: недостаточно средств.\n");
}
