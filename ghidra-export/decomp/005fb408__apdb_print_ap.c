// func _apdb_print_ap @ 005fb408 size=248

void _apdb_print_ap(int param_1)

{
  short *psVar1;
  int iVar2;
  
  if (param_1 != 0) {
    printf("0x%08x\t%-16s\t%-16s\t%-5d\t",*(undefined4 *)(param_1 + 0x10),param_1 + 0xda,
           param_1 + 0x11b,*(undefined4 *)(param_1 + 0x18));
    for (iVar2 = 0; iVar2 < *(int *)(param_1 + 0x160); iVar2 = iVar2 + 1) {
      psVar1 = (short *)(*(int *)(param_1 + 0x164) + iVar2 * 0x38);
      printf("%d.%d ",(int)*psVar1,(int)psVar1[1]);
    }
    putchar(10);
    return;
  }
  if (apdb_err_switch == 0) {
    return;
  }
  printf("[APDB_ERROR]%s()/line %d : input error.\n","_apdb_print_ap",0x1185);
  return;
}

