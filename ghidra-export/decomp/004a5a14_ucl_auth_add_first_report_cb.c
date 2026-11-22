// func ucl_auth_add_first_report_cb @ 004a5a14 size=1

undefined4 ucl_auth_add_first_report_cb(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int in_t9;
  undefined1 auStack_2e0 [100];
  undefined1 auStack_27c [6];
  undefined1 auStack_276 [40];
  undefined1 auStack_24e [50];
  undefined1 auStack_21c [304];
  undefined1 auStack_ec [220];
  
  (**(code **)(in_t9 + 0x2b3d94))(auStack_21c,0,0x205);
  if (param_1 == 0) {
    uVar2 = 0xffffffff;
    if (**(int **)(in_t9 + 0x2b389c) != 0) {
      (**(code **)(in_t9 + 0x2b3ebc))
                (*(int *)(in_t9 + 0x2b37e4) + -0x1648,*(int *)(in_t9 + 0x2b37e4) + -0xb78,0x7d);
    }
  }
  else {
    uVar2 = 0;
    iVar1 = (**(code **)(in_t9 + 0x2b371c))();
    if ((iVar1 == 0) && (*(char *)(param_1 + 0x81) == '\x01')) {
      (**(code **)(in_t9 + 0x2b38cc))(*(undefined4 *)(param_1 + 0x14),auStack_21c);
      (**(code **)(in_t9 + 0x2b3d94))(auStack_2e0,0,0xc4);
      iVar1 = *(int *)(in_t9 + 0x2b370c);
      (**(code **)(in_t9 + 0x2b3cd4))(auStack_2e0,100,iVar1 + 0x15f0,param_1 + 0xa3);
      (**(code **)(in_t9 + 0x2b3ddc))(auStack_27c,param_1 + 0xc,6);
      (**(code **)(in_t9 + 0x2b3ddc))(auStack_276,param_1 + 0x58,0x28);
      (**(code **)(in_t9 + 0x2b3cd4))(auStack_24e,0x32,iVar1 + 0x15f0,auStack_ec);
      ucl_auth_db_add_first_report_station(auStack_2e0);
    }
  }
  return uVar2;
}

