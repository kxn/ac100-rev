// func arp_defend_print_ap_entry @ 0047eddc size=308

void arp_defend_print_ap_entry(undefined4 *param_1)

{
  uint uVar1;
  int iVar2;
  
  if ((param_1 != (undefined4 *)0x0) && (arp_defend_debug_switch != 0)) {
    iVar2 = 0;
    puts("#####################################################################");
    uVar1 = 0;
    printf("ap_id\t\t\t= %d\n",*param_1);
    printf("status\t\t\t= %d\n",(uint)*(byte *)(param_1 + 1));
    printf("bind_num\t\t= %d\n",param_1[2]);
    puts("++++++++++bind_arp_list++++++++++");
    while (uVar1 < DAT_007670f0) {
      if (*(int *)(param_1[3] + uVar1 * 4) == -1) {
        uVar1 = uVar1 + 1;
      }
      else {
        iVar2 = iVar2 + 1;
        printf("%d:%d,",uVar1);
        uVar1 = uVar1 + 1;
      }
    }
    printf("\nbind_count in list:%d",iVar2);
    puts("\n#####################################################################");
    return;
  }
  return;
}

