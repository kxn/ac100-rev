// func apmngr_db_entry_init @ 0053a310 size=412

void apmngr_db_entry_init(void *param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  undefined4 uVar1;
  int iVar2;
  
  if (param_1 != (void *)0x0) {
    memset(param_1,0,0x2d8);
    *(undefined4 *)((int)param_1 + 0x1c) = 1;
    if ((param_4 != 7) || (uVar1 = 0, allow_sensor_join_direct != 0)) {
      uVar1 = apmngr_auto_firm_get();
    }
    *(undefined4 *)((int)param_1 + 0x3c) = uVar1;
    *(int *)((int)param_1 + 0x14) = param_4;
    *(undefined4 *)((int)param_1 + 0x2c) = 0xffffffff;
    *(undefined4 *)((int)param_1 + 0x30) = 0xffffffff;
    *(undefined1 *)((int)param_1 + 0x2b0) = 0;
    iVar2 = apdb_support_new_ap_trunk_by_id(param_3,param_2);
    if (iVar2 == 0) {
      *(undefined1 *)((int)param_1 + 0x2b1) = 0xff;
    }
    else {
      *(undefined1 *)((int)param_1 + 0x2b1) = 0;
    }
    *(undefined1 *)((int)param_1 + 0x2b2) = 0;
    *(undefined1 *)((int)param_1 + 0x2b3) = 1;
    strncpy((char *)((int)param_1 + 0x2b4),"0",0x13);
    *(undefined1 *)((int)param_1 + 0x130) = 0;
    *(undefined1 *)((int)param_1 + 0x2d1) = 0xff;
    *(undefined1 *)((int)param_1 + 0xe8) = 0x1e;
    *(undefined2 *)((int)param_1 + 0xea) = 300;
    *(undefined4 *)((int)param_1 + 0xec) = 0xe10;
    *(undefined4 *)((int)param_1 + 0xf0) = apmngr_dft_offline_selfmanage;
    *(undefined4 *)((int)param_1 + 0x1b8) = 1;
    *(undefined1 *)((int)param_1 + 0x1bd) = 7;
    *(undefined1 *)((int)param_1 + 0x1c1) = 7;
    iVar2 = apdb_support_ap_trunk_by_id(param_3,param_2);
    if (iVar2 == 0) {
      *(undefined4 *)((int)param_1 + 0x124) = 0xffffffff;
    }
    else {
      *(undefined4 *)((int)param_1 + 0x124) = 0;
    }
    strncpy((char *)((int)param_1 + 0xf4),"admin",0x1f);
    strncpy((char *)((int)param_1 + 0x114),"xxxxxx",0xf);
    *(undefined1 *)((int)param_1 + 0x131) = 0xff;
    strncpy((char *)((int)param_1 + 0x132),"admin",0x40);
    return;
  }
  return;
}

