// func cw_frag_mngr_dump @ 00596020 size=224

undefined4 cw_frag_mngr_dump(undefined4 *param_1)

{
  undefined4 uVar1;
  
  if (param_1 == (undefined4 *)0x0) {
    printf("[ASSERT]%32s():%4d assert(%s) failed\n","cw_frag_mngr_dump",0x343,"NULL != session");
    uVar1 = 0xffffffff;
  }
  else {
    puts("******************frag manager configuration**********************\r");
    printf("current frag ID:                %d\r\n",param_1[1]);
    uVar1 = FUN_00407fe0(param_1 + 5);
    printf("current frag packet number:     %d\r\n",uVar1);
    printf("current frag packet len:        %d\r\n",param_1[2]);
    if (param_1[4] != 0) {
      printf("total frag packet len needed:   %d\r\n",param_1[3]);
    }
    printf("mtu value:                      %d\r\n",*param_1);
    printf("pointer of timer:               %p\r\n",param_1[9]);
    puts("******************************************************************\r");
    uVar1 = 0;
  }
  return uVar1;
}

