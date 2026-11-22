// func _wportal_common_wq_item_traverse_func @ 0042b768 size=344

undefined4 _wportal_common_wq_item_traverse_func(int *param_1,int param_2)

{
  undefined1 auStack_54 [68];
  
  memset(auStack_54,0,0x40);
  *param_1 = *param_1 + 1;
  FUN_00408190(0x1000000,*(undefined4 *)(param_2 + 0x20),0,0,0,auStack_54,0x40,"---");
  printf("\n---------%d----------\n",*param_1);
  printf("entry->userIp is %s\n",auStack_54);
  printf("entry->reqId is %u\n",(uint)*(ushort *)(param_2 + 0x24));
  printf("entry->serialNo is %u\n",(uint)*(ushort *)(param_2 + 0x26));
  printf("entry->mac is %02X-%02X-%02X-%02X-%02X-%02X\n",(uint)*(byte *)(param_2 + 0x28),
         (uint)*(byte *)(param_2 + 0x29),(uint)*(byte *)(param_2 + 0x2a),
         (uint)*(byte *)(param_2 + 0x2b),(uint)*(byte *)(param_2 + 0x2c),
         (uint)*(byte *)(param_2 + 0x2d));
  printf("entry->papChap is %u\n",(uint)*(byte *)(param_2 + 0x2e));
  FUN_00407e70();
  printf("entry->auth_time passed %lld second\n");
  putchar(10);
  return 0;
}

