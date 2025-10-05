#include "../include/liststruct.h"

#include "../include/acash.h"

DblList *createList(void) {
  DblList *List = (DblList *)malloc(sizeof(DblList));
  if (List) {
    List->Head = NULL;
    List->Tail = NULL;
    List->ElemSize = 0;
  }

  return List;
}

bool isEmpty(DblList *List) { return List->ElemSize == 0; }

void fPush(DblList *List, const intptr_t Value) {
  Node *Nod = (Node *)malloc(sizeof(Node));

  if (Nod) {
    Nod->Data = Value;
    Nod->Next = List->Head;
    Nod->Prev = NULL;

    if (isEmpty(List))
      List->Tail = Nod;
    else
      List->Head->Prev = Nod;

    List->Head = Nod;
    List->ElemSize++;
  }
}

void bPush(DblList *List, const intptr_t Value) {
  if (!List) {
    printf("Ошибка: список не инициализирован.\n");
    return;
  }

  Node *Nod = (Node *)malloc(sizeof(Node));
  if (!Nod) {
    fprintf(stderr, "Ошибка выделения памяти для узла.\n");
    return;
  }

  Nod->Data = Value;
  Nod->Next = NULL;
  Nod->Prev = List->Tail;

  if (isEmpty(List)) {
    // Если список пуст, обновляем Head и Tail
    List->Head = Nod;
    List->Tail = Nod;
  } else {
    // Иначе связываем текущий Tail с новым узлом
    List->Tail->Next = Nod;
    List->Tail = Nod;
  }

  List->ElemSize++;
}

intptr_t fPop(DblList *List) {
  if (isEmpty(List)) return -1;

  Node *Temp = List->Head;
  intptr_t value = Temp->Data;
  List->Head = List->Head->Next;

  if (List->Head)
    List->Head->Prev = NULL;
  else
    List->Tail = NULL;

  free(Temp);
  List->ElemSize--;

  return value;
}

intptr_t bPop(DblList *List) {
  if (isEmpty(List)) return -1;

  Node *Temp = List->Tail;
  intptr_t value = Temp->Data;
  List->Tail = List->Tail->Prev;

  if (List->Tail)
    List->Tail->Next = NULL;
  else
    List->Head;

  free(Temp);
  List->ElemSize--;

  return value;
}

size_t size(DblList *List) { return List->ElemSize; }

intptr_t gBind(DblList *List, const size_t Idx) {
  if (Idx >= List->ElemSize) return -1;

  Node *Curr = List->Head;
  for (size_t i = 0; i < Idx; ++i) Curr = Curr->Next;

  return Curr->Data;
}

void clear(DblList *List) {
  if (!List) return;

  Node *curr = List->Head;
  while (curr) {
    Node *next = curr->Next;
    ACCOUNT *acc = (ACCOUNT *)(intptr_t)curr->Data;
    free(curr);
    free(acc);
    curr = next;
  }

  List->Head = NULL;
  List->Tail = NULL;
  List->ElemSize = 0;
}

void insert(DblList *List, const size_t Idx, const intptr_t Value) {
  if (Idx > List->ElemSize) return;

  if (Idx == 0) {
    fPush(List, Value);
    return;
  }

  Node *Nod = (Node *)malloc(sizeof(Node));
  if (!Nod) return;

  Nod->Data = Value;
  Node *Curr = List->Head;

  for (size_t i = 0; i < Idx; ++i) Curr = Curr->Next;

  Nod->Prev = Curr->Prev;
  Nod->Next = Curr;
  if (Curr->Prev) Curr->Prev->Next = Nod;

  Curr->Prev = Nod;
  if (Idx == 0) List->Head = Nod;

  List->ElemSize++;
}

void removeElem(DblList *List, size_t Idx) {
  if (Idx >= List->ElemSize) return;

  if (Idx == 0) {
    fPop(List);
    return;
  }

  if (Idx == List->ElemSize - 1) {
    bPop(List);
    return;
  }

  Node *Curr = List->Head;
  for (size_t i = 0; i < Idx; ++i) Curr = Curr->Next;

  if (Curr->Prev) Curr->Prev->Next = Curr->Next;

  if (Curr->Next) Curr->Next->Prev = Curr->Prev;

  free(Curr);
  List->ElemSize--;
}

DblList *copy(DblList *Src) {
  if (Src == NULL) return NULL;

  DblList *CpList = createList();
  if (!CpList) return NULL;

  Node *Curr = Src->Head;
  while (Curr) {
    bPush(CpList, Curr->Data);
    Curr = Curr->Next;
  }

  return CpList;
}

DblList *merge(DblList *Src, DblList *Dest) {
  Node *Curr = Dest->Head;
  while (Curr) {
    bPush(Src, Curr->Data);
    Curr = Curr->Next;
  }
}

void reverse(DblList *List) {
  Node *Temp = NULL;
  Node *Curr = List->Head;

  while (Curr) {
    Temp = Curr->Prev;
    Curr->Prev = Curr->Next;
    Curr->Next = Temp;
    Curr = Curr->Prev;
  }

  if (Temp) List->Head = Temp->Prev;
}

void fEach(DblList *List, const intptr_t ch) {
  Node *Curr = List->Head;
  if (!List || List->ElemSize == 0) return;

  if (ch == 1) {
    while (Curr) {
      Curr->Data--;
      Curr = Curr->Next;
    }
  } else if (ch == 2) {
    while (Curr) {
      Curr->Data++;
      Curr = Curr->Next;
    }
  } else
    perror("Возникла ошибка!\n");
}

void fList(DblList *List) { free(List); }
