// func capwap_network_dump @ 00595a68 size=204

undefined4 capwap_network_dump(undefined4 *param_1)

{
  undefined4 uVar1;
  undefined1 auStack_50 [68];
  
  if (param_1 == (undefined4 *)0x0) {
    printf("[ASSERT]%32s():%4d assert(%s) failed\n","capwap_network_dump",0x11f,"NULL != session");
    uVar1 = 0xffffffff;
  }
  else {
    puts("*********************network configuration************************\r");
    memset(auStack_50,0,0x40);
    FUN_00408190(*param_1,param_1[1],param_1[2],param_1[3],param_1[4],auStack_50,0x40,"---");
    printf("ip:%s     port:%d \r\n",auStack_50,(uint)*(ushort *)(param_1 + 5));
    puts("******************************************************************\r");
    uVar1 = 0;
  }
  return uVar1;
}

