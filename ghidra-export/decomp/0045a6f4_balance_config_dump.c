// func balance_config_dump @ 0045a6f4 size=152

undefined4 balance_config_dump(undefined4 *param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0xffffffff;
  if (param_1 != (undefined4 *)0x0) {
    puts("balance config:\r");
    printf("\tstate:%d\r\n",*param_1);
    printf("\tmode:%d\r\n",param_1[1]);
    printf("\tusers threshold:%d\r\n",param_1[2]);
    printf("\tdiffer threshold:%d\r\n",param_1[3]);
    printf("\tmax failures:%d\r\n",param_1[4]);
    printf("\trssi threshold:%d\r\n",param_1[5]);
    uVar1 = 0;
  }
  return uVar1;
}

