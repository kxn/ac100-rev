// func wportal_db_ssid_rdt_get @ 00432a08 size=180

undefined4 wportal_db_ssid_rdt_get(uint param_1,void *param_2)

{
  uint uVar1;
  void *__src;
  undefined4 uVar2;
  
  uVar2 = 0xffffffff;
  if (((param_2 != (void *)0x0) && (-1 < (int)param_1)) &&
     (uVar1 = wserv_profile_get_max_wservice(), param_1 < uVar1)) {
    FUN_004082d0(wportal_rdt_mutex,0xffffffff);
    __src = *(void **)(wportal_wserv_node + param_1 * 8 + 4);
    if (__src == (void *)0x0) {
      FUN_00407f30(wportal_rdt_mutex);
    }
    else {
      memcpy(param_2,__src,0x16c);
      uVar2 = 0;
      FUN_00407f30(wportal_rdt_mutex);
    }
  }
  return uVar2;
}

