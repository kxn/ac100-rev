// func uac_id_test @ 0051a034 size=1072

void uac_id_test(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  
  iVar1 = uac_id_new();
  if (iVar1 != 0) {
    puts("Allocate 1/2...");
    for (iVar4 = 0; iVar4 < param_1; iVar4 = iVar4 + 2) {
      uac_id_alloc(iVar1);
    }
    uac_id_dump();
    puts("Free all include duplicated IDs and not ever allocated IDs...");
    for (iVar4 = 0; iVar4 < param_1; iVar4 = iVar4 + 1) {
      uac_id_free(iVar1,iVar4);
      uac_id_free(iVar1,iVar4);
    }
    iVar5 = param_1 << 1;
    uac_id_dump();
    puts("Allocate 2*idmax IDs...");
    for (iVar4 = 0; iVar4 < iVar5; iVar4 = iVar4 + 1) {
      uac_id_alloc(iVar1);
    }
    uac_id_dump();
    puts("Free all include duplicated IDs and not ever allocated IDs...");
    for (iVar4 = 0; iVar4 < param_1; iVar4 = iVar4 + 1) {
      uac_id_free(iVar1,iVar4);
      uac_id_free(iVar1,iVar4);
    }
    uac_id_dump();
    puts("Allocate 2, free 1...");
    for (iVar4 = 0; iVar4 < iVar5; iVar4 = iVar4 + 1) {
      uVar2 = uac_id_alloc(iVar1);
      uVar3 = uac_id_alloc(iVar1);
      printf("%d, ",uVar3);
      uac_id_free(iVar1,uVar2);
    }
    putchar(10);
    uac_id_dump(iVar1);
    puts("Cost test , cost=0");
    uVar2 = uac_id_new(param_1);
    uac_id_fix(uVar2);
    uac_id_dump(uVar2);
    puts("Cost test , cost=ALL");
    uVar2 = uac_id_new(param_1);
    for (iVar1 = 0; iVar1 < iVar5; iVar1 = iVar1 + 1) {
      uac_id_cost(uVar2,iVar1);
    }
    uac_id_dump();
    uac_id_fix(uVar2);
    uac_id_dump(uVar2);
    puts("Cost test , cost=1/2");
    uVar2 = uac_id_new(param_1);
    for (iVar1 = 0; iVar1 < param_1; iVar1 = iVar1 + 2) {
      uac_id_cost(uVar2,iVar1);
    }
    uac_id_dump();
    uac_id_fix(uVar2);
    uac_id_dump(uVar2);
    printf("now allocate ");
    for (iVar1 = 0; iVar1 < param_1; iVar1 = iVar1 + 1) {
      uVar3 = uac_id_alloc(uVar2);
      printf("%d, ",uVar3);
    }
    uac_id_dump();
    uac_id_destroy(uVar2);
    return;
  }
  return;
}

