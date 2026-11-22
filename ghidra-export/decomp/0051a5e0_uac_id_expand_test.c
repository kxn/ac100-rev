// func uac_id_expand_test @ 0051a5e0 size=440

void uac_id_expand_test(undefined4 param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = uac_id_new();
  if (iVar1 != 0) {
    iVar3 = 0;
    puts("Allocate start...");
    while (iVar3 < param_2) {
      iVar2 = uac_id_alloc(iVar1);
      if (iVar2 == -1) {
        iVar2 = iVar3 + 1;
        iVar3 = iVar3 + 1;
        printf("---ID allocator expands when allocate the %dth ID---\n",iVar2);
        uac_id_dump(iVar1);
        uac_id_expand(iVar1,*(undefined4 *)(iVar1 + 0x10));
        uac_id_alloc(iVar1);
      }
      else {
        iVar3 = iVar3 + 1;
      }
    }
    puts("---ID allocator after allocate all IDs---");
    uac_id_dump(iVar1);
    puts("Free all include duplicated IDs and not ever allocated IDs...");
    for (iVar3 = 0; iVar3 < param_2; iVar3 = iVar3 + 1) {
      uac_id_free(iVar1,iVar3);
      uac_id_free(iVar1,iVar3);
    }
    uac_id_dump();
    uac_id_destroy(iVar1);
    return;
  }
  return;
}

