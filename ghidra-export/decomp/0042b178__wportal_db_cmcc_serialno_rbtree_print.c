// func _wportal_db_cmcc_serialno_rbtree_print @ 0042b178 size=136

undefined4 _wportal_db_cmcc_serialno_rbtree_print(undefined4 param_1,byte *param_2)

{
  byte *pbVar1;
  int iVar2;
  
  if (param_2 != (byte *)0x0) {
    iVar2 = 0;
    printf("   serialno: %d, reqid: %d, challenge: ",(uint)*(ushort *)(param_2 + 0x10),
           (uint)*(ushort *)(param_2 + 0x12));
    pbVar1 = param_2;
    do {
      iVar2 = iVar2 + 1;
      printf("%02x ",(uint)*pbVar1);
      pbVar1 = param_2 + iVar2;
    } while (iVar2 != 0x10);
    putchar(10);
  }
  return 0;
}

