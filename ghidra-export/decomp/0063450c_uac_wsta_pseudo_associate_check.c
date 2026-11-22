// func uac_wsta_pseudo_associate_check @ 0063450c size=696

undefined4 uac_wsta_pseudo_associate_check(uint param_1,uint param_2,uint param_3,int param_4)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  char *__format;
  undefined4 uVar4;
  undefined1 auStack_78 [26];
  ushort local_5e;
  
  param_3 = param_3 & 0xff;
  param_2 = param_2 & 0xff;
  memset(auStack_78,0,0x54);
  if (param_4 == 0) {
    return 0x25;
  }
  if (((int)param_1 < 0) || (iVar1 = apmngr_db_get_ap_max(), iVar1 <= (int)param_1)) {
    if (g_wsta_warning == 0) {
      return 0x25;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0x25;
    }
    __format = "<wsta>[warning]%s(): %d  -> invalid ap_id[%d]!\r\n";
    uVar4 = 0xe2;
  }
  else if ((param_2 == 0) || (uVar2 = rdmngr_profile_get_max_rd_per_ap(), uVar2 < param_2)) {
    if (g_wsta_warning == 0) {
      return 0x25;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0x25;
    }
    __format = "<wsta>[warning]%s(): %d  -> invalid rd_id[%d]!\r\n";
    uVar4 = 0xe7;
    param_1 = param_2;
  }
  else if ((param_3 == 0) || (uVar2 = rdmngr_profile_get_max_wlan_per_rd(), uVar2 < param_3)) {
    if (g_wsta_warning == 0) {
      return 0x25;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0x25;
    }
    __format = "<wsta>[warning]%s(): %d  -> invalid wlan_id[%d]!\r\n";
    uVar4 = 0xec;
    param_1 = param_3;
  }
  else {
    uVar2 = rdmngr_db_generate_rd_id(param_1,param_2);
    iVar1 = rdmngr_db_rd_entry_get(uVar2,auStack_78);
    if (iVar1 != 0) {
      if (g_wsta_warning == 0) {
        return 0x25;
      }
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        return 0x25;
      }
      printf("<wsta>[warning]%s(): %d  -> rdmngr_db_rd_entry_get() fail, rd_id=%d\r\n",
             "uac_wsta_pseudo_associate_check",0xf4,uVar2);
      return 0x25;
    }
    iVar1 = wsta_db_get_rd_sta_num(param_1,param_2);
    if (iVar1 != -1) {
      if (iVar1 < (int)(uint)local_5e) {
        uVar4 = _uac_wsta_do_check(param_1,param_2,param_3,param_4,1);
        return uVar4;
      }
      if (g_wsta_warning == 0) {
        return 3;
      }
      iVar3 = is_target_debug_ap();
      if (iVar3 == 0) {
        return 3;
      }
      printf("<wsta>[warning]%s(): %d  -> assco sta reach max on ap[%d] rd[%d], cur_sta_num[%d]\r\n"
             ,"uac_wsta_pseudo_associate_check",0xff,param_1,uVar2,iVar1);
      return 3;
    }
    if (g_wsta_warning == 0) {
      return 0x25;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0x25;
    }
    __format = "<wsta>[warning]%s(): %d  -> wsta_db_get_rd_sta_num() fail, rd_id=%d\r\n";
    uVar4 = 0xfa;
    param_1 = uVar2;
  }
  printf(__format,"uac_wsta_pseudo_associate_check",uVar4,param_1);
  return 0x25;
}

