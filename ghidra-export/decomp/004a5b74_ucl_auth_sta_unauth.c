// func ucl_auth_sta_unauth @ 004a5b74 size=232

undefined4 ucl_auth_sta_unauth(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int in_t9;
  undefined4 local_18;
  undefined4 local_14;
  
  if (param_1 == 0) {
    uVar2 = 0xffffffff;
    if (**(int **)(in_t9 + 0x2b373c) != 0) {
      (**(code **)(in_t9 + 0x2b3d5c))
                (*(int *)(in_t9 + 0x2b3684) + -0x13a0,*(int *)(in_t9 + 0x2b3684) + -0x9a8,0x493);
    }
  }
  else {
    uVar2 = 0;
    iVar1 = ucl_auth_db_is_station_report_switch_enable();
    if (((iVar1 == 1) && (iVar1 = (**(code **)(in_t9 + 0x2b35bc))(), iVar1 == 0)) &&
       (*(char *)(param_1 + 0x81) == '\x01')) {
      (**(code **)(in_t9 + 0x2b3c7c))(&local_18,param_1 + 0xc,6);
      ucl_auth_db_add_offline_station(local_18,local_14);
    }
  }
  return uVar2;
}

