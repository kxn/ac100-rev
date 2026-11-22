// func balance_dis_sta_entry_dump @ 0045a790 size=264

void balance_dis_sta_entry_dump(byte *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  
  if ((param_1 != (byte *)0x0) && (param_2 != (int *)0x0)) {
    printf("%02X:%02X:%02X:%02X:%02X:%02X\t",(uint)*param_1,(uint)param_1[1],(uint)param_1[2],
           (uint)param_1[3],(uint)param_1[4],(uint)param_1[5]);
    printf("%d\t\t",*(undefined4 *)(param_1 + 8));
    printf("%u(%u)\t\t",*(int *)(param_1 + 0xc),*param_2 - *(int *)(param_1 + 0xc));
    printf("wtp:");
    iVar1 = FUN_004081b0(param_1 + 0x10);
    if (iVar1 != 0) {
      iVar2 = *(int *)(iVar1 + 0x10);
      while( true ) {
        printf("%d(%u)  ",*(undefined4 *)(iVar1 + 0xc),*param_2 - iVar2);
        iVar1 = FUN_00408680(iVar1);
        if (iVar1 == 0) break;
        iVar2 = *(int *)(iVar1 + 0x10);
      }
    }
    puts("\r");
    return;
  }
  return;
}

