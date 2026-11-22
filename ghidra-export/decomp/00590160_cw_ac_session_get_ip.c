// func cw_ac_session_get_ip @ 00590160 size=128

undefined4 cw_ac_session_get_ip(int param_1,void *param_2)

{
  undefined4 uVar1;
  undefined *puVar2;
  
  if (param_1 == 0) {
    uVar1 = 0x194;
    puVar2 = &DAT_006de7a4;
  }
  else {
    if (param_2 != (void *)0x0) {
      memcpy(param_2,(void *)(param_1 + 0x2c),0x14);
      return 0;
    }
    uVar1 = 0x195;
    puVar2 = &DAT_00677c24;
  }
  printf("[ASSERT]%32s():%4d assert(%s) failed\n","cw_ac_session_get_ip",uVar1,puVar2);
  return 0xffffffff;
}

