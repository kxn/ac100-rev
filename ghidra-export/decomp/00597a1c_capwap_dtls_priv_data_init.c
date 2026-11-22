// func capwap_dtls_priv_data_init @ 00597a1c size=148

void capwap_dtls_priv_data_init
               (undefined4 *param_1,undefined4 param_2,undefined4 param_3,void *param_4,
               void *param_5,undefined4 param_6)

{
  undefined4 uVar1;
  
  *param_1 = param_3;
  memcpy(param_1 + 1,param_4,0x14);
  *(undefined2 *)(param_1 + 6) = *(undefined2 *)((int)param_4 + 0x14);
  uVar1 = *(undefined4 *)((int)param_4 + 0x18);
  param_1[0x10] = param_2;
  param_1[7] = uVar1;
  param_1[0xf] = param_6;
  memcpy(param_1 + 8,param_5,0x14);
  *(undefined2 *)(param_1 + 0xd) = *(undefined2 *)((int)param_5 + 0x14);
  param_1[0xe] = *(undefined4 *)((int)param_5 + 0x18);
  return;
}

