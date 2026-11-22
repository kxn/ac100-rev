// func uac_wstation_implicit_station_del @ 00633e30 size=1

undefined4 uac_wstation_implicit_station_del(uint param_1)

{
  int iVar1;
  int iVar2;
  void *__src;
  char acStack_b0 [124];
  byte bStack_34;
  byte bStack_33;
  byte bStack_32;
  byte bStack_31;
  byte bStack_30;
  byte bStack_2f;
  
  acStack_b0[0] = '\0';
  acStack_b0[1] = '\0';
  acStack_b0[2] = '\0';
  acStack_b0[3] = '\0';
  acStack_b0[4] = '\0';
  acStack_b0[5] = '\0';
  acStack_b0[6] = '\0';
  acStack_b0[7] = '\0';
  acStack_b0[8] = '\0';
  acStack_b0[9] = '\0';
  acStack_b0[10] = '\0';
  acStack_b0[0xb] = '\0';
  acStack_b0[0xc] = '\0';
  acStack_b0[0xd] = '\0';
  acStack_b0[0xe] = '\0';
  acStack_b0[0xf] = '\0';
  acStack_b0[0x10] = '\0';
  acStack_b0[0x11] = '\0';
  acStack_b0[0x12] = '\0';
  acStack_b0[0x13] = '\0';
  if (((int)param_1 < 0) || (l_wsta_profile <= param_1)) {
    if ((g_wsta_warning != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("<wsta>[warning]%s(): %d  -> invalid wsta_id[%d]!\r\n","wsta_db_free_sta",0xaa2,param_1
            );
      return 0xffffffff;
    }
  }
  else {
    FUN_004082d0(DAT_007cc6bc,0xffffffff);
    __src = (void *)(DAT_007cc6c8 + param_1 * 0x80);
    if (*(int *)((int)__src + 0x18) == 0) {
      iVar1 = -1;
      if ((g_wsta_warning != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
        printf("<wsta>[warning]%s(): %d  -> wsta_id[%d] is not used!\r\n","wsta_db_free_sta",0xaa9,
               param_1);
      }
    }
    else {
      memcpy(acStack_b0 + 0x14,__src,0x80);
      iVar1 = 0;
      _wsta_free_entry_new(__src);
    }
    FUN_00407f30(DAT_007cc6bc);
    if (iVar1 == 0) {
      _uac_wsta_implicit_del_cb(acStack_b0 + 0x14,0);
      _uac_wstation_do_event(1,acStack_b0 + 0x14);
      snprintf(acStack_b0,0x14,"%02X-%02X-%02X-%02X-%02X-%02X",(uint)bStack_34,(uint)bStack_33,
               (uint)bStack_32,(uint)bStack_31,(uint)bStack_30,(uint)bStack_2f);
      loggerk_reg(0x5b,0x3a9b,1,acStack_b0,0);
      return 0;
    }
  }
  return 0xffffffff;
}

