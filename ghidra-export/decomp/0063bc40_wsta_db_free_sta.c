// func wsta_db_free_sta @ 0063bc40 size=472

undefined4 wsta_db_free_sta(uint param_1,code *param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  void *__src;
  char local_b0 [124];
  byte local_34;
  byte local_33;
  byte local_32;
  byte local_31;
  byte local_30;
  byte local_2f;
  
  local_b0[0] = '\0';
  local_b0[1] = '\0';
  local_b0[2] = '\0';
  local_b0[3] = '\0';
  local_b0[4] = '\0';
  local_b0[5] = '\0';
  local_b0[6] = '\0';
  local_b0[7] = '\0';
  local_b0[8] = '\0';
  local_b0[9] = '\0';
  local_b0[10] = '\0';
  local_b0[0xb] = '\0';
  local_b0[0xc] = '\0';
  local_b0[0xd] = '\0';
  local_b0[0xe] = '\0';
  local_b0[0xf] = '\0';
  local_b0[0x10] = '\0';
  local_b0[0x11] = '\0';
  local_b0[0x12] = '\0';
  local_b0[0x13] = '\0';
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
      memcpy(local_b0 + 0x14,__src,0x80);
      iVar1 = 0;
      _wsta_free_entry_new(__src);
    }
    FUN_00407f30(DAT_007cc6bc);
    if (iVar1 == 0) {
      if (param_2 != (code *)0x0) {
        (*param_2)(local_b0 + 0x14,param_3);
      }
      _uac_wstation_do_event(1,local_b0 + 0x14);
      snprintf(local_b0,0x14,"%02X-%02X-%02X-%02X-%02X-%02X",(uint)local_34,(uint)local_33,
               (uint)local_32,(uint)local_31,(uint)local_30,(uint)local_2f);
      loggerk_reg(0x5b,0x3a9b,1,local_b0,0);
      return 0;
    }
  }
  return 0xffffffff;
}

