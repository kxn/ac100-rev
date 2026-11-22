// func wportal_db_ssid_rdt_del @ 004328a4 size=152

undefined4 wportal_db_ssid_rdt_del(uint param_1)

{
  undefined4 uVar1;
  uint uVar2;
  undefined4 uVar3;
  
  uVar3 = 0xffffffff;
  if (-1 < (int)param_1) {
    uVar2 = wserv_profile_get_max_wservice();
    if (param_1 < uVar2) {
      FUN_004082d0(wportal_rdt_mutex,0xffffffff);
      if (*(int *)(wportal_wserv_node + param_1 * 8 + 4) != 0) {
        FUN_00407df0();
      }
      uVar1 = wportal_rdt_mutex;
      uVar3 = 0;
      *(undefined4 *)(wportal_wserv_node + param_1 * 8 + 4) = 0;
      FUN_00407f30(uVar1);
    }
  }
  return uVar3;
}

