// func cw_ac_thread_detail_dump @ 0058ce58 size=1

void cw_ac_thread_detail_dump(uint param_1)

{
  undefined4 uVar1;
  int iVar2;
  char *pcVar3;
  
  if (param_1 < *(uint *)(ac + 0x18)) {
    printf("\n----------------thread %d\'s ap information-------------------\n",param_1);
    uVar1 = FUN_00407fe0(*(int *)(ac + 0x1c) + param_1 * 0xa0 + 0x4c);
    printf("total num:%d\n",uVar1);
    for (iVar2 = FUN_004081b0(*(int *)(ac + 0x1c) + param_1 * 0xa0 + 0x4c); iVar2 != 0;
        iVar2 = FUN_00408680(iVar2)) {
      capwap_ac_session_dump(iVar2);
    }
    pcVar3 = "---------------------------end-------------------------------";
  }
  else {
    pcVar3 = "ac thread\'s index is wrong";
  }
  (*(code *)PTR_puts_00758f90)(pcVar3);
  return;
}

